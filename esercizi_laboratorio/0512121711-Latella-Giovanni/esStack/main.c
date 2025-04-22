#include <stdio.h>
#include "balance.h"

#define MAX 30


int main(void){
	char exp[MAX];
	printf("Inserisci l'epressione : ");
	scanf("%[^\n]",exp);

	if(isBalanced(exp)) printf("E bilanciata\n");
	else printf("Non è bilancita\n");

	return 0;
}
