#include "item.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 10

typedef struct point
{
	int x;
	int y;
};



char **leggiFile(char *nomeFile){
    FILE *f=fopen(nomeFile,"r");
    char buffer[20];
    char *buf;
    int i=0;
    char **mappa=malloc(7*sizeof(char *));
    while(fgets(buffer,20,f)!=NULL){
        buf=malloc(20);
        strcpy(buf,buffer);
        mappa[i]=buf;
        i++;
    }
    fclose(f);
    return mappa;
}


void backtracking(char **c, int x, int y, int rows, int cols) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return; // Boundary check
    if (c[x][y] == '#' || c[x][y] == '.') return;         // Wall or already visited

    if (c[x][y] == 'S') {
        printf("sono arrivato\n");
        return;
    }

    // Mark visited
    c[x][y] = '.';

    // Recursive exploration
    backtracking(c, x - 1, y, rows, cols); // Up
    backtracking(c, x + 1, y, rows, cols); // Down
    backtracking(c, x, y - 1, rows, cols); // Left
    backtracking(c, x, y + 1, rows, cols); // Right
}

void stampaMatrice(char **matrice, int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");
    }
}

int main(){
	char **mappa=leggiFile("input.txt");

	stampaMatrice(mappa,7,7);
	backtracking(mappa,6,6,7,7);
	stampaMatrice(mappa,7,7);


	
	
}
