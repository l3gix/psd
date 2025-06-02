link : auto.o item_auto.o main.o list.o store_auto.o
	gcc auto.o item_auto.o main.o list.o store_auto.o -o conce.exe

list.o : 
	gcc -c list.c

store_auto.o :
	gcc -c store_auto.c

auto.o : 
	gcc -c auto.c

item_auto.o :
	gcc -c item_auto.c

main.o : 
	gcc -c main.c

clean : 
	rm -rf *.o *.exe
