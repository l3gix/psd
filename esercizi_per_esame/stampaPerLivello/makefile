link_int: btree.o main.o item_int.o stackList.o
	gcc btree.o main.o item_int.o -o btree.exe

link_string: btree.o main.o item_string.o list.o queue_list.o stackList.o
	gcc btree.o main.o item_string.o list.o queue_list.o stackList.o -o btree.exe

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
btree.o: 
	gcc -c btree.c
	
main.o:
	gcc -c main.c

list.o :
	gcc -c list.c

stackList.o : 
	gcc -c stackList.c

queue_list.o :
	gcc -c queue_list.c

clean:
	rm -f *.o *.exe