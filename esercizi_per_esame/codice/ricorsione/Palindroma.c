#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char* stringa)
{
	int i, j, l = strlen(stringa);
	for(i = 0, j=l-1; i<j; i++, j--)
	{
		if(stringa[i]!=stringa[j])
			return 0;
	}
	return 1;
}

int palindromaRicorsiva(char* stringa, int l)
{
	if(l <= 1)
		return 1;
	if(stringa[0]!=stringa[l-1])
		return 0;
	else
		return palindromaRicorsiva(stringa+1, l-2);
}

int palindromaRic(char *stringa) //Funzione di transizione
{
	return palindromaRicorsiva(stringa, strlen(stringa));
}

int main(int argc, char *argv[])
{
	int flag;
	if(argc!=2)
	{
		fprintf(stderr, "ERRORE: Numero di parametri errato\n");
		exit(EXIT_FAILURE);
	}
	flag = palindromaRic(argv[1]);
	if(flag)
		printf("la stringa e' palindroma\n");
	else
		printf("la stringa non e' palindroma\n");
}