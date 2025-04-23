link : item-string.o main.o stack.o
	gcc main.o item-string.o stack.o -o stack.exe

main.o : 
	gcc -c main.c

item-string.o : 
	gcc -c item-string.c
	
stack.o :
	gcc -c stack.c

clean : 
	rm -rf *.o *.exe