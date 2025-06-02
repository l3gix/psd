#include "item.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>

struct queue{
    Stack memoria;
    Stack operazioni;
};

Queue newQueue(){
    Queue q=malloc(sizeof(struct queue));
    if(q==NULL){
        return NULL;
    }
    q->memoria=newStack();
    q->operazioni=newStack();
    return q;
}

int isEmptyQueue(Queue q){
    return (isEmptyStack(q->memoria));
}

int enqueue(Queue q,Item i){
    return push(q->memoria,i);

}

int dequeue(Queue q){
    Item temp;
    if(isEmptyQueue(q)){
        return 0;
    }
    while(!isEmptyStack(q->memoria)){
        temp=top(q->memoria);
        push(q->operazioni,temp);
        pop(q->memoria);
    }
    pop(q->operazioni);
    
    while(!isEmptyStack(q->operazioni)){
        temp=top(q->operazioni);
        push(q->memoria,temp);
        pop(q->operazioni);
    }
    return 1;

}

void printQueue(Queue q){
    Item temp;
    while(!isEmptyStack(q->memoria)){
        temp=top(q->memoria);
        pop(q->memoria);
        push(q->operazioni,temp);
    }
    while(!isEmptyStack(q->operazioni)){
        temp=top(q->operazioni);
        outputItem(temp);
        push(q->memoria,temp);
        pop(q->operazioni);
    }
}