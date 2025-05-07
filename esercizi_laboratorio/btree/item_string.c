#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

#define MAX 20

Item inputItem()
{
	char *s = malloc(MAX*sizeof(char));
	scanf("%s",s);

	return s;
}

void outputItem(Item item)
{
	char *s = item;
	printf("%s ",s);

}

int cmpItem(Item itemA, Item itemB)
{
	char *sA = itemA,*sB = itemB;

	return strcmp(sA,sB);
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