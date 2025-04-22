#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "esame.h"

#define NMAX 30

Item inputItem()
{
    Esame s;
    char nome_esame[NMAX];
    int voto;
    printf("\nInserisci Esame \n");
    printf("Inserisci il nome dell 'esame : ");
    scanf("%[^\n]",nome_esame);
    getchar();
    printf("Inserisci Voto esame : ");
    scanf("%d",&voto);
    getchar();

    s = initEsame(nome_esame,voto);

    return s;
}
void outputItem(Item e)
{
    Esame s = e;
    printf("Stampo Esame \n");
    printf("Nome esame : %s\n",getNomeEsame(s));
    printf("Voto esame : %d\n",getVoto(s));
}
int cmpItem(Item a , Item b)
{
    Esame ea = a,eb = a;
    return strcmp(getNomeEsame(ea),getNomeEsame(eb));
}