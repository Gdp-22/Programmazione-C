#include <stdio.h>
#include <stdlib.h>
#include "item.h"


int eq(item a, item b) {
   return a == b;
}

void input_item(item *x) {
     printf("Inserisci item intero \n");
     scanf("%d",x);
} 

void output_item(item x) {
    printf("%d\n",x);
     
} 

