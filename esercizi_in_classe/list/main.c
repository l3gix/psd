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
	//printf("\nInserisci posizione in cui vuoi aggiungere l'Item: \n");
	//scanf("%d",&pos);

	//printf("Inserisci l'item : ");
	//a = inputItem();

	//addListPos(l,a,pos);
	//addListTail(l,a);
	List clone = cloneList(l) ;

	printf("\nClone\n");
	printList(clone);

	return 0;
}

