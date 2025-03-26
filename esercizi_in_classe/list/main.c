#include <stdio.h>
#include "list.h"
#include "item.h"


int main(void){
	
	int n=5;
	Item a;
	List l = newList();
	for(int i = 0 ; i < n ; i++)
	{
		a = inputItem();
		addHead(l,a);
	}
	printList(l);
	printf("\nElemento cancella \n");
	outputItem(removeHead(l));
	printf("\n");
	printList(l);

	return 0;
}