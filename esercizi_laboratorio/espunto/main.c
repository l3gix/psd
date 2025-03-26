#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
	Punto p,*arrayP;
	float d;
	int n;//dimensione dell'array di punti
	p = creaPunto(10,20);
	stampaPunto(p);
	spostaPunto(p,3,3);
	printf("Punto spostato");
	stampaPunto(p);

	printf("Inserisci un dimensione per array di punti : ");
	scanf("%d",&n);

	arrayP = malloc(n * sizeof(Punto));
	riempiPunto(arrayP,n);

	printf("Calcolo del Centroide \n");
	stampaPunto(calcolaCentroide(arrayP,n));


	printf("Inserisci una distanza minima : ");
	scanf("%f",&d);
	printf("Calocolo delle coppie con questa distanza massima distanza \n");
	printf("%d \n",calcolaDistanzaMin(arrayP,n,d));

	printf("Calcolo delle distanza Massima dei punti \n");
	printf("%f \n",calcolaDistanzaMas(arrayP,n));




    return 0;
}
