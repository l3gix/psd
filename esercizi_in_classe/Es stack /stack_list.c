#include <stdlib.h>
#include "stack.h"
#include "item.h"
#include "list.h"

struct stack
{
    List items;
};

Stack newStack()
{
    Stack s = malloc(sizeof(struct stack));
    s->items = newList();
    return s;
}

int isEmptyStack(Stack s)
{
    return isEmpty(s->items);
}

int push(Stack s, Item item)
{
    addHead(s->items,item);
    return 1;
}

int pop(Stack s)
{
    if(removeHead(s->items) != NULL)return 1;
    else return 0;
}

Item top(Stack s)
{
    return getHead(s->items);
}

void printStack(Stack s)
{
    printList(s->items);
}


