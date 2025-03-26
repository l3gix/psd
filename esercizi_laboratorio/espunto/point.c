#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "point.h"


struct point{
	float x;
	float y;
};

Punto creaPunto(float x, float y)
{
	Punto p=malloc(sizeof(struct point));
	p->x=x;
	p->y=y;
	return p;
}


float ascissa(Punto p)
{
	return p->x;
}

float ordinata(Punto p)
{
	return p->y;
}

float distanza(Punto p, Punto r)
{
	float Dx=p->x-r->x;
	float Dy=p->y-r->y;
	return sqrt((Dx*Dx)+(Dy*Dy));
	
}

void stampaPunto(Punto p)
{
	printf("Punto\n");
	printf("X:%f\nY:%f\n",p->x,p->y);
}

void riempiPunto(Punto *p,int dim)
{
	float x,y;

	for(int i = 0; i < dim ; i++)
	{
		printf("\ninserisci in punto %d\n",i);
		printf("X : ");
		scanf("%f",&x);
		printf("Y : ");
		scanf("%f",&y);

		*(p + i) = creaPunto(x,y);
	}
}


//esercizio 1 
void spostaPunto(Punto p, float dx,float dy)
{
	p->x += dx;
	p->y += dy;
}

//Eercizio 2 
//funzione calcolo del centroide
Punto calcolaCentroide(Punto *p, int dim)
{
	
	float totX=0,totY=0;
	int i=0;
	for(;i < dim ; i++)
	{
		totX += p[i]->x;
		totY += p[i]->y;
	}


	return creaPunto(totX/dim,totY/dim);
}

int calcolaDistanzaMin(Punto *p,int dim,float d)
{
	int coppie= 0;
	for(int i = 0; i < dim ; i++)
	{
		for(int j = i+1 ; j < dim ; j++)
		{
			if(distanza(p[i],p[j]) < d)coppie++;
		}
	}

	return coppie;
}

//Esercizio 4 
//funzione calcola la distanza massima
float calcolaDistanzaMas(Punto *p,int dim)
{
	float massima = 0;
	for(int i = 0; i < dim ; i++)
	{
		for(int j = i+1 ; j < dim-1 ; j++)
		{
			if(distanza(p[i],p[j]) > massima) massima = distanza(p[i],p[j]);
		}
	}

	return massima;
}








