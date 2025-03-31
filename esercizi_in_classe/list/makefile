link_int:  list.o main.o item_int.o
	gcc list.o main.o item_int.o -o list.exe

link_string:  list.o main.o item_string.o
	gcc list.o main.o item_string.o -o list.exe

link_student: list.o main.o item_student.o
	gcc list.o main.o item_student.o -o list.exe

item_int.o : 
	gcc -c item_int.c

item_string.o : 
	gcc -c item_string.c

item_student.o :
	gcc -c item_student.c
	
list.o: 
	gcc -c list.c
	
main.o:
	gcc -c main.c

clean:
	rm -f *.o *.exe