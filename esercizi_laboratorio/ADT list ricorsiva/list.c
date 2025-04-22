#include <stdlib.h>
#include <stdio.h>
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
	List l=malloc(sizeof(struct list));
	l->size=0;
	l->head=NULL;
	return l;
}

int isEmpty(List l){
	if(l->size==0){
		return 1;
	}
	else{
		return 0;
	}

}

void addHead(List l, Item e){
	struct node *n=malloc(sizeof(struct node));
	n->value=e;
	n->next=l->head;
	l->head=n;
	(l->size)++;

}

Item removeHead(List l){
	if(isEmpty(l)){
		return NULL;
	}
	struct node *t=l->head;
	l->head=t->next;
	Item tmp=t->value;
	free(t);
	(l->size)--;
	return tmp;
}

Item getHead(List l){
	if(isEmpty(l)){
		return NULL;
	}
	return l->head->value;
}

int sizeList(List l){
	return l->size;
}

void printList(List l){
	struct node *p;
	for(p=l->head; p!=NULL;p=p->next){
		outputItem(p->value);
	}
}

Item searchListItem(List list, Item item, int *pos)
{
	struct node *p;
	*pos=0;

	for(p=list->head; p!=NULL;p=p->next){
		if(cmpItem(item, p->value)==0)
			return p->value;
		(*pos)++;
	}
	*pos=-1;
	return NULL;
}

Item removeListItem(List list, Item item)
{
	struct node *p, *prev;
	Item i;

	if(isEmpty(list))
		return NULL;

	for(p=list->head; p!=NULL;prev=p, p=p->next){
		if(cmpItem(item, p->value)==0)
		{
			if(p==list->head)
				return removeHead(list);

			prev->next = p->next;
			i = p->value;
			free(p);
			list->size--;

			return i;
		}
	}

	return NULL;
}

Item removeListPos(List list, int pos)
{
	struct node *p, *prev;
	Item i;
	int c=0;

	if(isEmpty(list) || pos<0 || pos>= list->size)
		return NULL;

	for(p=list->head; p!=NULL;c++, prev=p, p=p->next){
		if(c == pos)
		{
			if(p==list->head)
				return removeHead(list);

			prev->next = p->next;
			i = p->value;
			free(p);
			list->size--;

			return i;
		}
	}

	return NULL;
}

int addListPos(List l, Item e, int pos)
{
	struct node *p;
	int c = 0;

	if(pos < 0 || pos > l->size)
		return 0;

	for(p=l->head; c<pos-1 ;c++, p=p->next);

	if(pos == 0)
	{
		addHead(l,e);
		return 1;
	}

	struct node *n = malloc(sizeof(struct node));
	n->value = e;
	n->next = p->next;
	p->next = n;
	l->size++;
	return 1;
}

int addListTail(List l, Item e)
{
	return addListPos(l,e,l->size);
}

void reverseList(List l)
{
	struct node *p, *prev, *temp;

	for(p=l->head, prev=NULL; p!=NULL; prev=p, p=temp)
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

	for(p=l->head; p!=NULL; p=p->next)
	{
		addListTail(clone,p->value);
	}

	return clone;
}

void printListRecHelper(struct node *n)
{
	if(n == NULL) return;

	outputItem(n->value);
	printListRecHelper(n->next);
}

void printListRec(List list)
{
	printListRecHelper(list->head);
}

Item searchListRecHelper(struct node *n,Item e , int *pos)
{

	if(n == NULL ) 
	{
		(*pos) = -1;
		return NULL;
	}
	if(cmpItem(n->value, e) == 0)
	{
		return n->value;
	}
	(*pos)++;
	searchListRecHelper(n->next,e,pos);
}

Item searchListRec(List list , Item item,int *pos)
{
	return searchListRecHelper(list->head,item,pos);
}

void countItemListRecHelper(struct node *n,Item item,int *c)
{
	if(n == NULL) return;

	if(cmpItem(n->value,item) == 0)
	{
		(*c)++;
	}

	countItemListRecHelper(n->next,item,c);
	
}

int countItemListRec(List list , Item item)
{
	int counter = 0;
	countItemListRecHelper(list->head,item,&counter);
	return counter;
}

void destroyListRecHelper(struct node *n)
{
	if(n == NULL ) return ;

	//printf("\nnodo eliminato \n");
	//outputItem(n->value);
	//printf("\n");
	destroyListRecHelper(n->next);
	free(n);
}

void destroyListRec(List list)
{
	destroyListRecHelper(list->head);
	free(list);
}

