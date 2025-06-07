#include "item.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 10

void reversQueue(Queue q)
{
	if(!isEmptyQueue(q))
	{
		Item x = dequeue(q);
		reversQueue(q);
		enqueue(q,x);
	}
}


void minimoCoda(Queue q)
{
	Queue app = newQueue();
	Item min = dequeue(q);
	while (!isEmptyQueue(q))
	{
		Item temp = dequeue(q);
		if(cmpItem(min,temp) > 0)
		{
			enqueue(app,min);
			min = temp;
		}else enqueue(app,temp);
	}
	enqueue(q,min);
	while(!isEmptyQueue(app))
	{
		enqueue(q,dequeue(app));
	}
	
}

void massimoCoda(Queue q)
{
	Queue app = newQueue();
	Item max = dequeue(q);
	while (!isEmptyQueue(q))
	{
		Item temp = dequeue(q);
		if(cmpItem(max,temp) < 0)
		{
			enqueue(app,max);
			max = temp;
		}else enqueue(app,temp);
	}
	while(!isEmptyQueue(app))
	{
		enqueue(q,dequeue(app));
	}
	enqueue(q,max);
}

int isPalindroma(Queue q,char *s)
{
	int size = strlen(s);
	char buff[100];
	for(int i= size - 1; i >= 0 ; i--)
	{
		//printf("%c\n",s[i]);
		if(s[i] != ' ' && s[i] != '\n')
		{
			Item x = dequeue(q);
			char *c = malloc(2);
				c[0]= s[i];
				c[1] = '\0';
			//outputItem(c);
			//printf("da qui in poii\n");
			//outputItem(x);
			if(cmpItem(x,c) != 0)return 0;
		}
	}

	return 1;
}

void inputString();
void inputInt();
void inputStringPalindroma();



int main()
{
	//inputString();
	//inputInt();
	inputStringPalindroma();
}


void inputStringPalindroma()
{
	FILE *f = fopen("input_palindroma.txt","r");
	if(f == NULL)exit(0);
	char buffer[100];
	while(fgets(buffer,100,f))
	{
		char buff[100];
		Queue q = newQueue();
		for(int i = 0,n = 0; (sscanf(buffer + i , "%s%n",buff,&n) == 1) ; i+=n)
		{
				char *stringa = strdup(buff);
				for(int j = 0 ; j < strlen(stringa) ; j++)
				{
					char *c = malloc(2);
						c[0] = stringa[j];
						c[1] = '\0';
					outputItem(c);
					enqueue(q,c);
				}
				
				
			//enqueue(q,strdup(buff));

		}

		printf("\ncoda\n");
		printQueue(q);
		printf("\n");
		//isPalindroma(q,buffer);
		if(isPalindroma(q,buffer) == 0)printf("La stringa non e palindroma \n");
		else printf("La stringa e palindroma \n");
		printf("\n");
	}

	fclose(f);
}


void inputString()
{
	FILE *f = fopen("input_s.txt","r");
	if(f == NULL)exit(0);
	char buffer[100];
	while(fgets(buffer,100,f))
	{
		char buff[100];
		Queue q = newQueue();
		for(int i = 0,n = 0; sscanf(buffer + i , "%s%n",buff,&n) == 1 ; i+=n)
		{
			enqueue(q,strdup(buff));
		}

		printf("coda\n");
		printQueue(q);
		printf("\n");
		reversQueue(q);
		printf("Reverse Coda\n");
		printQueue(q);
		printf("\n");
		
	}

	fclose(f);
}

void inputInt()
{
	FILE *f = fopen("input_n.txt","r");
	if(f == NULL)exit(0);
	char buffer[100];
	while(fgets(buffer,100,f))
	{	
		int *buff;
		Queue q = newQueue();
		for(int i = 0,n = 0; (buff = malloc(sizeof(int)) ) && (sscanf(buffer+i,"%d%n",buff,&n) == 1);i+=n)
		{
			enqueue(q,buff);
		}


		printf("stampo la coda\n");
		printQueue(q);
		printf("\n");
		minimoCoda(q);
		printf("stampo la coda con il min\n");
		printQueue(q);
		printf("\n");
		massimoCoda(q);
		printf("stampo la coda con il max\n");
		printQueue(q);
		printf("\n");

	}
}
