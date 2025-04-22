#include <stdio.h>
#include <stdlib.h>


int MCD(int a,int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int MCDr(int a,int b)
{
    if(b == 0)return a;
    else 
        MCDr(b, a % b);
}


int main(int argc,char *argv[])
{
    int a,b,mcd;
    if(argc != 3)
    {
        fprintf(stderr,"Errore : numeri di parametri");
        exit(EXIT_FAILURE);
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    mcd = MCD(a,b);

    printf("%d\n",mcd);


}
