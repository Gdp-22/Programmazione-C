#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "punto.h"
// PROGETTAZIONE input_item()
//In questa funzione ci serviamo della funzione creapunto implementata nel modulo punto.c 
// inoltre per facilitare l'inserimento verifichiamo che le conversioni nella funzione scanf siano andate a buon fine
// in caso contrario restutiamo un item nullo.
item input_item()
{
 float x,y;
 scanf("%f",&x);
 scanf("%f",&y);
 item p;
 p=creapunto(x,y);
 
 return p;

}
// in questa funzione ci serviamo della funzione stampa implementata in punto.c per stampare un item
void output_item(item p)
{
stampa(p);
}

int eq(item a, item b) {
   float x1,x2,y1,y2;
   x1=ascissa(a);
   y1=ordinata(a);
   x2=ascissa(b);
   y2=ordinata(b);
   if(x1==x2 && y1==y2)
   {
       return 1;
   }
   return 0;

}
