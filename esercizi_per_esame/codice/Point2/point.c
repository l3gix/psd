#include <stdlib.h>
#include <math.h>
#include "point.h"


struct point{
	float x;
	float y;
};

Punto creaPunto(float x, float y){
Punto p=malloc(sizeof(struct point));
p->x=x;
p->y=y;
return p;
}


float ascissa(Punto p){
	return p->x;
}

float ordinata(Punto p){
	return p->y;
}

float distanza(Punto p, Punto r){
	float Dx=p->x-r->x;
	float Dy=p->y-r->y;
	return sqrt((Dx*Dx)+(Dy*Dy));
	
}




