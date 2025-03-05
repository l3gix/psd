#include<stdio.h>
#include<stdlib.h>

#define N 5

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void inputArray(int array[], int n)
{
	int i;
	for(i = 0; i < n ; i++)
	{
		printf("inserisci un elemento : ");
		scanf("%d",&array[i]);
	}

}

void outputArray(int array[], int n )
{
	for(int i = 0; i < n ; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int trovaMin(int array[], int n)
{
	int min = 0;
	for(int i = 1 ; i < n ; i++)
	{
		if(array[i] < array[min])
		{
			min = i;
		} 
	}
	
	return min;
}

void selectionSort(int array[], int n )
{
    for(int i = 0; i < n-1 ; i++)
    {
        int min = trovaMin(array + i , n - i); // array + i il sotto array corrente 
        swap(array + i , array + (min + i) ); // somma del sotto array 
    }
}

int main(void)
{
	int a[N], n = 5,min = 0;
	inputArray(a,n);
	min = trovaMin(a,n);
	printf("minimo %d e indice %d\n",a[min],min);
	outputArray(a,n);
    selectionSort(a,n);
    outputArray(a,n);

}
