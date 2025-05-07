#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"

struct stack{
	List items;
};

Stack newStack()
{
	Stack s;
	s=malloc(sizeof(struct stack));
	s->items=newList();
	return s;
}


int isEmptyStack(Stack s) 
{
	return (isEmpty(s->items));
}


int push(Stack s, Item e)
{
	addHead(s->items, e);
	return 1;
}


int pop(Stack s)
{
	if(removeHead(s->items)==NULL)
		return 0;
	return 1;
}

Item top(Stack s)
{
	return (getHead(s->items));
}


void printStack(Stack s)
{
	printList(s->items);
}