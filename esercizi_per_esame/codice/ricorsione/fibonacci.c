#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n ){
	if(n==0 || n==1) 
		return 1;
	else 
		return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciIter(int n){
	int f=1, f1=1, f2=1;
	
	for(int i=2; i<=n;i++){
		f= f1+f2;
		f1=f2;
		f2=f;
	}
	return f;
}

int main(int argc, char*argv[]){
	if(argc !=2){
		fprintf(stderr,"ERRORE: Numero di parametri errato!\n");
		exit(EXIT_FAILURE);
	}
	
	int n = atoi(argv[1]);
	
	printf("%d\n", fibonacciIter(n));
	return 0;
} 