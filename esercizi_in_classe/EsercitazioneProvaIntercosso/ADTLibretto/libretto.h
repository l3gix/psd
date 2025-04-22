#include "esame.h"

typedef struct libretto * Libretto;

Libretto newLibretto(char *nome_studente,char *congome_studente, int matricola);
void AddEsame(Libretto,Esame);
void printLibretto(Libretto);
Esame serachEsame(Libretto,char *nome_esame,int *pos);
int mediaEsami(Libretto);
