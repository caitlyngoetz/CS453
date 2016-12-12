#include "buddy.h"

static int initialized = 0; 
static int init_kval = 0;
static long long unsigned offset = 0;
static struct buddy_header freeLists[MAX_KVAL + 1];

static void addBlockToFront(int, struct buddy_header *);
static struct buddy_header * reduceBlock(int, int);
static struct buddy_header * removeFirstBlock(int);
static void printBlock(struct buddy_header *);

static void addBlockToFront(int kval, struct buddy_header * block)
{
	if(freeLists[kval].next == NULL) {
		freeLists[kval].next = (void *) block;
		freeLists[kval].prev = (void *) block;
		block->next = (void *) &freeLists[kval];
		block->prev = (void *) &freeLists[kval];
	} else {
		struct buddy_header * first_block = (struct buddy_header *) freeLists[kval].next;
		first_block->prev = &block;
		freeLists[kval].next = &block;
		block->next = &first_block;
		block->prev = &freeLists[kval];
	}
}

void buddy_init(size_t init_val)
{
	if(!initialized) {
		if(init_val == 0) { //zero = default
			init_val = DEFAULT_BLOCK_SIZE;
		}
		
		if( ((init_val & (~init_val + 1)) != init_val) ) {
			init_val = 1L << (64 - __builtin_clzl(init_val));
		}
		init_kval = 63 - __builtin_clzl(init_val);

		if(init_kval > MAX_KVAL) {
			init_kval = MAX_KVAL;
			init_val = 1L << (MAX_KVAL);
		}
		
		void * block = sbrk(init_val);
		if(block == (void *) -1) { // not enough memory 
			//print error
		}

		struct buddy_header *buddy_block = (struct buddy_header *) block;
		buddy_block->kval = init_kval;
		buddy_block->tag  = 0; 

		for(int i = 0; i < sizeof(freeLists) / sizeof(struct buddy_header); i++) {
			freeLists[i].next = NULL;
			freeLists[i].kval = 0;
			freeLists[i].tag = 2; 
			freeLists[i].prev = NULL;
		}
		
		initialized = 1;
		offset = (long long unsigned) block;
		buddy_free(block + (2 * sizeof(int unsigned)));
	}
}


void buddy_free(void *ptr)
{
	if(!initialized) {
		buddy_init(0); 
	}
	void * block_start = ptr - (2 * sizeof(int unsigned));
	struct buddy_header *buddy_block = (struct buddy_header *) block_start;
	printf("welcome to the free, let's see what block we're working with\n");
	printf("this blocks kval is : %u\n", buddy_block->kval);
	printf("has this block been freed? %u\n", buddy_block->tag);
	if(buddy_block->tag) {
		//this block has been freed already
	} else {
		printf("current offset : %llu\n", offset);

		int k = buddy_block->kval;
		if(k == init_kval) {
			buddy_block->tag = 1;
			addBlockToFront(k, buddy_block);
		} else {
			//TODO JOIN BUDDY
			buddy_block->tag = 1;
			addBlockToFront(k, buddy_block);
		}
	}
	printBuddyLists();
}

static struct buddy_header * reduceBlock(int kval, int list_index) {
	if(freeLists[list_index].next == NULL) return NULL; //....

	printf("reducing the first block in the %d list\n", list_index);
	
	struct buddy_header * block = removeFirstBlock(list_index);
	if(block->kval == kval) {
		return block;
	} else if (block->kval < kval) {
		return NULL;
	} else {
		long long unsigned block_position = (long long unsigned)block - offset;
		printf("finding halfway point of this free block");
		struct buddy_header * buddy_block = (struct buddy_header *)(void *) ((block_position+ (1L << (list_index -1)) + offset));
		buddy_block->kval = list_index - 1;
		buddy_block->tag = 1; 
		addBlockToFront(list_index - 1, buddy_block);
		printBuddyLists();

		block->kval--;
		addBlockToFront(block->kval, block);
		printBuddyLists();
		printf("address of original block, %llu\n", block_position);
		printf("address of buddy block, %llu\n", block_position + (1 << block->kval));
		return reduceBlock(kval, list_index - 1);
	}
}

static struct buddy_header * removeFirstBlock(int kval)
{
	if(freeLists[kval].next != NULL) {
		printBuddyLists();
		struct buddy_header * block = (struct buddy_header *) freeLists[kval].next;

		freeLists[kval].next = block->next;
		struct buddy_header * next_block = (struct buddy_header *) block->next;
		if(next_block) {
			next_block->prev = &freeLists[kval];
		}

		if(freeLists[kval].next == &freeLists[kval]) {
			freeLists[kval].next = NULL;
			freeLists[kval].prev = NULL;
		}
		printBuddyLists();
		return block;
	} else {
		for(int i = kval; i <= init_kval; i++) {
			if(freeLists[i].next != NULL) {

				printf("we've found a larger block at (%d)\n", i);
				struct buddy_header * block = reduceBlock(kval, i);
				return block;
			}
		}
	}
	printf("we're out of memory!\n");
	return NULL;
}

void *buddy_calloc(size_t items, size_t item_size)
{
	if(!initialized) {
		buddy_init(0); 
	}

}

void *buddy_malloc(size_t size)
{
	if(!initialized) {
		buddy_init(0); 
	}
	printf("entering buddy_malloc\n");

	if(size == 0) {
		printf("zero size...really?");
	}
	
	size_t min_size = size + (2 * sizeof(int unsigned)); 
	if( ((min_size & (~min_size + 1)) != min_size) ) {
		min_size = 1L <<(64 - __builtin_clzl(min_size));
	}
	int request_kval = 63 - __builtin_clzl(min_size);

	if(request_kval > init_kval) {
		//TODO report error
		return NULL;
	}

	printf("going to get a block of size (%d)\n", request_kval);
	struct buddy_header * request_block = removeFirstBlock(request_kval);

	request_block->tag = 0; 
	printf("returning the following block [tag=%d,kval=%d,addr=%p]\n", request_block->tag, request_block->kval, request_block);
	return ((void *)request_block) + (2 * sizeof(int unsigned));
}

void *buddy_realloc(void *ptr, size_t new_size)
{
	if(!initialized) {
		buddy_init(0); 
	}

}

void printBuddyLists(void)
{
	int freeCount = 0;
	printf("\n");
	for(int i = 0; i <= init_kval; i++) {
		printf("List %d: head = %p --> ", i, &freeLists[i]);
		if(freeLists[i].next) {
			struct buddy_header *node = (struct buddy_header *)freeLists[i].next;
			while(node && node->tag != 2) {
				freeCount++;
				printf("[tag=%d,kval=%d,addr=%p] --> ", node->tag, node->kval, node);
				node = node->next;
			}
		}
		printf("<null>\n");
	}
}

static void printBlock(struct buddy_header * block)
{
	printf("[tag=%d, kval =%d, addr=%p]\n", block->tag, block->kval, block);
}
