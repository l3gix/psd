link : main.o list.o esame.o item_esame.o libretto.o
	gcc main.o list.o esame.o item_esame.o libretto.o -o libretto.exe

main.o :
	gcc -c main.c

libretto.o :
	gcc -c libretto.c
list.o :
	gcc -c list.c

esame.o : 
	gcc -c esame.c

item_esame.o :
	gcc -c item_esame.c

clean : 
	rm -rf *.o *.exe
