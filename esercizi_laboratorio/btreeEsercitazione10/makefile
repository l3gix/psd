link_int: btree.o main.o item_int.o list.o
	gcc btree.o main.o item_int.o list.o -o btree.exe

link_string: btree.o main.o item_string.o list.o
	gcc btree.o main.o item_string.o list.o -o btree.exe

list.o :
	gcc -c list.c

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
btree.o: 
	gcc -c btree.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe