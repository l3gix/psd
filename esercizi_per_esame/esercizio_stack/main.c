#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

void filtroStack(Stack s,Item x)
{
	if(!isEmptyStack(s))
	{
		Item t = top(s);
		pop(s);
		filtroStack(s,x);
		if(strncmp(x,t,1) != 0)
		{
			push(s,t);
		}
	}
}

int searchStack(Stack s,Item x)
{

	if(isEmptyStack(s)) return 0;
	else {
		Item t = top(s);
		pop(s);
		int find = 0;
			find = searchStack(s,x);
		if(cmpItem(t,x) == 0) 
		{
			find++;
		}

		push(s,t);

		return find;
	}
}


void remuveStack(Stack s , Item x)
{
	if(!isEmptyStack(s))
	{
		Item t = top(s);
		pop(s);
		remuveStack(s,x);
		if(cmpItem(t,x) != 0)push(s,t);
	}
}

void minStack(Stack s)
{
	Stack temp = newStack();
	Item min = top(s);
	pop(s);
	while (!isEmptyStack(s))
	{
		if(cmpItem(min,top(s)) > 0)
		{
			push(temp,min);
			min = top(s);
			pop(s);

		}else 
		{
			push(temp,top(s));
			pop(s);
		}
	}

	while(!isEmptyStack(temp))
	{
		push(s,top(temp));
		pop(temp);
	}
	push(s,min);
}


int contaInStack(Stack s)
{
	if(isEmptyStack(s))return 0;
	else 
	{
		int find = 0;
		Item x = top(s);
		pop(s);
		find = 1 + contaInStack(s);
		push(s,x);

		return find;
	}

	
}

char *isMultiplo(Stack s)
{
	int n = contaInStack(s);
	if(n % 3 == 0)return "Ok";
	else if ((n-1) % 3 ==  0) return "RIMUOVI";
	else if((n+1) % 3 == 0) return "AGGIUNGI";
}

void InputString()
{
	FILE *f = fopen("input_s.txt","r");
	if(f == NULL)exit(0);
	char buffer[100]; // buffer per prendere le righe del file fi input
	while(fgets(buffer,100,f))
	{
		char buff[100];//buffer per l'input delle singole parole
		Stack s = newStack();
		char *param = " ";
		for(int i = 0,n = 0; sscanf(buffer +i,"%s%n",buff,&n) == 1; i+=n)
		{
			if(strcmp(param," ") == 0)param=strdup(buff);
			else push(s,strdup(buff));
		}
		printf("Parama %s\n",param);
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
		filtroStack(s,param);
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");

	}
}

void searchInput()
{
	FILE *f = fopen("input_se.txt","r");
	if(f == NULL)exit(0);
	char buffer[100]; // buffer per prendere le righe del file fi input
	while(fgets(buffer,100,f))
	{
		char buff[100];//buffer per l'input delle singole parole
		Stack s = newStack();
		char *param= " ";
		for(int i = 0,n = 0; sscanf(buffer +i,"%s%n",buff,&n) == 1; i+=n)
		{
			if(strcmp(param," ") == 0)param=strdup(buff);
			else push(s,strdup(buff));
		}
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
		int r = searchStack(s,param);
		if(r > 0)printf("TRUE\n");
		else printf("FALSE\n");
		//printf("risultato %d\n",r);
		printf("Stampo dello stack Dopo\n");
		printStack(s);
		printf("\n");

	}
}

void inputRemove()
{
	FILE *f = fopen("input_se.txt","r");
	if(f == NULL)exit(0);
	char buffer[100]; // buffer per prendere le righe del file fi input
	while(fgets(buffer,100,f))
	{
		char buff[100];//buffer per l'input delle singole parole
		Stack s = newStack();
		char *param= " ";
		for(int i = 0,n = 0; sscanf(buffer +i,"%s%n",buff,&n) == 1; i+=n)
		{
			if(strcmp(param," ") == 0)param=strdup(buff);
			else push(s,strdup(buff));
		}
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
		remuveStack(s,param);
		printf("Stampo dello stack Dopo\n");
		printStack(s);
		printf("\n");

	}
}
void inputint()
{
	
	FILE *f = fopen("input_i.txt","r");
	if(f == NULL)exit(0);
	char buffer[100]; // buffer per prendere le righe del file fi input
	while(fgets(buffer,100,f))
	{
		Stack s = newStack();
		int *input;
		for(int i = 0,n = 0; (input  = malloc(sizeof(char))) && (sscanf(buffer + i , "%d%n",input,&n) == 1) ; i+=n)
		{
			push(s,input);
		}

		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
		minStack(s);
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
	}
}

void multiploDi3()
{
	FILE *f = fopen("input_i.txt","r");
	if(f == NULL)exit(0);
	char buffer[100]; // buffer per prendere le righe del file fi input
	while(fgets(buffer,100,f))
	{
		Stack s = newStack();
		int *input;
		for(int i = 0,n = 0; (input  = malloc(sizeof(char))) && (sscanf(buffer + i , "%d%n",input,&n) == 1) ; i+=n)
		{
			push(s,input);
		}

		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
		printf("\nconta in stack %d,%s\n" , contaInStack(s),isMultiplo(s));
		printf("Stampo dello stack\n");
		printStack(s);
		printf("\n");
	}
}

int main(void)
{
	//InputString();
	//inputint();
	//searchInput();
	//inputRemove();
	multiploDi3();
	return 0;
}
