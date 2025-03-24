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
         *gg,
         *mm,
         *aa;
};


Item inputItem()
{
    Studente s = malloc(sizeof(struct student));
    s->nome = malloc(MAX*sizeof(char));
    s->cognome = malloc(MAX*sizeof(char));
    s->gg = malloc(MAX*sizeof(char));
    s->mm = malloc(MAX*sizeof(char));
    s->aa = malloc(MAX*sizeof(char));

    printf("\nCompilazione Studente \n");
    printf("Nome : ");
    scanf("%s",s->nome);
    printf("Cognome :");
    scanf("%s",s->cognome);
    printf("Inserimento la data di nasciata \n");
    printf("Giorno gg : ");
    scanf("%s",s->gg);
    printf("Mese mm : ");
    scanf("%s",s->mm);
    printf("Anno mm : ");
    scanf("%s",s->aa);

    return s;
}

void outputItem(Item item)
{
    Studente s = item;
    printf("\nDati Anagrafici Studenti \n");
    printf("Nome %s \nCognome %s \n",s->nome,s->cognome);
    printf("Data di Nasciata %s/%s/%s \n",s->gg,s->mm,s->aa);
}

int cmpItem(Item itemA, Item itemB)
{
    Studente a=itemA,b=itemB;
    if(strcmp(b->aa,a->aa) == 0)
    {
        if(strcmp(b->mm,a->mm) == 0)
        {
            return strcmp(b->gg,a->gg);
        }else return strcmp(b->mm,a->mm);

    }else return strcmp(b->aa,a->aa);


}