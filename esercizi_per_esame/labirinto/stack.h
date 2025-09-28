// lo stack si può implementare anche come array, impostando un array e una variabile top che punta all'indice dell'elemento ultimo inserito. Metteremo questa variabile. La variabile parte da 0. Il problema è che l'array ha un massimo, perciò possiamo usare o gli array dinamici o limplementazione di stack come ADT. Per lo stack ADT useremo la lista e le sue funzioni//

#include "item.h"

typedef struct stack *Stack;

Stack newStack(); 
int isEmptyStack(Stack); 
int push(Stack, Item);
int pop(Stack);
Item top(Stack);
void printStack(Stack);

