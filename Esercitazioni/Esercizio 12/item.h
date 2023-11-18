#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM 0

int eq(item x, item y);
int minore(item a, item b);
int maggiore(item a,item b);
int maggiore_uguale(item a,item b);
int minore_uguale(item a,item b);
void input_item(item *x); 
void output_item(item x);
void scambia_item(item *a,item *b);
