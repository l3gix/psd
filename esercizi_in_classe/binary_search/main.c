#include <stdio.h>
#include <stdlib.h>
#define N 5

void swap(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void inputArray(int array[], int n){
	for (int i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}   
}
void outputArray(int array[], int n){

	for (int i = 0; i<n; i++){
		printf("%d\t", array[i]);
	}
}

int trovaMinimo(int array[], int n){

	int posMinimo = 0;
	for (int i = 1; i<n; i++){
		if (array[i] < array[posMinimo]){
			posMinimo = i;
		}
	}
	return posMinimo;
}

void selectionSort(int array[], int n){
	for (int i = 0; i<n-1;i++){
		int posMinimo = trovaMinimo(array+i, n-i) + i; // array + i = &array[i]
		swap(&array[i], &array[posMinimo]);
	}
}

void insertionSortArray(int a[], int *n, int val)
{
	int i, j;
	
	for(i=*n; (i>0)&&(val<a[i-1]); i--)
	{
		a[i]=a[i-1];
	}
	
	a[i]=val;
	(*n)++;
}

void insertionSort(int a[], int n)
{
	int i=1;
	
	while(i<n)
		insertionSortArray(a, &i, a[i]);
}

int bubbleSort(int a[], int n)
{
	int i, j, count=0;
	
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			count++;
			if(a[j]>a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
	return(count);
}

int adaptiveBubbleSort(int a[], int n)
{
	int i, j, ordinato=0, count=0;
	
	for(i=1; i<n && !ordinato; i++)
	{
		ordinato=1;
		for(j=0; j<n-i; j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				ordinato=0;
			}
		}
	}
	return(count);
}


int binarySearch(int array[],int n,int el)
{
    int start  = 0;
    int end = n-1;
    int mid = 0;

    while(start <= end)
    {
        mid = (start + end)/ 2;
        if(array[mid] == el) return mid;
        if(el > array[mid]) 
        {
            start = mid + 1;
        }else //elemento minore
        {
            end = mid - 1;
        }
        
    }

    return -1;
}

int main(){
	int array[N], n = 5, cercare,indice;
	inputArray(array, n);
    adaptiveBubbleSort(array,n);
    outputArray(array,n);
	printf("inserisci un elemento da cercare : ");
    scanf("%d",&cercare);
    indice = binarySearch(array,n,cercare);
    if(indice != -1)printf("\nElemnto trovato : %d\nposizione : %d\n",array[indice],indice);
    else printf("Elemento non trovato");
	return 0;
}