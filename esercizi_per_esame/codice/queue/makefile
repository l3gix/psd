link_array: item_int.o main.o queue_array.o
	gcc item_int.o main.o queue_array.o -o queue.exe

link_list: item_string.o main.o list.o queue_list.o
	gcc item_string.o main.o list.o queue_list.o -o queue.exe
	
queue_array.o:
	gcc -c queue_array.c
	
queue_list.o:
	gcc -c queue_list.c
	
list.o:
	gcc -c list.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
		
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe
