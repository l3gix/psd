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