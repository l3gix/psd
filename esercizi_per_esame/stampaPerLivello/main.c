#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
#include "string.h"
#include "stack.h"


/*
	Precondizione : nessuna 
	PostCondizione : tutti i nodi dell' albero sono stati stati stampati in ordine da livello da sinistra verso destra 
*/
void printLevelOrder(BTree t) // complesita O(n^2)
{

	Queue q = newQueue(); // costante 
	enqueue(q,t); // costante 
	while (!isEmptyQueue(q)) // o(n)
	{
		BTree x = dequeue(q); // o(n)
		outputItem(getBTreeRoot(x)); // costante 
		if(getLeft(x) != NULL)enqueue(q,getLeft(x)); //costante
		if(getRight(x) != NULL)enqueue(q,getRight(x));//costante
	}
}	

// O(n)
void postOrderIt(BTree t)
{
	Stack s1 = newStack();
	Stack s2 = newStack();
	push(s1,t);

	while(!isEmptyStack(s1))
	{
		Item root = top(s1);
		pop(s1);

		push(s2,getBTreeRoot(root));

		if(getLeft(root) != NULL)push(s1,getLeft(root));
		if(getRight(root) != NULL)push(s1,getRight(root));
	}
	

	printStack(s2);
}

int main(void){
	
	BTree h, a, c, d, l, p, s, o, q;
	d=buildTree(NULL, NULL, "d");
	o=buildTree(NULL, NULL, "o");
	q=buildTree(NULL, NULL, "q");
	p=buildTree(NULL, NULL, "p");
	s=buildTree(NULL, NULL, "s");
	l=buildTree(o, q, "l");
	a=buildTree(d, l, "a");
	c=buildTree(p, s, "c");
	h=buildTree(a, c, "h");
	
	printLevelOrder(h);
	printf("\n");

	postOrderIt(h);
	return 0;
}