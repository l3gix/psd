#define N 10

// Swap due elementi
void swap(int *a, int *b);

// Input/Output array
void inputArray(int array[], int n);
void outputArray(int array[], int n);

// Algoritmi di ordinamento
int trovaMinimo(int array[], int n);
void selectionSort(int array[], int n);
void insertionSortArray(int a[], int *n, int val);
void insertionSort(int a[], int n);
int bubbleSort(int a[], int n);
int adaptiveBubbleSort(int a[], int n);
void mergeSort(int a[], int n);
void mergeSortIterativo(int a[], int n);
void quickSort(int a[], int n);

// Funzioni ausiliarie per ordinamenti
void merge(int a[], int b[], int n1, int n2, int c[]);
int partition(int a[], int start, int end);
void quicksort(int a[], int start, int end);

void mergeSortStampe(int n);

// Ricerca binaria (iterativa e ricorsiva)
int ricercaBinaria(int array[], int n, int elemento);
int ricercaBinariaRicorsiva(int a[], int inf, int sup, int e);
int ricercaBinariaR(int a[], int n, int e);



