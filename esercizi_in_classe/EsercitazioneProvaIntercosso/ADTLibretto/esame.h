#include <stdlib.h>

typedef struct esame *Esame;

Esame initEsame(char *nome_esame,int voto);
char *getNomeEsame(Esame);
int getVoto(Esame);