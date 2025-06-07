#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"


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
	preOrder(h);
	printf("\n");
	insertNodeLeft(h,"z");
	preOrder(h);
	printf("\n");
	insertNodeIfDontHaveRighSon(h,"w");
	preOrder(h);
	printf("\n");
	printf("Numero dei nodi %d\n",countNodi(h));
	printf("\n");
	printf("Numero di nodi che hanno solo il figlio destro %d\n",countNodesIfRight(h));
	printf("\n");
	printf("Cerco il nodo ");
	Item cercato = searchNode(h,"w");
	outputItem(cercato);
	printf("\n");
	//deleteNode(h,"w");

	char stringa[100];
	printHigh(h,stringa);
	printf("\n%s\n",stringa);
	return 0;
}