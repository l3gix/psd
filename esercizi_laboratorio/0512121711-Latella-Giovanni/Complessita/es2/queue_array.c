#include "item.h"
#include "queue.h"
#include <stdlib.h>
#define MAXQUEUE 50

struct queue{
	Item items[MAXQUEUE];
	int head;
	int tail;
};

Queue newQueue(){
	Queue q=malloc(sizeof(struct queue));
	if(q==NULL){
		return NULL;
	}
	q->head=0;
	q->tail=0;
	return q;
}

int isEmptyQueue(Queue q){
	return q->head==q->tail;
}

int enqueue(Queue q, Item e){
	if((q->tail+1)%MAXQUEUE==q->head){
		return 0;
	}
	q->items[q->tail]=e;
	q->tail=(q->tail+1)%MAXQUEUE;
	return 1;
}

Item dequeue(Queue q){
	Item temp;
	if(isEmptyQueue(q)){
		return NULL;
	}
	temp=q->items[q->head];
	q->head=(q->head+1)%MAXQUEUE;
	return temp;
}

void printQueue(Queue q){
	for(int i=q->head;i!=q->tail;i=(i+1)%MAXQUEUE){
		outputItem(q->items[i]);
	}
}

