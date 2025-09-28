#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"

int maxV(int a,int b)
{
	return a > b ? a : b ;
}


/*
	prerequisiti : nessuno
	postRequisiti : ritorla l'altezza dell albero

	Complessita 
	ci ritroviamo nel caso 1b ovvero
	t(n) = at(n/p) + b 
	t(n) = max(t(left),t(right)) singola chiamata ricorsiva quidi lineare O(n);

*/
int high(BTree t)
{
	// se albero e vuoto ritona -1
	if(isEmptyTree(t))
		return -1;
	else 
	{
		// restituisce 1 + massimo dell altezza del figlio di desta e quello di sinista 
		return 1 + maxV(high(getLeft(t)),high(getRight(t)));
	}
}

/*
	prerequisiti nessuno 
	postRequisiti : nessuno 
	
	complessita high chiamata due volte quindi O(n^2);
	e la singola chiamata ricorsiva maxPath quindi lineare O(n);
	quindi la complessita nel caso peggiore e O(n^2)

*/
void maxPath(BTree t,Queue q)
{
	if(high(t) == -1) return ;
	else // se non mi trovo nella condizione di essere al altezza minima S
	{
		enqueue(q,getBTreeRoot(t)); // complessita costante 
		//outputItem(getBTreeRoot(t));
		if(high(getLeft(t)) >= high(getRight(t))) maxPath(getLeft(t),q);
		else maxPath(getRight(t),q);
	}
}

void minPath(BTree t,Queue q)
{
	if(high(t) == -1) return ;
	else 
	{
		enqueue(q,getBTreeRoot(t));
		if(high(getLeft(t)) <= high(getRight(t))) maxPath(getLeft(t),q);
		else maxPath(getRight(t),q);
	}
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
	
	int maxv = high(h);
	printf("\n \n %d \n",maxv);
	Queue qu = newQueue();
	maxPath(h,qu);
	printQueue(qu);
	printf("\n");
	Queue lo = newQueue();
	minPath(h,lo);
	printQueue(lo);
	printf("\n");
	return 0;
}