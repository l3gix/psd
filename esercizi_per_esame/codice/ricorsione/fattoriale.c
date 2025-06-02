#include <stdio.h>
#include <stdlib.h>

int fact(int n ){
	if(n==0) 
		return 1;
	else 
		return n*fact(n-1);
}

int factIter(int n){
	int f=1;
	
	for(int i=2; i<=n;i++){
		f*=i;
	}
	return f;
}

int main(int argc, char*argv[]){
	if(argc !=2){
		fprintf(stderr,"ERRORE: Numero di parametri errato!\n");
		exit(EXIT_FAILURE);
	}
	
	int n = atoi(argv[1]);
	
	printf("%d\n", factIter(n));
	return 0;
} 