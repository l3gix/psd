#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem()
{
	int *p = malloc(sizeof(int));
	scanf("%d",p);

	return p;
}

Item inputItemFile(FILE *fp)
{
	int *p = malloc(sizeof(int));
	if (fscanf(fp, "%d", p) != 1) {
        free(p);  // libera la memoria se la lettura fallisce
        return NULL;
    }
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