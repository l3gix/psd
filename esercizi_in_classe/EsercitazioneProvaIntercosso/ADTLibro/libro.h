typedef struct libro *Libro;

Libro newLibro(char *autore,char *titolo,char *editore,int anno);
void StampaLibri(Libro *,int dim);
void OrdinaLibri(Libro *,int dim);

void swapLibro(Libro *a,Libro *b);


