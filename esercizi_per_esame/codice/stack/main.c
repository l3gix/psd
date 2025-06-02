#include <stdio.h>
#include "stack.h"
#include "item.h"



int main(void){
	int n=5;
	Item a;
	Stack s=newStack();
	for(int i=0;i<=n;i++){
		a=inputItem();
		push(s,a);
		printf("\n");
		printStack(s);
	}
	printf("\n");
	for(int i=0;i<=n;i++){
		a=top(s);
		printf("\nSto cancellando: ");
		if(a!=NULL)
			outputItem(a);
		pop(s);
		printf("\n");
		printStack(s);
	}
	return 0;
}
