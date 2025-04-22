#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libretto.h"
#include "list.h"


struct studente
{
    char *nome,
        *cognome;
    int matricola;
};


struct libretto
{
    struct studente student;
    List esami;
};

Libretto newLibretto(char *nome_studente,char *cognome_studente, int matricola)
{
    Libretto l = malloc(sizeof(struct libretto));

    l->student.nome = malloc((strlen(nome_studente)+1)*sizeof(char));
    if(l->student.nome == NULL )
    {
        fprintf(stderr,"Errore Allocazione");
        exit(1);
    }
    strcpy(l->student.nome,nome_studente);

    l->student.cognome = malloc((strlen(cognome_studente)+1)*sizeof(char));
    if(l->student.cognome == NULL )
    {
        fprintf(stderr,"Errore Allocazione");
        exit(1);
    }
    strcpy(l->student.cognome,cognome_studente);

    l->student.matricola = matricola;

    l->esami = newList();

    return l;
}

void AddEsame(Libretto l ,Esame e)
{
    addHead(l->esami,e);
}

void printLibretto(Libretto l)
{
    printf("\nLibretto Studente\n");
    printf("Nome : %s \n",l->student.nome);
    printf("Cognome : %s \n",l->student.cognome);
    printf("Matricola : %d \n",l->student.matricola);
    printList(l->esami);
}

Esame serachEsame(Libretto l,char *nome_esame ,int *pos)
{   
    Esame t = initEsame(nome_esame,-1);
    return searchListItem(l->esami,t,pos);
}

int mediaEsami(Libretto l)
{
    List clone = cloneList(l->esami);
    Esame t;
    int somma = 0,counter = 0;
    while(!isEmpty(clone))
    {
        t = removeHead(clone);
        somma += getVoto(t);
        counter++;
    }

    return (somma/counter);
}
