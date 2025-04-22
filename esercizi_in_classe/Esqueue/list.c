#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct list{
	int size;
	struct node *head;
};

struct node{
	Item value;
	struct node *next;
};

List newList(){
	List l = malloc(sizeof(struct list));

	l->head = NULL;
	l->size = 0;

	return l; 
}

int isEmpty(List l){
	if(l->head == NULL)
		return 1;
	else
		return 0;
}

void addHead(List l, Item item){
	struct node *node = malloc(sizeof(struct node));

	node->value = item;
	//Collego il nodo creato alla testa della lista
	node->next = l->head;

	l->head = node;
	l->size++;
}

Item removeHead(List l){
	//Controlliamo la precondizione
	if(isEmpty(l))
		return NULL;

	struct node *t = l->head;

	Item item;
	//Salvo il contenuto
	item = t->value;

	l->head = t->next;
	free(t);

	l->size--;

	return item;
}


Item getHead(List l){
	if(isEmpty(l))
		return NULL;
	//Lista->Nodo->valore
	return l->head->value;
}

int sizeList(List l){
	return l->size;
}

void printList(List l){
	struct node *p;

	for(p = l->head; p != NULL; p = p->next)
		outputItem(p->value);
}

Item searchListItem(List l, Item item, int *pos)
{
	struct node *p;
	*pos=0;
	for(p = l->head; p != NULL; p = p->next)
	{
		if(cmpItem(p->value,item)==0)
			return p->value;

		(*pos)++;

	}

	*pos = -1;
	return NULL;
}

Item removeListItem(List l, Item item)
{
	struct node *p,*prev;
	Item valore;

	if(isEmpty(l))
		return NULL;	

	for(p = l->head; p != NULL; prev = p, p = p->next)
	{
		if(cmpItem(p->value,item)==0)
		{
			if(p == l->head)
				return removeHead(l);

			prev->next = p->next;
			valore = p->value;
			free(p);
			l->size--;

			return valore;
		}	
	}
	return NULL;
}

Item removeListPos(List l, int pos)
{
	struct node *p,*prev;
	Item valore;
	int k=0;

	if(isEmpty(l) || pos<0 || pos>=l->size)
		return NULL;	

	for(p = l->head; p != NULL; prev = p, p = p->next,k++)
	{
		if(pos == k)
		{
			if(p == l->head)
				return removeHead(l);

			prev->next = p->next;
			valore = p->value;
			free(p);
			l->size--;

			return valore;
		}	
	}
	return NULL;
}

int addListPos(List l, Item item, int pos)
{
	int i;	
	struct node *p, *newNode;
	if(pos < 0 || pos > l->size)
		return 0;

	if(pos == 0)
	{
		addHead(l, item);
		return 1;
	}

	for(p = l->head, i = 0; i < pos - 1; p = p->next, i++);

	newNode = malloc(sizeof(struct node));
	
	newNode->value = item;
	newNode->next = p->next;

	p->next = newNode;
	l->size++;

	return 1;
}

int addListTail(List l, Item item)
{
	return addListPos(l, item, l->size);
}

void reverseList(List l)
{
	struct node *p, *prev, *temp;
	for(prev = NULL, p = l->head; p != NULL; prev = p, p = temp)
	{
		temp = p->next;
		p->next = prev;
	}

	l->head = prev;
}

List cloneList(List l)
{
	List clone = newList();
	struct node *p;
	
	for(p = l->head; p != NULL; p = p->next)
	{
		addListTail(clone, p->value);
	}

	return clone;
}