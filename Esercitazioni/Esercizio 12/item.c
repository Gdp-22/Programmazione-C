#include <stdio.h>
#include <stdlib.h>
#include "item.h"


int eq(item a, item b) {
   return a == b;
}
int minore(item a,item b)
{
    if(a<b) return 1;
    return 0;
}

int maggiore(item a,item b)
{
    if(a>b) return 1;
    return 0;
}
int maggiore_uguale(item a,item b)
{
    if (a>=b) return 1;
    else return 0;
}
int minore_uguale(item a,item b)
{
    if (a<=b) return 1;
    else return 0;
}

void input_item(item *x) {
     printf("Inserisci item intero \n");
     scanf("%d",x);
} 

void output_item(item x) {
    printf("%d",x);
     
} 

void scambia_item(item *a,item *b) {
    item t;
    t=*a;
    *a=*b;
    *b=t;
}

