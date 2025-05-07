#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
#include "stack.h"

//esercizio 1
int CountNodeTree(BTree t);
int highTree(BTree t);
int max(int a ,int b);//funzione per il calcolo del massimo
//Esercizio 2 
void visitTree(BTree t);

//Esercizio 3
void preOrderIt(BTree t);
void postOrderIt(BTree t);
void inOrderIt(BTree t);

int main(void){
	
	BTree a,b,c,d,e;
	int x[5];
	x[0] = 1;
	e = buildTree(NULL,NULL,&x[0] );
	x[1] = 5;
	d = buildTree(NULL,NULL,&x[1]);
	x[2] = 9;
	c = buildTree(e,d,&x[2]);
	x[3] = 3;
	b = buildTree(NULL,NULL,&x[3]);
	x[4] = 7;
	a = buildTree(b,c,&x[4]);

	printTree(a);
	printf("numero nodi :%d\n",CountNodeTree(a));
	printf("altezza albero : %d\n",highTree(a));
	
	printf("Visita dell albero : ");
	visitTree(a);
	printf("\n");
	printf("Preorder : ");
	preOrderIt(a);
	printf("\n");
	printf("Postorder : ");
	postOrderIt(a);
	printf("\n");
	printf("InOrder : ");
	inOrderIt(a);
	printf("\n");
	
	//albero randomico
	
	BTree h = newRandomTree(4);
	printTree(h);
	printf("numero nodi :%d\n",CountNodeTree(h));
	printf("altezza albero : %d\n",highTree(h));
	
	printf("Visita dell albero : ");
	visitTree(h);
	printf("\n");
	printf("Preorder : ");
	preOrderIt(h);
	printf("\n");
	printf("Postorder : ");
	postOrderIt(h);
	printf("\n");
	printf("InOrder : ");
	inOrderIt(h);
	printf("\n");
	return 0;
}

//Esercizio 1 
/*
	funzione che ritorna il numero di archi e l'altezza dell albero
	CountNodeTree(BTree t) ritorna il numero dei nodi 
	highTree(BTree t) ritona l'altezza del albero
*/
int CountNodeTree(BTree t)
{
	if(isEmptyTree(t)) return 0;
	else 
	{
		return 1 + CountNodeTree(getLeft(t)) + CountNodeTree(getRight(t));
	}
}

//serve per trovare il maggiore 
int max(int a ,int b)
{
	return a > b ? a : b;
}

int highTree(BTree t)
{
	if(isEmptyTree(t)) return -1;
	else 
	{
		return 1 + max(highTree(getLeft(t)),highTree(getRight(t)));
	}
}


//Esercizio 2 
void visitTree(BTree t)
{
	if(isEmptyTree(t)) return ;
	Queue q = newQueue();
	enqueue(q,t);
	while(!isEmptyQueue(q))
	{
		BTree temp = dequeue(q);
		outputItem(getBTreeRoot(temp));
		if(getLeft(temp) != NULL)enqueue(q,getLeft(temp));
		if(getRight(temp) != NULL)enqueue(q,getRight(temp));

	}

}

//Esercizi 3 
void preOrderIt(BTree t)
{
	if(isEmptyTree(t)) return;
	Stack s = newStack();
	push(s,t);
	while(!isEmptyStack(s))
	{
		BTree temp = top(s);
		outputItem(getBTreeRoot(temp));
		pop(s);
		if(getRight(temp) != NULL)push(s,getRight(temp));
		if(getLeft(temp) != NULL)push(s,getLeft(temp));
	}
}

void postOrderIt(BTree t)
{
	if (isEmptyTree(t)) return;

    Stack s1 = newStack();
    Stack s2 = newStack();

    push(s1, t);

    while (!isEmptyStack(s1)) {
        BTree curr = top(s1);
        pop(s1);
        push(s2, curr);

        if (getLeft(curr) != NULL)
            push(s1, getLeft(curr));
        if (getRight(curr) != NULL)
            push(s1, getRight(curr));
    }

    while (!isEmptyStack(s2)) {
        outputItem(getBTreeRoot(top(s2)));
        pop(s2);
    }
}


void inOrderIt(BTree t)
{
	if (isEmptyTree(t)) return;

	Stack s = newStack();
	BTree current = t;

	while (!isEmptyStack(s) || current != NULL) {
		// Scendi a sinistra finché possibile
		while (current != NULL) {
			push(s, current);
			current = getLeft(current);
		}

		// Torna su e visita il nodo
		current = top(s);
		pop(s);
		outputItem(getBTreeRoot(current));

		// Passa al sottoalbero destro
		current = getRight(current);
	}
}

