link_int: stackList.o main.o item_int.o list.o
	gcc stackList.o list.o main.o item_int.o -o stack.exe

link_string: stackList.o main.o item_string.o list.o
	gcc stackList.o main.o item_string.o list.o -o stack.exe

stackArray.o :
	gcc -c stackArray.c 

stackList.o :
	gcc -c stackList.c

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
list.o: 
	gcc -c list.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe