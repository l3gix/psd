#include "item.h"
#include "stack.h"
#include "list.h"
#include <stdlib.h>

struct stack{
	List items;
};

Stack newStack(){
	Stack s=malloc(sizeof(struct stack));
	s->items=newList();
	return s;
} 
int isEmptyStack(Stack s){
	return isEmpty(s->items);
}
int push(Stack s, Item elemento){
	addHead(s->items,elemento);
	return 1;

}
int pop(Stack s){
	return NULL!=removeHead(s->items);
	
}
Item top(Stack s){
	return getHead(s->items);
}
void printStack(Stack s){
	printList(s->items);
}

