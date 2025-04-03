#include <stdio.h>
#include "item.h"
#include "playlist.h"


int main(void)
{
	int i;
	Playlist mypl = createPlayList("Rock");
	Song s;
	for(i = 0; i < 5 ; i++)
	{
		s = inputItem();
		addSong(mypl,s);
	}
	sortPlayList(mypl);

	printPlaylist(mypl);
}
