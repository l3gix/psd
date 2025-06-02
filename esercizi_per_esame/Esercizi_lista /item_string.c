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

char *getString(Item e)
{
	return e;
}