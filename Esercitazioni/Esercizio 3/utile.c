// Implementazione del Modulo: file utile.c
#include <stdio.h>
#include "utile.h"
/* commenti relativi alla progettazione 
e realizzazione della funzione scambia */
void scambia(int * x, int * y)
{	
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

