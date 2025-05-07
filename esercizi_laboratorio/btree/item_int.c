#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem()
{
	int *p = malloc(sizeof(int));
	scanf("%d",p);

	return p;
}

void outputItem(Item item)
{
	int *p = item;
	printf("%d ",*p);
}

int cmpItem(Item itemA, Item itemB)
{
	int *pA = itemA,*pB = itemB;

	return (*pA) - (*pB);
}


char* itemToString(Item a) {
	char *p=malloc(12*sizeof(char));
	sprintf(p, "%d", *((int*)a));
	return p;
}

Item randomItem() {
	int *pt = malloc(sizeof(int));
	*pt = rand() % 10;
	return pt;
}