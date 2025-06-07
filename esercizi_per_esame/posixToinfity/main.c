#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "stack.h"
#include "string.h"

/*
	complessita costante O(1);
	prequisiti nessuno 
	post requisiti ritrona 1 se e un operatore seno ritorna zero
*/
int isOperation(Item x)
{
	if(cmpItem(x,"+") == 0) return 1;
	if(cmpItem(x,"-") == 0) return 1;
	if(cmpItem(x,"/") == 0) return 1;
	if(cmpItem(x,"*") == 0) return 1;

	return 0;
}

/*
	Prerequisiti : Nessuno
	Post requisit : ritorna l'labero costriutio con le operazioni 

	in tutto questo algortmo e linera O(n);
*/
BTree posixToInfinity(char *str)
{
	char buff[100];
	Stack s = newStack();
	//ciclo linerare quindi o(n) dove n dipende dalla lunghezza della stringa passa in input 
	//ciclo per prendere i singoli numerie e operatari della stringa 

	for(int i = 0, n = 0; sscanf(str + i, "%s%n",buff,&n) == 1 ; i+=n)
	{
		Item x = strdup(buff); // lineare dipende dalla dimensione della stringa da copiare
		//is operator e costante 
		// controlla se è un operando e nel caso costruisce l'albero con l'operando come radice 
		if(isOperation(x) == 1)
		{
			BTree righ = top(s);//costante
			pop(s);
			BTree left = top(s);//costante
			pop(s);
			BTree root = buildTree(left ,righ,x);//costante
			push(s,root);//costante
		}else // in questo caso se non e un operando coststuisce una foglia e lo inserisce nello stack 
		{
			
			BTree temp = buildTree(NULL,NULL,x);//costante
			push(s,temp);//costante 
		}

		
	}

		BTree t = top(s);//costante
		pop(s);//costante
		return t; // ritorna l'albero
}

void printInfity(BTree t)
{
	if(!isEmptyTree(t)) 
	{
		if(getLeft(t) != NULL || getRight(t) != NULL )printf("(");
		printInfity(getLeft(t));


		outputItem(getBTreeRoot(t));

		printInfity(getRight(t)); 
		if(getLeft(t) != NULL || getRight(t) != NULL)printf(")");
	}
}

int main(void){
	FILE *f = fopen("input.txt","r");
	char buffer[100];
	while(fgets(buffer,100,f))
	{
		BTree t = posixToInfinity(buffer);
		printInfity(t);
		printf("\n");
	}
	return 0;
}