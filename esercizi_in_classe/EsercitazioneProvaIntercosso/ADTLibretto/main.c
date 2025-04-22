#include <stdio.h>
#include "item.h"
#include "libretto.h"


int main(void)
{
    char line[100];
    FILE *fp = fopen("oracolo.txt","r");
    int oracolo;

    char materia[100];
    int pos = 0;
    Libretto l = newLibretto("Giovanni","Latella",1234);
    Item a;
    for(int i = 0; i < 2 ; i++)
    {
        printf("Inserisci voto N : %d",i+1);
        a = inputItem();
        AddEsame(l,a);
    }

    printLibretto(l);

    printf("\n\nInserisci in nome della materia da cercare : ");
    scanf("%[^\n]",materia);
    getchar();
    Item cercato = serachEsame(l,materia,&pos);
    printf("\n\n");
    if(cercato != NULL)outputItem(cercato);
    else printf("Esame non trovato\n");

    fscanf(fp,"%d\n",&oracolo);

    if(oracolo == mediaEsami(l))printf("ok va beneeee \n");
    return 0;
}