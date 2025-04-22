#include <stdio.h>
#include <stdlib.h>


int isPalindroma(char *s,int end,int start)
{
    if(start >= end ) return 1;

    if(s[start] != s[end]) return 0;

    return isPalindroma(s,end-1,start+1);
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Errore : numeri di parametri");
        exit(EXIT_FAILURE);
    }



}

