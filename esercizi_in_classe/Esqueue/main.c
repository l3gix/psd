#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(void){
	Queue q = newQueue ();
	int n = 5;
	Item e;
	for (int i=0; i<n - 1 ; i++) {
		e = inputItem ();
		enqueue(q,e);
		printf ("\n");
		printQueue (q);
	}
	for (int i=0; i<n - 1; i++) {
		printf ("\nStiamo rimuovendo: ");
		e = dequeue(q);
		if (e != NULL) 
			outputItem (e);
		//pop (stack);
		printf ("\n");
		printQueue (q);
	}
	return 0;
}