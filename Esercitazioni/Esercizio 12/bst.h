// file BST.h
#include "item.h"
typedef struct node *BST;
// prototipi

item getItem(struct node *N);
void setItem(struct node *N, item el); 
BST newBST(void);
int emptyBST(BST T);
BST figlioSX(BST T);
BST figlioDX(BST T);
BST insert(BST T, item elem);
int contains(BST T, item elem);
BST deleteNode(BST T, item elem);
BST consBST(item val, BST sx, BST dx);