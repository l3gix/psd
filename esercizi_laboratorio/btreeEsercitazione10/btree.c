#include <stdlib.h>
#include <stdio.h>
#include "btree.h"
#include "string.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree(){
	return NULL;
}


int isEmptyTree(BTree node){
	if(node!=NULL)
		return 0;
	
	return 1;	
}

BTree buildTree(BTree t1, BTree t2, Item e){
	BTree t=malloc(sizeof(struct node));
	t->value=e;
	t->left=t1;
	t->right=t2;
	return t;
}



Item getBTreeRoot(BTree t){
	if(isEmptyTree(t))
		return NULL;
	return t->value;
}

BTree getLeft(BTree t){
	if(isEmptyTree(t))
		return NULL;
	return t->left;
}

BTree getRight(BTree t){
	if(isEmptyTree(t))
		return NULL;
	return t->right;
}

void preOrder(BTree t){
	if(!isEmptyTree(t)){
		outputItem(t->value);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(BTree t){
	if(!isEmptyTree(t)){
		postOrder(t->left);
		postOrder(t->right);
		outputItem(t->value);
	}
}

void inOrder(BTree t){
	if(!isEmptyTree(t)){
		inOrder(t->left);
		outputItem(t->value);
		inOrder(t->right);
	}	
}

// not in btree.h
int tta(BTree b, int p, char **a, int h, int *ml) {
	if(isEmptyTree(b)) return h;
	a[p] = itemToString(b->value);
	int l = strlen(a[p]);
	if(l > *ml) *ml = l;
	int lh = tta(b->left, 2 * p + 1, a, h + 1, ml);
	int rh = tta(b->right, 2 * p + 2, a, h + 1, ml);
	return lh > rh ? lh : rh;
}

// not in btree.h
void prt(char *a, int sp, char cfl, char cfr) {
	if(a) {
		int l = sp - strlen(a);
		int ll = l / 2, lr = (l + 1) / 2;
		if(cfl) {
			for(int k = ll / 2; k >= 0; k--) putchar(' ');
			for(int k = (ll + 1) / 2; k > 1; k--) putchar(cfl);
		} else {
			for(int k = ll; k > 0; k--) putchar(' ');
		}
		fputs(a, stdout);
		if(cfr) {
			for(int k = (lr + 1) / 2; k > 1; k--) putchar(cfr);
			for(int k = lr / 2; k >= 0; k--) putchar(' ');
		} else {
			for(int k = lr; k > 0; k--) putchar(' ');
		}
	} else {
		for(int k = sp; k > 0; k--) putchar(' ');
	}
}

void printTree(BTree btree) {
	char *a[1023] = {0};
	int ml = 0;
	int h = tta(btree, 0, a, 0, &ml);

	for(int i = 0; i < h; i++) {
		int sp = (ml + 1) * (1 << ((h - 1) - i)), s = (1 << i) - 1, e = (2 << i) - 1;
		if(i) {
			for(int j = s; j < e; j++) {
				prt(a[j] ? (j % 2 ? "/" : "\\") : " ", sp, 0, 0);
			}
			putchar('\n');
		}
		for(int j = s; j < e; j++) {
			if(i < h - 1)
				prt(a[j], sp, a[(2 * j) + 1] ? '_' : 0, a[(2 * j) + 2] ? '_' : 0);
			else
				prt(a[j], sp, 0, 0);
		}
		putchar('\n');
	}
}

BTree newRandomTree(int maxh) {
	if(maxh <= 0)
		return NULL;
	return buildTree(rand() % 3 == 0 ? NULL : newRandomTree(maxh - 1), rand() % 3 == 0 ? NULL : newRandomTree(maxh - 1), randomItem());
}