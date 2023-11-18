#include "item.h"

typedef struct node *list;

list removeList(list l, int pos);

list insertList(list l, int pos,item val);

void elimina_nodo_successivo(list l);

void assegna (list l, item val);

list newList(void);

int emptyList(list l);

list consList(item val, list l);

list tailList(list l);

item getFirst (list l);

int sizeList (list l);

int posItem (list l, item val);

item getItem (list l, int pos);

list reverseList (list l);

void outputList (list l);
