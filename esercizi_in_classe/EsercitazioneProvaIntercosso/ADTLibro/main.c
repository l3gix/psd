#include <stdio.h>
#include <stdlib.h>
#include "libro.h"

#define MAX 100

int main(void)
{
    char line[100];
    int dim;
    FILE *fp = fopen("input.txt","r");

    if(fp == NULL )
    {
        fprintf(stderr,"Errore");
        exit(0);
    }

    fscanf(fp,"%d\n",&dim);
    //printf("sono qui%d\n",dim);
    Libro *libri = malloc(dim * sizeof(Libro));
    if(libri == NULL)exit(0);

    char autore[100],titolo[100],editore[100];
    int anno;

    for(int i = 0 ; i < dim ; i++)
    {
        if(fgets(line,100,fp) != NULL)
        {
            sscanf(line,"%99[^;];%99[^;];%99[^;];%d",autore,titolo,editore,&anno);
            libri[i] = newLibro(autore,titolo,editore,anno);
        }
    }

    fclose(fp);


    printf("Libri letti dal file:\n");
    StampaLibri(libri, dim);

    OrdinaLibri(libri, dim);

    printf("Libri ordinati per titolo:\n");
    StampaLibri(libri, dim);

    return 0;
}