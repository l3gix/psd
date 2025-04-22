typedef void* Item;

Item inputItem();
Item inputItemFile(FILE *);
void outputItem(Item);
int cmpItem(Item, Item);