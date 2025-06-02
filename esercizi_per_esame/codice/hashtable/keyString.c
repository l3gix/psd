#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "key.h"
#define N 100

int equals(Key k1, Key k2){
    char *s1 = k1;
    char *s2 = k2;
    if(strcmp(s1, s2) == 0)
        return 1;
    else
        return 0;
}

int hashValue(Key k, int m){
    char *s = k;
    int h = 0, a = 128;
    for(; *s != '\0'; s++)
        h = (h * a + *s) % m;
    return h;
}

Key inputKey(){
    Key k = malloc(sizeof(char) * N);
    scanf("%s", k);
    return k;
}

void outputKey(Key k){
    char *s = k;
    printf("%s ", s);
}