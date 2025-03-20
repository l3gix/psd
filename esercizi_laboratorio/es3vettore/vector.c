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


//somma elementi dell ' array 
int sommaInArray(int a[],int size)
{
    int i,somma = 0;
    for(int i = 0 ; i < size ; i++)
    {
        somma += a[i];
    }

    return somma;
}

//somma gli elementi di due array e inserisci il risulato in un array preso in input
void sommaArray(int a[],int b[],int r[],int sizeA, int sizeB, int sizeR)
{
    int i;
    for(i = 0; i < sizeR ; i++)
    {
        r[i] = a[i] + b[i];
    }
}

//somma il prodotto di due array e l ho ritorna 
int prodotto(int a[],int b[],int sizeA, int sizeB)
{
    int i,somma = 0;
    for(i = 0; i < sizeB ; i++)
    {
        somma += (a[i] * b[i]);
    }

    return somma;
}

//funzione che carica dati da un buffer puntato da line nell'array di interi arr
int inputArrayStr(int *arr,char *line , int * pos)
{
    int i=0,n=0, counter=0;
    *pos = 0;
    while(sscanf(line,"%d%n",&arr[i],&n) == 1)
    {
        printf("numero letto %d\ncaratteri letti : %d\n",arr[i],n);
        line += n;
        i++;
        counter +=n;
    }

    *pos = counter + 1;
    return i;
}

int compareArray(int a[],int b[],int sizeA,int sizeB)
{
    int i = 0; 
    for(; i < sizeA ;i++)
    {
        if(a[i] != b[i]) return 0;
    }

    return 1;
}

//alloca in maniera dinamica all'array
int *inputArrayDyn(int *size , char *line)
{
    int *a,k = 0,n = 0;

    while(line[k] != '\0')
    {
        //printf("%d\n",line[k]);
        if(line[k] == 32) (*size)++;
        k++;
    }

    (*size)++;
    //printf("Sono qui\n , size = %d\n", *size);

    a = calloc((*size),sizeof(int));

    if(a == NULL)
    {
        printf("Errore nell allocazione dinamica");
        exit(1);
    }

    for(int i = 0; i < *size ; i++)
    {
        sscanf(line,"%d%n",&a[i],&n);
        line += n;
    }

    //printf("Dalla funzione\n");
    //outputArray(a,(*size));

    return a;
}

int *concatenaVet(int *a,int *b,int sizea,int sizeb,int *sizer)
{
    int *r,i=0;
    
    (*sizer) = sizea + sizeb;

    r = calloc((*sizer),sizeof(int));

    if(r == NULL)
    {
        printf("Errore allocazione dinamica \n");
        exit(0);
    }

    for ( i = 0;i < sizea ; i++) r[i] = a[i];
    for(i = 0;i < sizeb ; i++) r[sizea + i] = b[i];

    return r;



}


