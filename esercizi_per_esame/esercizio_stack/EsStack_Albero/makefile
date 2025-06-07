link :  main.o list.o stackList.o item_int.o btree.o 
	gcc main.o list.o stackList.o item_int.o btree.o -o stack.exe

link_string : main.o list.o stackList.o item_string.o 
	gcc main.o list.o stackList.o item_string.o -o stack.exe

link_int :  main.o list.o stackList.o item_int.o btree.o 
	gcc main.o list.o stackList.o item_int.o btree.o -o stack.exe

main.o : 
	gcc -c main.c 

list.o : 
	gcc -c list.c 

item_int.o : 
	gcc -c item_int.c

item_string.o :
	gcc -c item_string.c 

stackList.o : 
	gcc -c stackList.c 

btree.o : 
	gcc -c btree.c

clean : 
	rm -rf *.o *.exe
