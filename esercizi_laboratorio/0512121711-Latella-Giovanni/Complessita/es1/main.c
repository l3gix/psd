#include "array.h"
#include "item.h"
#define DIM 10

int main(void){
	int n=5;

	Item a[DIM];
	inputArray(a, n);
	//bubbleSort(a,n);
	SelectionSortRic(a,n);
	outputArray(a,n);
	
	return 0;
}