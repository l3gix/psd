#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define N 10


int main()
{
	int a[N],n = 5;
	inputVector(a,n);
	//insertionSort(a,n);
	bubbleSort(a,n);
	printVector(a,n);

}