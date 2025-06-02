#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "auto.h"
#include "string.h"


Item inputItem()
{
    char marca[30],modello[30];
    int anno_di_produzione;
    double prezzo;

    printf("Input Auto\n");
    printf("Insersci un marca ");
    scanf("%s",marca);
    printf("Inserisci un modello ");
    scanf("%s",modello);
    printf("Inserisci un anno di produzione ");
    scanf("%d",&anno_di_produzione);
    printf("Inserisci il prezzo ");
    scanf("%lf",&prezzo);

    return newCar(marca,modello,anno_di_produzione,prezzo);
}

void outputItem(Item e)
{
    Car c = e;
    printf("Stampo auto \n");
    printf("Marca : %s\nModello : %s\nAnno di Produzione : %d\nPrezzo : %lf\n",getMarca(c),getModello(c),getAnnoDiProduzione(c),getPrezzo(c));
}

//compare per marca
int cmpItem(Item e1, Item e2)
{
    Car c1 = e1,
        c2 = e2;

    return strcmp(getModello(c1),getModello(c2));
}