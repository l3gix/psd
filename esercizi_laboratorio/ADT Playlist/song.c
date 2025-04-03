#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "song.h"


struct song
{
    char *title;
    char *artist;
    int duration;
};



Song initSong(char *title,char *artist,int duration)
{
    Song s = malloc(sizeof(struct song));
    if(s == NULL)
    {
        fprintf(stderr,"errore allocazione Song");
        exit(0);
    }
    s->title = malloc((strlen(title)+1)*sizeof(char));
    if(s->title == NULL)
    {
        fprintf(stderr,"errore allocazione Song");
        exit(0);
    }
    s->artist = malloc((strlen(artist)+1)*sizeof(char));
    if( s->artist == NULL)
    {
        fprintf(stderr,"errore allocazione Song");
        exit(0);
    }
    strcpy(s->title,title);
    strcpy(s->artist,artist);
    s->duration = duration;
}


char *title(Song s)
{
    return s->title;
}
char *artist(Song s)
{
    return s->artist;
}

int duration(Song s)
{
    return s->duration;
}

