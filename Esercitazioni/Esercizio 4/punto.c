#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

typedef struct miopunto{
      float x;
      float y;
       };


punto creapunto(float x, float y){
     punto p;
     p->x = x; 
     p->y = y;
     return p;
      }
void copia_struttura (punto p1, punto p2)
{

p1->x = ascissa(p2);
p1->y = ordinata(p2);
}
float ascissa(punto p){
     return p->x;
      }

float ordinata(punto p){
      return p->y;
      }

float distanza(punto p1, punto p2){
     
    float radice=sqrtf((ascissa(p1)*ascissa(p2))+(ordinata(p1)*ordinata(p2)));
    
    return radice;
      }

void  stampa (punto p){
	printf("\n%f %f",ascissa(p),ordinata(p));
	
}


