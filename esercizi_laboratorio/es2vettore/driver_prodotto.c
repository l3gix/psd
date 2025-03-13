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


    char line[N];//buffer per contenere i caratteri letti 
    int arr_inputa[N];//contera gli input dal file di input.txt , prima della virgola
    int arr_inputb[N];//contera gli input deal file di input.txt , dopo della virgola
    int arr_oracle[N];//contie una linea del file ..oracolo.txt

    int n_inputa;//dimensione dell arr_inputa[]
    int n_inputb;//dimensione dell arr_inputb[]

    int r_oracolo;//contiene la linea di oracolo.txt
    int result = 0;
    int test; //usato per esprimere il risulato del testing
    int i,pos;

    //la funzione fgets() legge una linea stream immaginandola nel buffer puntato da line
    for(i = 1 ; fgets(line,N,f_input ) != NULL ; i++)
    {
    
        //inputArrayStr estrapola i dati dal buffer puntato da line 
        n_inputa = inputArrayStr(arr_inputa,line,&pos) ;

        n_inputb = inputArrayStr(arr_inputb,line,&pos) ;

        result = prodotto(arr_inputa,arr_inputb,n_inputa,n_inputb);
        //prendo dal file oracolo il valore della prima linea
        fscanf(f_oracolo,"%d",&r_oracolo);

        //compara vettore in input.txt e orcolo.txt
        if(result == r_oracolo) test = 1;
        else test = 0;

        //printf("%d\n",n_input);
        fprintf(f_output,"Test case : %d : %d\n",i,test);
        //scrive il risulato sul file 
    }

    fclose(f_input);
    fclose(f_output),
    fclose(f_oracolo);

    return 0;
}