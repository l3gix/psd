#include <stdlib.h>
#include <stdio.h>
#include "libro.h"
#include <string.h>

struct libro
{
    char *autore,
         *titolo,
         *editore;
    int anno;
};

Libro newLibro(char *autore,char *titolo,char *editore,int anno)
{
    Libro t = malloc(sizeof(struct libro));
    if(t == NULL)fprintf(stderr,"Errore");

    t->autore = malloc((strlen(autore)+1)*sizeof(char));
    if(t->autore == NULL) fprintf(stderr,"Errore");
    strcpy(t->autore,autore);

    t->titolo = malloc((strlen(titolo)+1)*sizeof(char));
    if(t->titolo == NULL) fprintf(stderr,"Errore");
    strcpy(t->titolo,titolo);

    t->editore = malloc((strlen(editore)+1)*sizeof(char));
    if(t->editore == NULL) fprintf(stderr,"Errore");
    strcpy(t->editore,editore);

    t->anno = anno;

    return t;
}

void stampaLibro(Libro l,int indice)
{
    printf("Libro N : %d \n",indice);
    printf("Autore : %s \n",l->autore);
    printf("Titolo : %s \n",l->titolo);
    printf("Editore : %s \n",l->editore);
    printf("Anno Pubblicazione : %d \n\n",l->anno);
}

void StampaLibri(Libro *l,int dim)
{
    int i = 0;
    for(; i < dim ; i++)
    {
        stampaLibro(l[i],i);
    }
}

void swapLibro(Libro *a,Libro *b)
{
    Libro t = *a; 
    *a = *b;
    *b = t;
}

void OrdinaLibri(Libro *l,int dim)
{
    int i = 0,j= 0;
    for(; i < dim - 1 ; i++)
    {
        for(j = 0 ; j < dim -1  ; j++)
        {
            if(strcmp(l[j]->titolo,l[j+1]->titolo ) > 0)
            {
                swapLibro(&l[j],&l[j+1]);
            }
        }
    }
}