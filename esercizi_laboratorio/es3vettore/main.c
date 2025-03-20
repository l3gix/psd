#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"


int main(void)
{
    char stringa[100],//input stringa del primo array
         stringb[100]; // input stringa secondo array;
    int *a, // prima array
        *b, // secondo array
        *r, // array risulatante dalla concatenazione
        sizea = 0, // dimenzione array a
        sizeb = 0, // dimezione array b
        sizer = 0; // dimenzione array r

    printf("Inserisci la prima stringa \n");
    scanf("%[^\n]",stringa);
    getchar();


    printf("Inserisci la seconda stringa \n");
    scanf("%[^\n]",stringb);


    a = inputArrayDyn(&sizea,stringa);
    b = inputArrayDyn(&sizeb,stringb);
    r = concatenaVet(a,b,sizea,sizeb,&sizer);

    printf("Vetttore a\n");
    outputArray(a,sizea);
    printf("Vetttore b\n");
    outputArray(b,sizeb);
    printf("Vetttore r concatenato\n");
    outputArray(r,sizer);

    free(a);
    free(b);
    free(r);

    return 0;
}