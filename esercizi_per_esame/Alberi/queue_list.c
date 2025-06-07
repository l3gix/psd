#include "item.h"
#include "queue.h"
#include "list.h"
#include <stdlib.h>

struct queue {
	List items;

};

Queue newQueue(){
	Queue q=malloc(sizeof(struct queue));
	if(q==NULL){
		return NULL;
	}
	q->items=newList();
	return q;
}

int isEmptyQueue(Queue q){
	return isEmpty(q->items);
}

int enqueue(Queue q, Item e){
	return addListTail(q->items,e);
}

Item dequeue(Queue q){
	return removeHead(q->items);
}

void printQueue(Queue q){
	printList(q->items);
}

