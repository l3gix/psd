#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "song.h"


#define MAX 30

Item inputItem()
{
    Song s;
    char artista[MAX],titolo[MAX];
    int durata;
    printf("\nTitolo Canzone : ");
    scanf("%s",titolo);
    printf("\nNome Artista : ");
    scanf("%s",artista);
    printf("\nDurata : ");
    scanf("%d",&durata);

    s = initSong(titolo,artista,durata);

    return s;
}

void outputItem(Item item)
{
    Song s = item;
    printf("Titolo : %s\n",title(s));
    printf("Artista : %s\n",artist(s));
    printf("Dutata %d\n",duration(s));

}

int cmpItem(Item itemA, Item itemB)
{
    Song a=itemA,b=itemB;

    return strcmp(title(a),title(b));
}


