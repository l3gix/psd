#include "item.h"
#include "queue.h"
#include <stdio.h>
#define DIM 10

int main(){
	int n=5;
	Item a;
	Queue q=newQueue();
	for(int i=0;i<n;i++){
		a=inputItem();
		enqueue(q,a);
		printf("\n");
		printQueue(q);
	}

	reverseQueue(q);
	printf("\n");
	printQueue(q);
		

	
	
}
