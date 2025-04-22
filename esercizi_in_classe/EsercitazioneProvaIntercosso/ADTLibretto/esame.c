#include <stdio.h>
#include <stdlib.h>
#include "esame.h"
#include <string.h>

struct esame
{
    char *nome_esame;
    int voto;
};


Esame initEsame(char *nome_esame,int voto)
{
    Esame p = malloc(sizeof(struct esame));
    
    p->nome_esame = malloc((strlen(nome_esame)+1)*sizeof(char));
    if(p->nome_esame == NULL)
    {
        fprintf(stderr, "Allocazione fallita\n");
        exit(0);
    };
    strcpy(p->nome_esame,nome_esame);

    p->voto = voto;
    
    return p;
}


char *getNomeEsame(Esame e)
{
    return e->nome_esame;
}
int getVoto(Esame e)
{
    return e->voto;
}