#include<stdio.h>
#include"utils.h"

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}