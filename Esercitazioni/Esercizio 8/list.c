#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct node {
     item value;
     struct node *next;
};
list removeList (list l, int pos)
{     
      list l1, prec;    // puntatore al nodo da eliminare
      int i;

      if(pos == 0 && l != NULL) {       // eliminazione in posizione 0
            l1 = l;
            l = tailList(l);
            free(l1);
         }
       else {       // se non dobbiamo cancellare in posizione 0, scorriamo 
	          // la lista fino alla posizione precedente a quella del 
                       // nodo da eliminare
             i = 0;
             prec = l;         
             while (i < pos-1 && prec!= NULL) {   
                   prec = prec->next;
                   i++;
             }
             /* alla fine del ciclo, se prec != NULL allora prec->next punta al nodo da 
   eliminare. Se prec->next != NULL allora il nodo si può eliminare */

             if(prec != NULL && prec->next != NULL) { // short-circuit evaluation
                    l1 = prec->next;
                    prec->next = l1->next;
                    free(l1); 
               }
          }

       return l; 
}

list insertList (list l, int pos, item val)
{
      int i = 0;
      list l1, prec = l;   
      
      if(pos == 0)          // inserimento in posizione 0
            return consList(val, l);
      
/* se non dobbiamo inserire in posizione 0 scorriamo la lista 
fino alla posizione precedente a quella in cui inserire il nuovo nodo */

      while (i < pos-1 && prec!= NULL) {   
               prec = prec->next;
               i++;
      }

        if(prec == NULL)  // la lista di input ha meno di pos elementi
                return l; 
                /* se prec != NULL prec punta all’elemento di posizione pos-1 ed 
è possibile inserire il nuovo elemento in posizione pos */

          l1 = consList(val, prec->next);
          prec->next = l1;

            return l;  /* se abbiamo inserito in posizione > 0 l punta ancora
                               al primo elemento */                   
}


void elimina_nodo_successivo (list l)
{
     list successivo;
     successivo=tailList(l);
     l->next=successivo->next;
     successivo->value=NULLITEM;
     


     }
void assegna (list l,item val) {
l->value = val;
}
list newList(void)
{
return NULL;

}

int emptyList(list l)
{
     return l == NULL;

}
   list consList(item val, list l)
{
      struct node *nuovo;
      nuovo = malloc (sizeof(struct node));
      if (nuovo != NULL) {
     	nuovo->value = val;
      nuovo->next = l;
	l = nuovo; 
	}
      return l;
}
  

list tailList(list l)
{
           list temp;
      if (l != NULL)    
	temp = l->next;
      else 
             temp = NULL;
      return temp;

}

item getFirst (list l)
{
      item e;
      if(l != NULL)    
	e = l->value;
      else 
             e = NULLITEM;
      return e;

  
}

int sizeList (list l)
{
  int n=0;
      while (!emptyList(l)) // finché non raggiungiamo la fine della lista 
      {
           n++;    		// il primo elemento contribuisce al conteggio
           l = tailList(l);  	// continuiamo la visita degli elementi successivi
      }
      return n;
   
}

int posItem (list l, item val)
{
            int pos =0; // contatore di posizione
      int found =0;
      list k;
      k=l;
      while (!emptyList(k) && !found) {
          if (eq(getFirst(k), val))
              found =1;
          else {
              pos++; // incrementa il contatore di posizione
              k = tailList(k);  // continuiamo la visita degli elementi della lista
              }
        }    
  
      if(!found)
      	 pos = -1;  // se non trovato restituiamo come posizione -1
  	 
      return pos;

}

item getItem (list l, int pos)
{
   item e;
      int i =0;
     // prima scorriamo la lista fino alla posizione pos … se esiste
      while (i < pos && !emptyList(l)) { 
          i++;
          l = tailList(l);
      }

      if (!emptyList(l)) // se la lista ha almeno pos+1 elementi
          e = getFirst(l);  // elemento di posizione pos
      else e = NULLITEM;

      return e;
 
}

list reverseList (list l)
{
          list rev;
      item val;

      rev = newList();     

      while (!emptyList(l)) {
         val = getFirst(l);
         rev = consList(val, rev);  
         l = tailList(l);
       }

      return rev;

}

void outputList (list l)
{
      int i =0;
      item val; 

      while(!emptyList(l)) {
          val = getFirst(l);
          printf("Elemento di posizione %d: ", i);  
          output_item(val);  
          printf("\n");
          l = tailList(l);
          i++;
       } 

}
