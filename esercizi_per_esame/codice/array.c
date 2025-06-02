#include <stdio.h>
#include <stdlib.h>
#define N 10

//f(n) = O(1)
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

//f(n) = O(n) = Omega(n) = Theta(n)
int trovaMinimo(int array[], int n){

	int posMinimo = 0;
	for (int i = 1; i<n; i++){
		if (array[i] < array[posMinimo]){
			posMinimo = i;
		}
	}
	return posMinimo;
}

//f(n) = O(n^2) = Omega(n^2) = Theta(n^2) = n*Theta(n)
void selectionSort(int array[], int n){
	for (int i = 0; i<n-1;i++){
		int posMinimo = trovaMinimo(array+i, n-i) + i; // array + i = &array[i]
		swap(&array[i], &array[posMinimo]);
	}
}

//f(n) = O(n) = Omega(1)
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

//f(n) = O(n^2) = Omega(n) = n*Omega(1)
void insertionSort(int a[], int n)
{
	int i=1;

	while(i<n)
		insertionSortArray(a, &i, a[i]);
}

//f(n) = Theta(n^2)
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

//f(n) = O(n^2) = Omega(n)
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

//f(n) = O(log n) = Omega(1)
int ricercaBinaria( int array[], int n, int elemento)
{
	int inizio=0, fine=n-1, centro;
	while(inizio<=fine)
	{
		centro=(inizio+fine)/2;
		if(array[centro]==elemento)
			return centro;
		else if (elemento>array[centro])
			inizio=centro+1;
		else //elemento<array[centro]
			fine=centro-1;
	}
	return -1;
}

int ricercaBinariaRicorsiva(int a[], int inf, int sup, int e) {
	int centro;

	if(inf > sup){
		return -1;
	}
	else {
		centro = (sup + inf)/2;
		if(e == a[centro]){
			return centro;
		}
		else if (e > a[centro]) {
			return ricercaBinariaRicorsiva(a, centro + 1, sup, e);
		}
		else {
			return ricercaBinariaRicorsiva(a, inf, centro - 1, e);
		}
	}
}

int ricercaBinariaR(int a[], int n, int e) {
	return ricercaBinariaRicorsiva(a, 0, n-1, e);
}

void merge(int a[], int b[], int n1, int n2, int c[])
{
	int i, j, k, temp[n1 + n2];
	for(i = 0, j = 0, k = 0; i < n1 && j < n2; k++)
	{
		if(a[i] <= b[j])
			temp[k] = a[i++];
		else
			temp[k] = b[j++];
	}
	for(;i < n1; i++, k++)
		temp[k] = a[i];
	for(;j < n2; j++, k++)
		temp[k] = b[j];
	for(k = 0; k < n1 + n2; k++)
		c[k] = temp[k];
}

void mergeSort(int a[], int n)
{
	if(n > 1)
	{
		mergeSort(a, n/2);
		mergeSort(a + n/2, n - n/2);
		merge(a, a + n/2, n/2, n - n/2, a);
	}
}

int partition (int a[], int start, int end)
{
	int pivot,i,j;
	i=start-1;
	j=end+1;
	pivot=a[start];
	while(1) {
		do {
			j--;
		} while (a[j]>pivot);
		do {
			i++;
		} while(a[i]<pivot);
		if(i>=j) {
			return j;
		}
		swap(&a[i],&a[j]);
	}
}

void quicksort(int a[], int start, int end)
{
	if(start<end) {
		int p=partition(a,start,end);
		quicksort(a,start,p);
		quicksort(a,p+1,end);
	}
}

void quickSort(int a[], int n)
{
	quicksort(a,0,n-1);
}

int main(){
	int c[N], n = 5;
	
	inputArray(c, n);
	quickSort(c, n);
	outputArray(c, n);

	return 0;
}

