link: main.o list.o stack.o itemString.o
    gcc main.o list.o stack.o itemString.o -o array.out

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

clean:
    rm -f *.o *.out