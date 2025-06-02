#include <stdio.h>
#include "hashtable.h"
#include "key.h"
#include "entry.h"
#include "item.h"

int main() {
    HashTable h=newHashtable(5);
    for(int i=0; i<4; i++){
        Key k=inputKey();
        Item e=inputItem();
        Entry j=newEntry(k, e);
        insertHash(h, j);
    }
    printf("Inserisci la chiave da cercare: \n");
    Key k=inputKey();

    Entry j=searchHash(h, k);

    if(j!=NULL){
        outputItem(getValue(j));
        printf("\n");
    }
    else
        printf("Valore non presente\n");

    return 0;
}
