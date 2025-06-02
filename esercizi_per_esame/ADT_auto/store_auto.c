#include <stdlib.h>
#include "auto.h"
#include "list.h"
#include "store_auto.h"

struct store
{
    List list;
};

Store newStore()
{
    Store s = malloc(sizeof(struct store));
    s->list = newList();

    return s;
}

void addCar(Store s,Car c)
{
    addHead(s->list,c);
}

Car searchCar(Store s,char *marca)
{
    int i=0;
    Car temp = newCar(marca,"",0,0);
    return searchListItem(s->list,temp,&i);

}

void removeCar(Store s,Car c)
{
    removeListItem(s->list,c);
}

void printStore(Store s)
{
    printList(s->list);
}
