#include <stdlib.h>
#include "entry.h"
#include "key.h"
#include "list.h"
#include "hashtable.h"

struct hashtable{
    int size;
    List *entries;
};

HashTable newHashtable(int size){
    HashTable h=malloc(sizeof(struct hashtable));
    h->size=size;
    h->entries=malloc(sizeof(List)*size);
    for(int i=0; i<size; i++)
        h->entries[i]=newList();
    return h;
}

int insertHash(HashTable h, Entry e){
    int i=hashValue(getKey(e), h->size);
    addHead(h->entries[i], e);
    return 1;
}

Entry searchHash(HashTable h, Key k){
    int i=hashValue(k, h->size), pos=0;
    Entry e=newEntry(k, NULL);
    return searchListItem(h->entries[i], e, &pos);
}

Entry deleteHash(HashTable h, Key k){
    int i=hashValue(k, h->size);
    Entry e=newEntry(k, NULL);
    return removeListItem(h->entries[i], e);
}
