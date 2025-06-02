#include <stdio.h>
#include "point.h"

int main()
{
	float dis, x, y;
	Punto pu, ru;
	printf("Inserire le cordinate del primo punto: ");
	scanf("%f %f", &x,&y);
	pu=creaPunto(x, y);
	printf("Inserire le cordinate del secondo punto: ");
	scanf("%f %f", &x,&y);
	ru=creaPunto(x, y);
	dis=distanza(pu, ru);
	printf("Distanza tra i due punti: %.1f \n", dis);
    return 0;
}
