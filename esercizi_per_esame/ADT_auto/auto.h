typedef struct car *Car;

Car newCar(char *marca,char *modello,int anno_di_produzione,double prezzo);
char *getMarca(Car c);
char *getModello(Car c);
int getAnnoDiProduzione(Car c);
double getPrezzo(Car c);




