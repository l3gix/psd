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

	for(int i=0;i<n+1;i++){
		a=dequeue(q);
		printf("sto cancellando: ");
		if(a!=NULL){
			outputItem(a);

		}
		printf("\n");
		printQueue(q);
		

	}
	
}
