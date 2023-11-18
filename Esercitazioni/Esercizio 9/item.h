#ifndef ITEM_H
#define ITEM_H
#include "punto.h"
typedef punto item;
#endif

#define NULLITEM 0

int eq(item x, item y);
void input_item(item *x); 
void output_item(item x);
