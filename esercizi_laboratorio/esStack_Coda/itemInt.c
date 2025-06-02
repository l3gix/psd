#include "item.h"
#include <stdio.h>
#include <stdlib.h>

Item inputItem(){
	int *p;
	p=malloc(sizeof(int));
	scanf("%d",p);
	return p;
}

void outputItem(Item item){
	int *p;
	p=item;
	printf("%d ",*p);

}

int cmpItem(Item a,Item b){
	int *p1=a;
	int *p2=b;
	return (*p1)-(*p2);
}
