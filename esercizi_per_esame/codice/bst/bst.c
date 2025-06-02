#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BST newBST(){
	return NULL;
}

int isEmptyBST(BST node){
	if(node!=NULL)
		return 0;
	
	return 1;	
}


BST getLeft(BST t){
	if(isEmptyBST(t))
		return NULL;
	return t->left;
}

BST getRight(BST t){
	if(isEmptyBST(t))
		return NULL;
	return t->right;
}

Item getItem(BST t){
	if(isEmptyBST(t))
		return NULL;
	return t->value;
}
	
Item search(BST t, Item e){
	if (isEmptyBST(t))
		return NULL;
	
	int c=cmpItem(e,t->value);
	if (c==0)
		return t->value;
	else if (c<0)
		return search(t->left, e);
	else 
		return search(t->right, e);
}

Item min(BST t){
	if (isEmptyBST(t))
		return NULL;
	while(t->left!=NULL)
		t=t->left;
	
	return t->value;
}

Item max(BST t){
	if (isEmptyBST(t))
		return NULL;
	while(t->right!=NULL)
		t=t->right;
	
	return t->value;
}

void insertBST(BST *t, Item e){
	if (isEmptyBST(*t)){
		*t=malloc(sizeof(struct node));
		(*t)->value=e;
		(*t)->left=NULL;
		(*t)->right=NULL;
	}else{
		int c=cmpItem(e,(*t)->value);
		if (c<0)
			insertBST(&((*t)->left), e);
		else if (c>0)
			insertBST(&((*t)->right), e);
	}
}
Item deleteBST(BST *t, Item e){
	if (isEmptyBST(*t)){
		return NULL;
	}else{
		int c=cmpItem(e,(*t)->value);
		if (c<0)
			return deleteBST(&((*t)->left), e);
		else if (c>0)
			return deleteBST(&((*t)->right), e);
		else{
			if(isEmptyBST((*t)->left)){
				BST tempNode = *t;
				Item temp = (*t)->value;
				*t = (*t)->right;
				free(tempNode);
				return temp;
			}else if(isEmptyBST((*t)->right)){
				BST tempNode = *t;
				Item temp = (*t)->value;
				*t = (*t)->left;
				free(tempNode);
				return temp;
			}
			else{
				Item maxSx = max((*t)->left);
				Item temp = (*t)->value;
				(*t)->value = maxSx;
				deleteBST(&((*t)->left) , maxSx);
				return temp;
			}
		}	
	}
}


