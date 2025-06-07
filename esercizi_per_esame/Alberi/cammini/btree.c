#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

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