link_int: btree.o main.o item_int.o
	gcc btree.o main.o item_int.o -o btree.exe

link_string: btree.o main.o item_string.o
	gcc btree.o main.o item_string.o -o btree.exe

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