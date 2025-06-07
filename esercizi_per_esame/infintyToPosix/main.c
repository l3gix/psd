#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"
#include <string.h>

int isOperator(Item x)
{
	if(cmpItem(x,"+") == 0 )return 1;
	if(cmpItem(x,"-") == 0 )return 1;
	if(cmpItem(x,"/") == 0 )return 1;
	if(cmpItem(x,"*") == 0 )return 1;
	return 0;
}

void operator(Stack s , Item e)
{
	if(!isEmptyStack(s) && isOperator(e) == 0 && isOperator(top(s)) == 1)
	{
		Item temp = top(s);
		pop(s);
		push(s,e);
		push(s,	temp);
	}
	else 
	{
		push(s,e);
	}
}

int precedenza(Stack n,Stack o, Item x) 
{
	if(cmpItem(x,")") == 0)
	{
		while(!isEmptyStack(o))
		{
			push(n,top(o));
			pop(o);
		}
		return 1;
	}else return 0;
}

void insertAtBottom(Stack s, Item value)
{
	if (isEmptyStack(s)) {
		push(s, value);
	} else {
		Item temp = top(s);
		pop(s);
		insertAtBottom(s, value);
		push(s, temp);
	}
}

void reverseStack(Stack s)
{
	if (!isEmptyStack(s)) {
		Item temp = top(s);
		pop(s);
		reverseStack(s);
		insertAtBottom(s, temp);
	}
}

void infityToPosix(char *str)
{
	Stack num = newStack();//stack per contere i numeri
	Stack o = newStack();//stack per contere le operazione 

	char buff[10];

	for(int i = 0, n = 0; sscanf(str + i, "%s%n", buff, &n) == 1; i += n)
	{
		Item x = strdup(buff);
		if(precedenza(num,o,x))
		{

		}else if(isOperator(x) == 0 && (cmpItem(x,"(") != 0 || cmpItem(x,")") != 0 ))
		{
			push(num,x);
		}else if(isOperator(x) == 1)
		{
			push(o,x);
		}
	}

	while (!isEmptyStack(o))
	{
		push(num,top(o));
		pop(o);
	}
	

	printf("stack numeri \n");
	printStack(num);
	printf("\n");
	printf("stack op \n");
	printStack(o);
	printf("\n");
	printf("\n");
}




int main(void)
{
	//Stack s = newStack();
	char *s = "( 15 - 7 ) * ( 10 / 5 )";
	infityToPosix(s);
	return 0;
}
