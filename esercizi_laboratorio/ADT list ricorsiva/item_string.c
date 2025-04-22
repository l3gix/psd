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

Item inputItemFile(FILE *fp)
{
	char *p = malloc(MAX*sizeof(char));
	if (fscanf(fp, "%s", p) != 1) {
        free(p);  // libera la memoria se la lettura fallisce
        return NULL;
    }
    return p;
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