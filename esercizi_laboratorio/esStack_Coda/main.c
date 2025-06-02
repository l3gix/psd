#include "item.h"
#include "queue.h"
#include <stdio.h>
#define DIM 10

int main(){
	int n=5;
	Item a;
	Queue s=newQueue();
	for(int i=0;i<n;i++){
		a=inputItem();
		enqueue(s,a);
	}
	printQueue(s);
	printf("\n");
	for(int i=0;i<n;i++){
		dequeue(s);
		printQueue(s);
		printf("\n");

		
	}
	printQueue(s);
	
}
