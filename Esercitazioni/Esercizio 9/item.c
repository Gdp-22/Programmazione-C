#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "punto.h"


int eq(item a, item b) {
   return a == b;
}

void input_item(item *x) {
     
     scanf("%d",x);
} 

void output_item(item x) {
    printf("%d\n",x);
     
} 

