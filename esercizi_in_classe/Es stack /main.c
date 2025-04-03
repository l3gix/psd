#include <stdio.h>
#include "list.h"
#include "item.h"
#include "stack.h"


int main(void){
	int n=5;
	Item a;
	Stack s = newStack();
	for(int i = 0; i < n ; i++)
	{
		a = inputItem();
		push(s,a);
	}

	for(int i = 0; i < n ; i++ )
	{
		a = top(s);
		printf("\n");
		outputItem(a);
		pop(s);
		printf("\nRimuovo \n");
		printStack(s);
		printf("\n\n");
	}


	return 0;
}
