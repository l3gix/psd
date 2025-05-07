link_int: btree.o main.o item_int.o queue_list.o list.o stack_list.o
	gcc btree.o main.o item_int.o queue_list.o list.o stack_list.o -o btree.exe

link_string: btree.o main.o item_string.o queue_list.o list.o stack_list.o
	gcc btree.o main.o item_string.o queue_list.o list.o stack_list.o -o btree.exe

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
queue_list.o :
	gcc -c queue_list.c

stack_list.o : 
	gcc -c stack_list.c 

list.o : 
	gcc -c list.c

btree.o: 
	gcc -c btree.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe