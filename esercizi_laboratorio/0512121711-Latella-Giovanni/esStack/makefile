link_char : stackList.o main.o item_char.o list.o balance.o
	gcc stackList.o main.o item_char.o list.o balance.o -o stack.exe

link_int: stackList.o main.o item_int.o list.o
	gcc stackList.o list.o main.o item_int.o -o stack.exe


balance.o :
	gcc -c balance.c

stackList.o :
	gcc -c stackList.c

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c

item_char.o : 
	gcc -c item_char.c

list.o: 
	gcc -c list.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe