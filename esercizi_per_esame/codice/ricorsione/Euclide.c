#include <stdio.h>
#include <stdlib.h>

int MCD(int a, int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int MCDRicorsiva(int a, int b)
{
	if(b==0) 
		return a;
	else 
		return MCDRicorsiva(b, a%b);
}

int main(int argc, char *argv[])
{
	int a, b, m;
	if(argc!=3)
	{
		fprintf(stderr,"ERRORE: Numero di parametri errato\n");
		exit(EXIT_FAILURE);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	m = MCDRicorsiva(a,b);
	printf("%d\n", m);
}