
//inserisci i numeri dell 'array
void inpurArray(int a[],int n);

//stampa in vettore 
void outputArray(int a[],int n);

//ordina l'array con selection sort
void selectionSort(int *a,int n);

//ricerca un elemento in base un indice
int ricercaArray(int a[],int n,int elem);

//ricerca il minimo elemento all'interno dell array
int minimoArray(int a[],int n);

void eleminaArray(int a[],int *n , int elem);

void insersisciArray(int a[],int *n,int elem);



//somma elementi dell ' array 
int sommaInArray(int a[],int size);

//somma gli elementi di due array e inserisci il risulato in un array preso in input
void sommaArray(int a[],int b[],int r[],int sizeA, int sizeB, int sizeR);

//somma il prodotto di due array e l ho ritorna 
int prodotto(int a[],int b[],int sizeA, int sizeB);

//funzione che carica dati da un buffer puntato da line nell'array di interi arr
int inputArrayStr(int *arr,char *line , int * pos);

//compare gli elementi di due array 
int compareArray(int a[],int b[],int sizeA,int sizeB);



//Funzioni esercizio 3 

//allocazione dinamica dell 'array tramite la funzione
int *inputArrayDyn(int *size , char *line);

// concatela le due stringhe in un terzo array e ritorna l'indirizzo di quest'ultimo
int *concatenaVet(int *a,int *b,int sizea,int sizeb,int *sizer);

