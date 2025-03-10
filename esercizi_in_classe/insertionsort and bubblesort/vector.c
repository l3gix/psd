#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "utils.h"



void insertIntoSort(int a[],int *n,int val)
{
	int i;
	for(i = *n ; (i > 0) && (val < a[i-1]) ; i--)
	{
		a[i] = a[i-1];
	}

	a[i] = val;
	(*n)++;
}


void insertionSort(int a[],int n)
{
	int i = 1;
	while(i < n)
	{
		insertIntoSort(a,&i,a[i]);
	}
}

void bubbleSort(int a[],int n)
{
	int i ;
	for(i = 1 ; i < n  ; i++ )
	{
		for(int j = 0 ; j < n-i ; j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a + j , a + j + 1);
			}
		}
	}
}


void inputVector(int a[],int n)
{
    for(int i = 0; i < n ;i++)
    {
        printf("v[%d] : ",i);
        scanf("%d",&a[i]);
    }
}


void printVector(int array[], int n){

	for (int i = 0; i<n; i++){
		printf("%d\t", array[i]);
	}

	printf("\n");
}