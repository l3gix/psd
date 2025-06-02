#include <stdio.h>
#include "list.h"
#include "item.h"


int main(void){
	int n=5;
	int pos;
	Item a;
	List l=newList();
	for(int i=0;i<n;i++){
		a=inputItem();
		addHead(l,a);
	}
	printList(l);
	printf("\nInserisci posizione in cui aggiungere l'Item: ");
	scanf("%d",&pos);
	printf("\nInserici l'Item: ");
	a = inputItem();
	addListPos(l,a,pos);
	printList(l);
	return 0;
}
