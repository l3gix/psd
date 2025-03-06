#include<stdlib.h>
#include<stdio.h>
#include "vector.h"
#include "utils.h"

void inpurArray(int a[],int n)
{
    for(int i = 0; i < n ;i++)
    {
        printf("v[%d] : ",i);
        scanf("%d",&a[i]);
    }
}

void outputArray(int a[],int n)
{
    for(int i = 0; i < n ;i++)
    {
        printf("v[%d]= %d\n",i,a[i]);
    }
}

int ricercaArray(int a[],int n,int elem)
{
    for(int  i= 0 ; i < n ; i++)
    {
        if(a[i] == elem) return i;
    }

    return -1;
}

int minimoArray(int a[],int n)
{
    int min = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] < a[min] ) min = i;
    }

    return min;
}

void selectionSort(int *a,int n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        int min = minimoArray(a + i,n-i);
        printf("Min %d \n",a[min]);
        swap(a + i,a + (min + i));
    }
}

void eleminaArray(int a[],int *n, int elem)
{
    int indice = ricercaArray(a,*n,elem);

    if( indice != -1 )
    {
        for(int i = indice ; i < *n ; i++)
        {
            a[i] = a[i + 1];
        }

        a[(*n)-1] = -1;

        (*n)--;
    }
}

void insersisciArray(int *a,int *n,int elem)
{
    a = realloc(a,((*n)+1)*sizeof(int));
    
    a[*n] = elem;
    printf("%d\n",a[*n]);

    (*n)++;



}