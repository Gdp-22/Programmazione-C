#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "list.h"


struct node {
     item value;
     struct node *next;
};

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
