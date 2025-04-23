link : main.o item-int.o queue-array.o
	gcc main.o item-int.o queue-array.o -o queue.exe

main.o : 
	gcc -c main.c

item-int.o : 
	gcc -c item-int.c

queue-array.o :
	gcc -c queue-array.c

clean : 
	rm -rf *.o *.exe;