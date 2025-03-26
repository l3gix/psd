typedef struct point *Punto;

Punto creaPunto(float x, float y);
float ascissa(Punto);
float ordinata(Punto);
float distanza(Punto , Punto );
void stampaPunto(Punto);

//funziona usata per riempieri l'array
void riempiPunto(Punto *p,int dim);



//Esercizio 1 
//funzione sposta punto
void spostaPunto(Punto , float ,float);

//Eercizio 2 
//funzione calcolo del centroide
Punto calcolaCentroide(Punto *p, int );

//Esercizio 3
//funzione caloca distanza minima e ritorna la coppia
int calcolaDistanzaMin(Punto *p,int ,float);

//Esercizio 4 
//funzione calcola la distanza massima
float calcolaDistanzaMas(Punto *p,int );
