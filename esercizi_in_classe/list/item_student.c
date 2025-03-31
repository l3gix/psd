#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "student.h"

#define MAX 20
struct student
{
    char *nome,
         *cognome,
         *matricola;
};


Item inputItem()
{
    Studente s = malloc(sizeof(struct student));
    s->nome = malloc(MAX*sizeof(char));
    s->cognome = malloc(MAX*sizeof(char));
    s->matricola = malloc(MAX*sizeof(char));

    printf("\nCompilazione Studente \n");
    printf("Nome : ");
    scanf("%s",s->nome);
    printf("Cognome :");
    scanf("%s",s->cognome);
    printf("Inserisci la tua matricola : ");
    scanf("%s",s->matricola);


    return s;
}

void outputItem(Item item)
{
    Studente s = item;
    printf("\nDati Studente : \n");
    printf("Nome : %s,\nCognome : %s,\nMatricola : %s\n;",s->nome,s->cognome,s->matricola);
}


int cmpItem(Item itemA, Item itemB)
{
    Studente sA = itemA , 
             sB = itemB;
    
    return strcmp(sA->matricola,sB->matricola);
    
}