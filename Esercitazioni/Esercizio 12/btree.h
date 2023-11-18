/* file Btree.h
#include "item.h"

typedef struct node *Btree;

// prototipi
item getItem(Btree T);

void setItem(Btree T, item el);

Btree newBtree(void);

int emptyBtree(Btree T);

Btree figlioSX(Btree T);

Btree figlioDX(Btree T);

Btree consBtree(item val, Btree sx, Btree dx);

Btree getRoot (Btree T);*/
