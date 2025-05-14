#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "list.h"


// funzione per trovare il max tra due item 
Item maxItem(Item a,Item b)
{
	if (a == NULL) return b;
    if (b == NULL) return a;
	if(cmpItem(a,b) > 0) return a;
	else return b;
}

void evenLevelTail(List l, BTree t,int count );
void eveLevel(List l,BTree t);



// cera un nodo nell 'albero 
//search:
//	descrizione: dato un elemento lo cerca all'interno dell'albero, se è presenta ritorna vero se no ritorna falso
//	precondizione: l'elemento da cercare non deve essere nullo
//  postcondizione: se trova l'elemento ritorna 1, se no richiama dinuovo se stessa sul sottoalbero sinistro, se non lo trova 
//					si richiama sul sottoalbero destro, se non lo trova nemmeno li restituisce 0 se no restituisce 1.
int search(BTree t,Item e);

// cerca il max nodo 
// descrizione: funzione ricorsiva, chiamata dalla funzione MaxItem. Divide l'albero in destra e sinistra
// 			 e per ogni lato viene chiamata di nuovo MaxItem. 
// precondizione: 
// postcondizione: ritorna il contenuto più grande.
Item maxNode(BTree t);

//	precondizione: nessuna
//	postcondizione: se albero vuoto la lista sarà vuota. 
//					Se l'albero è pieno, inserisci in una lista il contenuto dei nodi che si trovano nei livelli pari
int cmpTree(BTree a,BTree b);

int main(void){
	
	BTree a,b,c,d,e;
	int x[5];
	x[0] = 1;
	e = buildTree(NULL,NULL,&x[0] );
	x[1] = 5;
	d = buildTree(NULL,NULL,&x[1]);
	x[2] = 9;
	c = buildTree(e,d,&x[2]);
	x[3] = 3;
	b = buildTree(NULL,NULL,&x[3]);
	x[4] = 7;
	a = buildTree(b,c,&x[4]);

	Item cerca; // item usato per cercare 
	printTree(a);
	printf("Inserisci il nodo da cercare : ");
	cerca = inputItem();
	if(search(a,cerca) == 1)printf("Nodo trovato \n");
	else printf("Nodo non trovato\n");

	printf("Il max node : \n");
	Item max = maxNode(a);
	outputItem(max);

	printf("\nconfronto tra due alberi \n");
	printf("%d",cmpTree(a,a));

	List pari = newList();
	eveLevel(pari,a);
	printf("\nElemenit con nodi di livello pari\n");
	printList(pari);
	printf("\n");
	
	
	//albero randomico
	
	BTree h = newRandomTree(4);
	printTree(h);
	printf("Inserisci il nodo da cercare : ");
	cerca = inputItem();
	if(search(h,cerca) == 1)printf("Nodo trovato \n");
	else printf("Nodo non trovato\n");

	printf("Il max node : \n");
	max = maxNode(h);
	outputItem(max);

	printf("\nconfronto tra due alberi \n");
	printf("%d",cmpTree(h,h));

	pari = newList();
	eveLevel(pari,h);
	printf("\nElemenit con nodi di livello pari\n");
	printList(pari);
	printf("\n");

	return 0;
}

int search(BTree t,Item e)
{	
	if(isEmptyTree(t)) return 0;

	if(cmpItem(getBTreeRoot(t),e) == 0) return 1;
	else 
	{
		return search(getLeft(t), e) || search(getRight(t), e);
	}
}

Item maxNode(BTree t)
{
	
	if(isEmptyTree(t)) return NULL;

    Item root = getBTreeRoot(t);
    Item leftMax = maxNode(getLeft(t));
    Item rightMax = maxNode(getRight(t));

    return maxItem(root, maxItem(leftMax, rightMax)); 
}


int cmpTree(BTree a,BTree b)
{
	if(isEmptyTree(a) || isEmptyTree(b)) return 0;

	return !(cmpItem(getBTreeRoot(a), getBTreeRoot(b)) &&
			cmpTree(getLeft(a), getLeft(b)) &&
			cmpTree(getRight(a), getRight(b)));
}



void evenLevelTail(List l, BTree t,int count )
{
	if(isEmptyTree(t)) return ;

	count += 1;
	evenLevelTail(l,getLeft(t),count);
	evenLevelTail(l,getRight(t),count);
	if(count % 2 == 0) addHead(l,getBTreeRoot(t));
}

void eveLevel(List l,BTree t)
{
	int count = 0;
	evenLevelTail(l,t,count);
}
