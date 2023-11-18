
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"
#define MAX_S 100

void *xmalloc(size_t size)
{
void *p = malloc(size);
if (p == NULL)
{
      printf("xmalloc failed");
      exit(-1);
}
return p;
}
struct miolibro{
      char titolo[100];
      char editore[100];
	int anno;
      float prezzo;   
       };

libro creaLibro(char *t, char* e, float p, int a){
      libro l;
      l=xmalloc(sizeof(struct miolibro));
	strcpy(l->titolo,t);
      strcpy(l->editore,e);
      l->anno=a;
      l->prezzo=p;
      return l;
      }

char* titolo(libro l)
{
     return l->titolo;
	 
}

char* editore(libro l)
{
      return l->editore;
	  
}

int anno(libro l)
{
      return l->anno;
}

float prezzo(libro l)
{
       return l->prezzo;
}

float sconto(libro l, float percentuale)
{
      return (percentuale*l->prezzo)/100;
      
}

void aggiorna (libro l, int anno)
{
	l->anno=anno;
	
}
