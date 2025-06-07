#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"
#include "btree.h"

BTree cast(Stack s)
{
	Item root = top(s);
		pop(s);

	Item left = top(s);
		pop(s);
	
	Item righ = top(s);
		pop(s);

	while(!isEmptyStack(s))
	{
		// tolgo la radice
		Item root = top(s);
		pop(s);

		Item left = top(s);



	}
}



int main()
{
	return 0;
}