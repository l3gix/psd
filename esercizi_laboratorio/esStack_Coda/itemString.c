#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Item inputItem(){
	char *p;
	p=malloc(20*sizeof(char));
	scanf("%s",p);
	return p;
}

void outputItem(Item item){
	char *p;
	p=item;
	printf("%s ",p);
}

int cmpItem(Item a,Item b){
	char *p1=a,*p2=b;

	return strcmp(p1,p2);
	
}
