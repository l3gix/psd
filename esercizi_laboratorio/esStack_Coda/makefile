link_int: main.o list.o itemInt.o stack.o queue.o
	gcc main.o list.o stack.o itemInt.o queue.o -o array.out

link_string: main.o list.o stack.o itemString.o queue.o
	gcc main.o list.o stack.o itemString.o queue.o -o array.out

stack.o:
	gcc -c stack.c

itemInt.o:
	gcc -c itemInt.c

itemString.o:
	gcc -c itemString.c


list.o:
	gcc -c list.c

	
main.o:
	gcc -c main.c

queue.o:
	gcc -c queue.c

clean:
	rm -f *.o *.out
