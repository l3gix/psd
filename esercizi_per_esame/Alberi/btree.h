#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);
void printTree(BTree);

void printTree(BTree btree);
void insertNodeLeft(BTree t,Item x);
int insertNodeIfDontHaveRighSon(BTree t,Item x);
int countNodi(BTree);
int countNodesIfRight(BTree);
Item searchNode(BTree,Item);

void deleteNode(BTree t,Item x);
void printHigh(BTree t,char *s);