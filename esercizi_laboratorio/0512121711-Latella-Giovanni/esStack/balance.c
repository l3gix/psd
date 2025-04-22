#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balance.h"
#include "item.h"
#include "stack.h"


int isOpen(char ch)
{
    if(ch == 123 || ch == 91 || ch == 40) return 1;
    
    return 0;
}

int isClose(char ch)
{
    if(ch == 125 || ch == 93 || ch == 41)return 1;

    return 0;
}

int isCorresponding(char ch1,char ch2)
{
    if(ch1 == 123 && ch2 == 125) return 1;
    if(ch1 == 91 && ch2 == 93) return 1;
    if(ch1 == 40 && ch2 == 41) return 1;


    return 0;
}

int isBalanced(char *exp)
{
    Stack s= newStack();
    Item t;
    int i;
    for(i == 0; i < strlen(exp) ; i++)
    {
        if(isOpen(exp[i]))
        {
            push(s,getItem(exp[i]));
        }

        if(isClose(exp[i]))
        {

            if(isEmptyStack(s)) return 0; // caso in cui lo stack sia vuoto e quindi è gia non e bilanciata 
            t = top(s);

            if(!isCorresponding(getChar(t),exp[i]))
            {
                return 0;
            }else 
            {
                //nel momento in cui trovo la parentesi la tolgo 
                pop(s);
            }
        }
    }

    //se sono rimaste parentesi dello stack 
    if(!isEmptyStack(s)) return 0;

    return 1;
}

