#ifndef ITEM_H
#define ITEM_H
#include "punto.h"
typedef punto item;
#endif

#define NULLITEM 0

item input_item();
// specifica : input_item()---> item
// pre:/ post:ritorna un puntatore a item riempito da valori inseriti da tastiera

void output_item(item p);
// specifica : output_item(item)---> void
// pre: Item non nullo 
// post: stampa l'item a schermo

int eq (item a, item b);
