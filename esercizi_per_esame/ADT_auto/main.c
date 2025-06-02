#include <stdio.h>
#include "item.h"
#include "auto.h"
#include "store_auto.h"

int main(void)
{
    Car c;
    c = inputItem();
    outputItem(c);

    Store s = newStore();
    addCar(s,c);
    printStore(s);

    return 0;
}