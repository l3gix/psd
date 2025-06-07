link_string : main.o list.o item_string.o queue_list.o 
	gcc main.o list.o item_string.o queue_list.o -o queue.exe

link_int : main.o list.o item_int.o queue_list.o 
	gcc main.o list.o item_int.o queue_list.o -o queue.exe

main.o : 
	gcc -c main.c

list.o :
	gcc -c list.c

item_string.o :
	gcc -c item_string.c

item_int.o : 
	gcc -c item_int.c 

queue_list.o : 
	gcc -c queue_list.c 

clean : 
	rm -rf *.o *.exe