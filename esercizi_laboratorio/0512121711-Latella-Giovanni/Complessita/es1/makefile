link_int: utils.o array.o main.o item_int.o
	gcc utils.o array.o main.o item_int.o -o array.exe

link_string: utils.o array.o main.o item_string.o
	gcc utils.o array.o main.o item_string.o -o array.exe

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c
	
utils.o: 
	gcc -c utils.c
	
array.o: 
	gcc -c array.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe