link : main.o utils.o vector.o
	gcc main.o utils.o vector.o -o vector.exe

driverEs1 : utils.o vector.o driver_somma.o
	gcc utils.o vector.o driver_somma.o -o driver_somma.exe
	./driver_somma.exe input_somma.txt oracle_somma.txt output_somma.txt

driverEs2 : utils.o vector.o driver_somma_v.o
	gcc utils.o vector.o driver_somma_v.o -o driver_somma_v.exe
	./driver_somma_v.exe input_somma_v.txt oracle_somma_v.txt output_somma_v.txt

driverEs3 : utils.o vector.o driver_prodotto.o
	gcc utils.o vector.o driver_prodotto.o -o driver_prodotto.exe
	./driver_prodotto.exe input_prodotto.txt oracle_prodotto.txt output_prodotto.txt

main.o :
	gcc -c main.c

utils.o :
	gcc -c utils.c

vector.o :
	gcc -c vector.c

driver_somma.o : 
	gcc -c driver_somma.c

driver_somma_v.o : 
	gcc -c driver_somma_v.c

driver_prodotto.o : 
	gcc -c driver_prodotto.c

clear :
	rm -f utils.o vector.o main.o vector.exe driver_somma.o driver_somma.exe driver_somma_v.o driver_somma_v.exe driver_prodotto.o driver_prodotto.exe
