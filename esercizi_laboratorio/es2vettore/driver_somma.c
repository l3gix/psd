#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

#define N 50

int main(int argc,char * argv[])
{
    FILE *f_input,*f_oracolo,*f_output;
    if(argc != 4)
    {
        fprintf(stderr,"Errori parametri : specificare i tre nomi dei file\n");
        exit(EXIT_FAILURE);
    }

    if((f_input = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"Errorre aperture fine in INPUT %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }


    if((f_oracolo = fopen(argv[2],"r")) == NULL)
    {
        fprintf(stderr,"Errorre aperture fine in ORACLE%s\n",argv[2]);
        exit(EXIT_FAILURE);
    }


    if((f_output = fopen(argv[3],"w") )== NULL)
    {
        fprintf(stderr,"Errorre aperture fine in OUTPUT%s\n",argv[3]);
        exit(EXIT_FAILURE);
    }

//printf("ciaooo");
    char line[N];//buffer per contenere i caratteri letti 
    int arr_input[N];//contera gli input dal file di input.txt , prima della virgola
    int n_input;//dimensione dell arr_inputa[]
    int r_oracolo;//contiene la linea di oracolo.txt

    int result = 0;
    int test;//usato per esprimere il risulato del testing
    int i,pos;


    for(i = 1 ; fgets(line,N,f_input ) != NULL ; i++)
    {
        
        n_input= inputArrayStr(arr_input,line,&pos);
        //printf("%d\n",n_input);

        fscanf(f_oracolo,"%d",&r_oracolo);
        //printf("%d\n",r_oracolo);

        result = sommaInArray(arr_input,n_input);

        printf("%d\n",result);
        if(r_oracolo == result)
        {
            test = 1;
        }else test = 0;

        fprintf(f_output,"Test case : %d : %d\n",i,test);

    }

    fclose(f_input);
    fclose(f_output),
    fclose(f_oracolo);

    return 0;
}