#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

Item inputItem()
{
    char *s = malloc(sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "Errore di allocazione memoria\n");
        exit(EXIT_FAILURE);
    }

    scanf(" %c", s);
    return s;
}

void outputItem(Item item)
{
    char *s = item;
    printf("%c ", *s);
}

int cmpItem(Item itemA, Item itemB)
{
    char *sA = itemA;
    char *sB = itemB;
    return *sA == *sB;
}

Item getItem(char c)
{
    char *t = malloc(sizeof(char));
    if (t == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        exit(EXIT_FAILURE);
    }

    *t = c;
    return t;
}

char getChar(Item item)
{
    return *(char*)item;
}
