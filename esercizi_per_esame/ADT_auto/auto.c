#include <string.h>
#include "auto.h"
#include <stdlib.h>


struct car
{
    char *marca,
         *modello;
    int anno_produzione;
    double prezzo;
};


Car newCar(char *marca,char *modello,int anno_di_produzione,double prezzo)
{
    Car c = malloc(sizeof(struct car));
    c->marca = strdup(marca);
    c->modello = strdup(modello);

    c->anno_produzione = anno_di_produzione;
    c->prezzo = prezzo;
}


char *getMarca(Car c)
{
    return c->marca;
}


char *getModello(Car c)
{
    return c->modello;
}

int getAnnoDiProduzione(Car c)
{
    return c->anno_produzione;
}

double getPrezzo(Car c)
{
    return c->prezzo;
}
