#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "string.h"

void filterList(List l)
{
	Item temp;
	for(int i = 0; i < sizeList(l) ; i++)
	{
		temp = removeListPos(l,i);
		if(strncmp("b",getString(temp),1) != 0) addListPos(l,temp,i);
	}
}

void reverseListMain(List l)
{
	for(int i = 1 ; i <= sizeList(l)  ; i++)
	{
		Item x = removeListPos(l,sizeList(l) - i );
		addListTail(l,x);
	}
}

void minList(List l)
{
	//int size = sizeList(l);
	Item min = removeListPos(l,0);
	for(int i = 0 ; i < sizeList(l) ; i++)
	{
		Item temp = removeListPos(l,i);
		if(cmpItem(min,temp) > 0)
		{
			addListPos(l,min,i);
			min = temp;
		}else 
		{
			addListPos(l,temp,i);
		}
	}
	addHead(l,min);
}


void maxList(List l)
{
	//int size = sizeList(l);
	Item max = removeListPos(l,0);
	for(int i = 0 ; i < sizeList(l) ; i++)
	{
		Item temp = removeListPos(l,i);
		if(cmpItem(max,temp) < 0)
		{
			addListPos(l,max,i);
			max = temp;
		}else 
		{
			addListPos(l,temp,i);
		}
	}
	addListTail(l,max);
}

void inputReverseList();
void inputMinAndMax();

int main(void)
{

	//inputReverseList();
	inputMinAndMax();
	/*
	FILE *f = fopen("input_n.txt","r");
	char line[100];
	while(fgets(line,100,f))
	{
		int *buffer;
		List l = newList();
		int i = 0,n = 0;
		while((buffer = malloc(sizeof(int))) && sscanf(line+i,"%d%n",buffer,&n) == 1)
		{
			//printf("%s\n",buffer);
			addListTail(l,buffer);
			i+=n;
		}
		printf("stampo della lista non inverita \n");
		printList(l);
		printf("\n");
		minList(l);
		printList(l);
		printf("\n");
	}
	*/
	return 0;
}


void inputReverseList()
{
	FILE *f = fopen("input.txt","r");
	char line[100];
	while(fgets(line,100,f))
	{
		char buffer[100];
		List l = newList();
		int i = 0,n = 0;
		while(sscanf(line+i,"%s%n",buffer,&n) == 1)
		{
			//printf("%s\n",buffer);
			addListTail(l,strdup(buffer));
			i+=n;
		}
		printf("stampo della lista non inverita \n");
		printList(l);
		printf("\n");
		reverseListMain(l);
		printList(l);
		printf("\n");
	}
}

void inputMinAndMax()
{
	FILE *f = fopen("input_n.txt","r");
	char line[100];
	while(fgets(line,100,f))
	{
		int *buffer;
		List l = newList();
		int i = 0,n = 0;
		while((buffer = malloc(sizeof(int))) && sscanf(line+i,"%d%n",buffer,&n) == 1)
		{
			//printf("%s\n",buffer);
			addListTail(l,buffer);
			i+=n;
		}
		printf("stampo della lista \n");
		printList(l);
		printf("\n");
		//minList(l);
		maxList(l);
		printList(l);
		printf("\n");
	}
}
