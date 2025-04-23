#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "queue.h"
#include "item.h"

void modCoda(Queue q, Item x)
{
    if (isEmptyQueue(q)) return;
    int size = 0;
    Queue temp = newQueue();

    while(!isEmptyQueue(q)) 
    {
        Item t = dequeue(q);
        enqueue(temp,t);
        size++;
    }

    for(int i = 0 ; i < size ; i++ )
    {
        Item a = dequeue(temp);
        int *val =(int *) a;
        if(compareItem(a,x) > 0)
        {
            (*val) = (*val) * 2;
        }else if(compareItem(a,x) < 0)
        {
            (*val) = (*val) / 2;
        }

        enqueue(q,val);
    }



}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
    FILE *fp = fopen("input.txt","r");
    char line[100];
    while(fgets(line,100,fp))
    {   
        Queue q = newQueue();
        int *param = NULL;
        char *buff;
        for(int i = 0,n;buff = malloc(100) ,sscanf(line + i,"%s%n",buff,&n) == 1; i += n)
        {
            if(strcmp(buff,"!") == 0)
            {
                Item x = randomItem();
                if(param == NULL)param = x;
                else 
                {
                    enqueue(q,x);
                }
            }
            if(param == NULL)
            {
                param = malloc(sizeof(int));
                *param = atoi(buff);
            }else 
            {
                int *val = malloc(sizeof(int));
                *val = atoi(buff);
                enqueue(q,val);
            }

        }

        modCoda(q,param);
        printQueue(q);
        printf("\n");
    }

}


