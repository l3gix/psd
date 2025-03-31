#include <stdio.h>
#include "list.h"
#include "item.h"


int main(void){
	
	int n=5,pos;
	Item a,cerca;
	List l = newList();
	for(int i = 0 ; i < n ; i++)
	{
		a = inputItem();
		addHead(l,a);
	}
	printList(l);
	printf("\nInserisci elemento da cercare : \n");
	a = inputItem();
	cerca = removeListItem(l,a);
	if(cerca != NULL ) 
	{
		printf("\nElemento eliminato\n");
		outputItem(cerca);
	}
	printf("\n");
	printList(l);
	printf("\n");


	return 0;
}