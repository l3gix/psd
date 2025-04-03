#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "playlist.h"
#include "list.h"
#include "song.h"


#define MAX 30

struct playlist
{
    char *nome;
    List songs;
};


Playlist createPlayList(char *name)
{
    Playlist p = malloc(sizeof(struct playlist));
    if(p == NULL )
    {
        fprintf(stderr,"errore allocazione playlist 1");
        exit(0);
    }
    p->nome = malloc((strlen(name)+1)*sizeof(char));
    if(p->nome == NULL)
    {
        fprintf(stderr,"errore allocazione playlist 2");
        exit(0);
    }

    p->songs = newList();
    strcpy(p->nome,name);
    
    return p;
}
void addSong(Playlist p,Song s)
{
    addHead(p->songs,s);
}

void removeSong(Playlist p,char *name)
{
    Song temp = initSong(name,"0",0);
    removeListItem(p->songs,temp);
}


void sortPlayList(Playlist l)
{
    sortList(l->songs);
}


void printPlaylist(Playlist p)
{
    printf("\nName playlist : %s\n",p->nome);
    printList(p->songs);
    printf("\n");

}