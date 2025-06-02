link_int: bst.o main.o item_int.o
	gcc bst.o main.o item_int.o -o bst.exe

link_string: bst.o main.o item_string.o
	gcc bst.o main.o item_string.o -o bst.exe

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
bst.o: 
	gcc -c bst.c
	
main.o:
	gcc -c main.c

clean:
	del -f *.o *.exe