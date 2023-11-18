#include "item.h"

typedef struct node *list;

void elimina_nodo_successivo(list l);

void assegna (list l, item val);

list newList(void);

int emptyList(list l);

list consList(item val, list l);

list tailList(list l);

item getFirst (list l);

int sizeList (list l);

int posItem (list l, item val);

item getIte (list l, int pos);

list reverseList (list l);

void outputList (list l);
