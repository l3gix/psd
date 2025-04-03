link : main.o item_song.o list.o song.o playlist.o
	gcc main.o item_song.o list.o song.o playlist.o -o playlist.exe

item_song.o : 
	gcc -c item_song.c
	
list.o: 
	gcc -c list.c

song.o :
	gcc -c song.c
	
playlist.o :
	gcc -c playlist.c

main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe