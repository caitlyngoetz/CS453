#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct list * createList(int (*equals)(const void *,const void *),
			 char * (*toString)(const void *),
			 void (*freeObject)(void *))
{
	struct list *list;
	list = (struct list *) malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->equals = equals;
	list->toString = toString;
	list->freeObject = freeObject;
	return list;
}

void freeList(struct list *list)
{
	if(list == NULL) return;
	struct node *temp = list->head;
	while(temp != NULL){
		list->head = list->head->next;
		temp->next = temp->prev = NULL;
		freeNode(temp, list->freeObject);
		temp = list->head;
	}
	free(list);
}
int getSize(const struct list *list)
{
	if(list == NULL) return 0;
	return list->size;
} 
int isEmpty(const struct list *list)
{
	if(list == NULL) return 1;
	return list->size == 0;
}

void addAtFront(struct list *list, struct node *node)
{
	if (list == NULL) return;
	if (node == NULL) return;
	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}
void addAtRear(struct list *list, struct node *node)
{
	if(list == NULL) return;
	if(node == NULL) return;
	list->size++;
	node->next = NULL;
	node->prev = list->tail;
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
	}else{
		list->tail->next = node;
		list->tail = node;
	}
}
struct node* removeFront(struct list *list)
{
	if(list == NULL) return NULL;
	if(list->size == 0) return NULL;	

	struct node *temp = list-> head;

	if(list->size == 1){
		list->head=list->tail=NULL;
	}else{
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	temp->next = NULL;
	temp->prev = NULL;
	list->size--;
	return temp;
}
struct node* removeRear(struct list *list)
{
	if(list == NULL) return NULL;
	if(list->size == 0) return NULL;
	
	struct node *temp = list->tail;

	if(list->size == 1){
		list->head=list->tail=NULL;
	}else{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	temp->next = NULL;
	temp->prev = NULL;
	list->size--;
	return temp;
}

struct node* removeNode(struct list *list, struct node *node)
{
	if(list == NULL) return NULL;
	if(list->size == 0) return NULL;
	if(node == NULL) return NULL;

	if(node == list->head){ 
		node = removeFront(list);
	}else if(node == list->tail){
		node = removeRear(list);
	}else{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = node->prev = NULL;
		list->size--;
	}
	node->next = NULL;
	node->prev = NULL;
	return node;
	
}

struct node* search(const struct list *list, const void *obj)
{
	if(list == NULL) return NULL;
	if(obj == NULL) return NULL;

	struct node *curr = list->head;
	while(curr != NULL){
		if((list->equals)(curr->obj, obj)){
			return curr;
		}	
		curr = curr->next;
	}
	return NULL;
}

void reverseList(struct list *list)
{
	if(list == NULL) return;

	struct node *temp = list->head;
	struct node *curr = list->head;
	while(curr != NULL){
		curr = curr->next;
		list->head->next = list->head->prev;
		list->head->prev = curr;
		list->head = curr;
	}
	list->head = list->tail;
	list->tail = temp;
}

void printList(const struct list *list)
{
	if (!list) return; //list was null!!
	int count = 0;
	char *output;
	struct node *temp = list->head;
	while (temp) {
		output = list->toString(temp->obj);
		printf(" %s -->",output);
		free(output);
		temp = temp->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
	printf(" NULL \n");
}
