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

/*
	a[] array di item
	start punto di inizio
	n dimensione 
*/

/*
Complessita 
forma nella tabella 1a
T(0) = c
T(n) = T(n-1) + b

Complessita O(n)
*/
int findMinIndex(Item a[],int start , int n)
{
	if(start == n-1)return start;

	int minIndex = findMinIndex(a,start + 1,n);

	if(cmpItem(a[start],a[minIndex] )< 0)return start;
	else return minIndex;
}

/*
	Complesità
	forma nella tabella 2a
	T(0) = c
	T(n)=T(n−1)+O(n) = T(n-h)+b*n+d

	O(n^2)

*/
void recursiveSelectionSort(Item a[],int start , int n)
{
	if(start >= n-1)return;

	int minIndex = findMinIndex(a,start,n);	 // O(n-start)

	swap(&(a[start]), &(a[minIndex])); // 0(1)

	recursiveSelectionSort(a,start + 1 ,n); // chiamata ricorsiva T(n) = aT(n-1) + b
}

void SelectionSortRic(Item a[], int n)
{
	int start = 0;
	recursiveSelectionSort(a,start,n);
}



