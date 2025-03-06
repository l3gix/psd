#include<stdio.h>
#include<stdlib.h>
#include"vector.h"
#define MAX 5

int main()
{
    int dim = 5;
    int *a = calloc(dim,sizeof(int));
    int cerca;

    printf("inserisci elementi nell ìarray \n");
    inpurArray(a,dim);

    selectionSort(a,dim);
    printf("Stampa elementi dell' array \n");
    outputArray(a,dim);

    /*
    printf("inserisci un elemento da cercare : ");
    scanf("%d",&cerca);
    cerca = ricercaArray(a,dim,cerca);
    if(cerca != -1) printf("Elemento Trovato nella posizione %d = %d\n",cerca,a[cerca]);
    else printf("ELemento non trovato");
    */
    printf("Inserisci l'elemento da eleminare :");
    scanf("%d",&cerca);
    eleminaArray(a,&dim,cerca);
    printf("Stampa elementi dell' array \n");
    outputArray(a,dim);


    printf("Inserisci l'elemento da aggiungere :");
    scanf("%d",&cerca);
    insersisciArray(a,&dim,cerca);
    printf("Stampa elementi dell' array \n");
    outputArray(a,dim);

    free(a);
    
    return 0;
}
