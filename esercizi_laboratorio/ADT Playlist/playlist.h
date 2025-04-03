#include "song.h"

typedef struct playlist *Playlist;


Playlist createPlayList(char * name);
void addSong(Playlist,Song);
void removeSong(Playlist,char *);
void sortPlayList(Playlist);
void printPlaylist(Playlist);

