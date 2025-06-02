#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "item.h"


int main(void){
	
	BST t=newBST();
	int a[]={20,10,30,5,15,25,40,3,6,35};
	Item e;
	for(int i=0;i<10;i++){
		insertBST(&t,&a[i]);
	}
	printf("Inserisci un valore da eliminare : ");
	Item e1;
	e1=inputItem();
	deleteBST(&t, e1);
	printf("minimo: ");
	outputItem(min(t));
	printf("\nmassimo: ");
	outputItem(max(t));
	printf("\ninserisci un valore da cercare: ");
	e=inputItem();
	
	if (search(t, e))
		printf("\ntrovato!\n");
	else
		printf("\nnon trovato\n");
	

	return 0;
}