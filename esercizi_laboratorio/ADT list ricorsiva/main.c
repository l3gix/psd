#include <stdio.h>
#include "list.h"
#include "item.h"


int main(void)
{
	int pos = 0;
	List l=newList();

	FILE *fp = fopen("numeri.txt", "r");

	if (fp == NULL) {
    fprintf(stderr,"Errore apertura file");
    return 1;
	}

	//int n=5
	//Item a,b;

	Item x,cerca;
	while ((x = inputItemFile(fp)) != NULL) {
    	//outputItem(x);
		addHead(l,x);
    	//printf("\n");
	}
	printf("Stampa della lista \n");
	printListRec(l);
	printf("Inserisci un item da cercare :");
	cerca = inputItem();
	cerca = searchListRec(l,cerca,&pos);
	printf("elemento trovato nella posizone %d \n",pos);

	printf("Inserisci il item da cercare per le occorenze  : ");
	cerca = inputItem();
	printf("Numero occorenze %d \n" , countItemListRec(l,cerca));

	printf("Destroy della funzione \n");
	destroyListRec(l);



	return 0;
}
