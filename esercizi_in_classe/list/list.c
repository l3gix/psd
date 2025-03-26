#include "item.h"
#include "list.h"
#include <stdlib.h>

struct list
{
    int size;
    struct  node * head;
};

struct node
{
    Item value;
    struct node *next;
};

// creazione di una nuova lista 
List newList()
{
    List l = malloc(sizeof(struct list));
    l->size = 0;
    l->head = NULL;

    return l;
}

//verifiare se la lista è vuota
int isEmpty(List l)
{
    return (l->size == 0 ? 1 : 0);
}

//inserire un nuovo nodo alla testa della list 
void addHead(List l, Item e)
{
    struct node * n = malloc(sizeof(struct node));
    n->value = e;
    n->next = l->head;
    l->head = n;
    (l->size)++;
}

//rimuovere un nodo dalla testa 
Item removeHead(List l)
{
    if(isEmpty(l))return NULL;
    struct node * t = l->head;
    l->head = t->next;
    Item tmp = t->value; // deve ritornare il valore cancellato
    free(t);
    (l->size)--;
    return  tmp;
}

//ritorna la testa della lista 
Item getHead(List l)
{
    if(isEmpty(l))return NULL;
    return l->head->value;
}

//ritorna la dimensione della lista 
int sizeList(List l)
{
    return l->size;
}

//stampa la lista 
void printList(List l)
{
    struct node *p;
    for(p = l->head ; p != NULL ; p=p->next)
    {
        outputItem(p->value);
    }
}

