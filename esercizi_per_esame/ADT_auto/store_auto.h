#include "auto.h"
typedef struct store *Store;

Store newStore();
void addCar(Store s,Car );
Car searchCar(Store s,char *);
void removeCar(Store s,Car );
void printStore(Store s);
