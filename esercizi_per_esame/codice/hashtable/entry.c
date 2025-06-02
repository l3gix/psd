#include <stdlib.h>
#include "entry.h"
#include "key.h"
#include "item.h"

struct entry{
  Key key;
  Item value;
};

Entry newEntry(Key k, Item x){
  Entry e = malloc(sizeof(struct entry));
  e->key = k;
  e->value = x;
  return e;
}

Key getKey(Entry e){
  if(e != NULL)
    return e->key;
  return NULL;
}

Item getValue(Entry e){
  if(e != NULL)
    return e->value;
  return NULL;
}

