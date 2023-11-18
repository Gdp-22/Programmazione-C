#include "btree.h"
#include <stdlib.h>
#include "item.h"
#include <stdio.h>

struct node {
     item value;
     struct node *left;
     struct node *right;
};


item getItem(struct node *N);
void setItem(struct node *N, item el); 

item getItem(struct node *N)
{
      if (N == NULL)  return NULLITEM;
      return N->value;
}

void setItem(struct node *N, item el)
{
     if (N==NULL) return;
     N->value = el;  // correttezza di =
}                    // dipende dal tipo item


Btree newBtree(void)
{
     return NULL;
}
 
int emptyBtree(Btree T)
{
     return T == NULL;
}


struct node *getRoot(Btree T)
{
     return T;
} 

Btree consBtree(item val, Btree sx, Btree dx)
{
      struct node *nuovo;
      nuovo = malloc (sizeof(struct node));
      if (nuovo != NULL) {
     	setItem(nuovo, val);
      	nuovo->left = sx;
 	nuovo->right = dx;
      }
      return nuovo;
}

Btree figlioSX(Btree T)
{
      if (T != NULL)    
	return  T->left;
      else 
             return NULL;
}

Btree figlioDX(Btree T)
{
      if (T != NULL)    
	return  T->right;
      else 
             return NULL;
}






