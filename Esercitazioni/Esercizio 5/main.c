#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

#define MAX_S 100
#define BUFFSIZE 100


//Ricerca del libro piu vecchio
libro libropiuvecchio(libro* biblioteca,int n)
{
  int i;
  int k=0;
  int anno_minore=anno(biblioteca[0]);
  for(i=1;i<n;i++)
  {
    if(anno(biblioteca[i])<anno_minore)
    {
      k=1;
      anno_minore=anno(biblioteca[i]);
    }
  }
  return biblioteca[k];
}
//Ricerca del libro meno costoso
libro libromenocostoso(libro* biblioteca,int n)
{
  int i;
  int k=0;
  int prezzo_minore=prezzo(biblioteca[0]);
  for(i=1;i<n;i++)
  {
    if(prezzo(biblioteca[i])<prezzo_minore)
    {
      k=1;
      prezzo_minore=prezzo(biblioteca[i]);
    }
  }
  return biblioteca[k];
}
//Trova tutti i libri dell'editore X
libro* ricercaeditore(char* ed,int n,libro* biblioteca)
{
libro *libri_editore;
int i;
int k=0;
for(i=0;i<n;i++)
{
 if(strcmp(ed,editore(biblioteca[i]))==0)
 {
   k++;
 }
}
libri_editore=xmalloc(sizeof(libro)*k);
for(i=0;i<n;i++)
{
 if(strcmp(ed,editore(biblioteca[i]))==0)
 {
   libri_editore[i]=creaLibro(titolo(biblioteca[i]),editore(biblioteca[i]),prezzo(biblioteca[i]),anno(biblioteca[i]));
 }
}
return libri_editore;
}
//Ridurre del X% il costo dei libri dell'anno AAAA.
// questa funzione potrebbe restituire void oppure un intero
// che restiuisce 0 in caso tutto è andato correttamente
void scontalibri(libro* biblioteca, int an, float percentuale,int n)
{
  
 int i;
 for(i=0;i<n;i++){
   if (an==anno(biblioteca[i]))
   {
     float pr=prezzo(biblioteca[i])-sconto(biblioteca[i],percentuale);
     biblioteca[i]=creaLibro(titolo(biblioteca[i]),editore(biblioteca[i]),pr,an);
   }
 }

}

//Trova due libri con scarto di prezzo minore
libro* trovalibriprezzosimile(libro* biblioteca,int n)
{
  int k=0;
  int i,j;
  float differenza=prezzo(biblioteca[0])-prezzo(biblioteca[1]);
  libro *libri_prezzo_simile;
  libri_prezzo_simile=xmalloc(sizeof(libro)*2);
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(prezzo(biblioteca[i])-prezzo(biblioteca[j])<differenza)
      {
        differenza=(prezzo(biblioteca[i])-prezzo(biblioteca[j]));
        libri_prezzo_simile[0]=creaLibro(titolo(biblioteca[i]),editore(biblioteca[i]),prezzo(biblioteca[i]),anno(biblioteca[i]));
        libri_prezzo_simile[1]=creaLibro(titolo(biblioteca[j]),editore(biblioteca[j]),prezzo(biblioteca[j]),anno(biblioteca[j]));
      }
    }
  }
  return libri_prezzo_simile;



}



//Calcola il costo totale di tutti i libri dell'anno AAAA
float costototale(libro* biblioteca, int an,int n)
{
  float tot;
  tot=0;
  int i;
  for (i=0; i<n;i++)
  {
    if(anno(biblioteca[i])==an)
    {
      tot+=prezzo(biblioteca[i]);
    }
  }
  return tot;
}

//Elimina i libri dell'anno AAAA
void eliminaLibri(libro* biblioteca, int an,int n)
{
int i,j;
for(i=0;i<n;i++)
{
  if(anno(biblioteca[i])==an){ 
      
      for(j=i;j<n;j++)
      biblioteca[j]=creaLibro(titolo(biblioteca[j+1]),editore(biblioteca[j+1]),prezzo(biblioteca[j+1]),anno(biblioteca[j+1]));
       n--;
    }
  
}
}




char *leggi_stringa(char *s)
{
int n;

fgets(s,MAX_S+1,stdin);
n=strlen(s);
if (s[n-1]=='\n'){
s[n-1]='\0';
return s;
}
}

int main()
{

   int n=0;
   libro *biblioteca;
   char tit[100];
   char ed[50];
   char buffer[50];
   float pr;
   int an;
   
   
   printf("Dammi il numero di libri in biblioteca da inserire\n");
   scanf("%d", &n);
   
   biblioteca = malloc(sizeof(libro)*n);
  
   for (int i=0; i<n; i++){
       leggi_stringa(buffer);
	   printf("Titolo del libro :  ");
     leggi_stringa(tit);
      printf("\nEditore  :  ");
     leggi_stringa(ed);
     printf("\nAnno  :  ");
      scanf("%d",&an);
      printf("\nPrezzo :  ");
      scanf("%f",&pr);
      biblioteca[i]=creaLibro(tit,ed,pr,an);
    }
   
   //realizzare le varie funzioni dell'esercizio
  
  int a;
   printf("Il libro piu vecchio e :%s  \n",titolo(libropiuvecchio(biblioteca,n)));
    printf("anno per il costo totale\n");
  scanf("%d",&a);
   printf("il costo totale dei libri del %d e' :%f\n",a,(costototale(biblioteca,a,n)));
   
 	
  return 0;
}
