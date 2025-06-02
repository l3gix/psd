#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    int a[]={10,15,22,80,5,8,11,3,86};
    mergeSortIterativo(a,9);
    
    mergeSortStampe(8);
    outputArray(a,9);
}