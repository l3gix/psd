#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"


int sumBTree(BTree t)
{
	if(isEmptyTree(t)) return 0;
	else
	{
		Item x = getBTreeRoot(t);
		int *value = x;
		return *value + sumBTree(getLeft(t)) + sumBTree(getRight(t));
	}
}

int differentLeftRigh(BTree t)
{
	if(isEmptyTree(t)) return 0;
	else 
	{
		int left = sumBTree(getLeft(t));
		int righ = sumBTree(getRight(t));
		return left-righ;
	}
}

BTree addLeaft(BTree t,Item e)
{
	if(isEmptyTree(t)) return buildTree(newTree(),newTree(),e);

	if(isEmptyTree(getLeft(t)))
	{
		BTree left = buildTree(newTree(),newTree(),e);
		return buildTree(left,getRight(t),getBTreeRoot(t));
	}

	if(isEmptyTree(getRight(t)))
	{
		BTree righ = buildTree(newTree(),newTree(),e);
		return buildTree(getLeft(t),righ,getBTreeRoot(t));
	}

	BTree newleft = addLeaft(getLeft(t),e);
	if(newleft != getLeft(t)) return buildTree(newleft,getRight(t),getBTreeRoot(t));

	BTree newrigh = addLeaft(getRight(t),e);
	return	buildTree(getLeft(t),newrigh,getBTreeRoot(t));
}


BTree createBalanceTree(BTree unbalance,int diff)
{
	BTree balance;
	int added = 0;
	if(diff < 0)
	{
		diff *=-1;
		return buildTree(addLeaft(getLeft(unbalance),&diff),getRight(unbalance),getBTreeRoot(unbalance));
	}else 
	{
		return buildTree(getLeft(unbalance),addLeaft(getRight(unbalance),&diff),getBTreeRoot(unbalance));
	}

	return unbalance;
}

int main(void){
	
	

	
	return 0;
}