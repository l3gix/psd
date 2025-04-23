#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stack.h"
#include "item.h"


void ricorsiva(Stack s, Item e)
{
	Item t ;
	if(isEmptyStack(s)) return;
	else 
	{
		t = top(s);
		pop(s);
		ricorsiva(s,e);
		if(compareItem(t , e) > 0)
		{
			push(s,t);
		}
	}
}



void reverseAndPrint(Stack s , Item e)
{
	//Stack temp = newStack();
	Item temp[MAXSTACK];
	int n = 0;
	while(!isEmptyStack(s))
	{
		Item t;
		t = top(s);
		pop(s);
		if(compareItem(t,e) > 0)
		{
			temp[n] = t;
			n++;
		}

	}

	for(int i = 0; i < n ; i++)
	{
		push(s,temp[i]);
	}
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
	char line[100];

	FILE *fp = fopen("input.txt", "r");
	while (fgets(line, 100, fp)) {
		Stack s = newStack();
		char *buf, *param = NULL;
		for (int i = 0, n; buf = malloc(100), sscanf(line + i, "%s%n", buf, &n) == 1; i += n) {
			if (strcmp(buf, "!") == 0) buf = randomItem();
			if (param == NULL)
				param = buf;
			else
				push(s, buf);
		}
		reverseAndPrint(s, param);

		printStack(s);
		printf("\n");
	}
	
	fclose(fp);
	
}
