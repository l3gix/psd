link_int: list.o main.o item_int.o stack_list.o
	gcc list.o main.o item_int.o stack_list.o -o stack.exe

link_string: list.o main.o item_string.o stack_list.o
	gcc list.o main.o item_string.o stack_list.o -o stack.exe

item_int.o : 
	gcc -c item_int.c

stack_list.o : 
	gcc -c stack_list.c

item_string.o : 
	gcc -c item_string.c
	
list.o: 
	gcc -c list.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe