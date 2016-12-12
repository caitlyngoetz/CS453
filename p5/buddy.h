#ifndef __BUDDY_H
#define __BUDDY_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_KVAL 35 //32GB
#define DEFAULT_BLOCK_SIZE 536870912 //512MB or 2^29

struct buddy_header {
	int unsigned kval;
	int unsigned tag;
	void * next;
	void * prev;
};

void buddy_init(size_t init_val);
void buddy_free(void *ptr);
void printBuddyLists(void);
void *buddy_malloc(size_t size);
void *buddy_realloc(void *ptr, size_t new_size);
void *buddy_calloc(size_t items, size_t item_size);

#endif /* __BUDDY_H */
