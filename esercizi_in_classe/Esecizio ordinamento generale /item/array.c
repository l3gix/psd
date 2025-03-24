#include <stdio.h>
#include "utils.h"
#include "item.h"
#define DIM 10

void inputArray(Item a[], int n)
{
	for(int i = 0; i < n; i++)
		a[i] = inputItem();
}

void outputArray(Item a[], int n)
{
	for(int i = 0; i < n; i++)
		outputItem(a[i]);
	
}

void bubbleSort(Item a[], int n){
	int i;
	for(i=1; i<n; i++)
		for(int j=0; j< n-i; j++)
			if(cmpItem(a[j],a[j+1]) > 0)
				swap(&(a[j+1]), &(a[j]));
}




