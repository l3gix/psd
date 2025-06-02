#include "item.h"
#include "entry.h"

int cmpItem(Item x, Item y){
    Entry e1 = x;
    Entry e2 = y;
    if(equals(getKey(e1), getKey(e2)))
        return 0;
    else
        return -1;
}