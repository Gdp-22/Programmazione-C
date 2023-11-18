#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

void *xmalloc(size_t nbytes)
{
void *s;
s=malloc(nbytes);
if (!s) return NULL;
return s;
}


punto *distanza_massima(punto *sequenza,int n)
{
int i=0;
int j=0;
punto *punti_max;
punti_max=xmalloc(sizeof(punto)*2);
float dist_max=0;
for(i=0;i<n;i++)
{
  for(j=i;j<n;j++){
    printf("\nDistanza :\n %.3f",distanza(sequenza[i],sequenza[j]));
     if (distanza(sequenza[i],sequenza[j])>dist_max){
       dist_max=distanza(sequenza[i],sequenza[j]);
       copia_struttura(punti_max[0],sequenza[i]);
       copia_struttura(punti_max[1],sequenza[j]);
     }
}
printf("I due punti con distanza massima sono \n punto1:");
stampa(punti_max[0]);
printf("\npunto 2:");
stampa(punti_max[1]);
printf("\nla loro distanza e' %.3f",dist_max);
return punti_max;
}

}
int main(int argc, char *argv[])
{
  
  int n = 0, m=0;
  float d = 0;
  float ascissa=0, ordinata=0;
  punto *p;

  //carica tutto l'input: coppie e distanza
    int k=0;
  k=argc -1;
  punto *array;
  array=(punto *)malloc(sizeof(punto)*k);
  int i;
  float x,y;
  int j=1;
  for(i=0; j<argc; i++)
  {
    array[i]=xmalloc(sizeof(punto));
    x=atof(argv[j]);
    k=j+1;
    y=atof(argv[k]);
    printf(" x %.2f  y %.2f",x,y);
    j+=2;
    array[i]=creapunto(x,y);
    n=i;
  }


  
      
  //calcola le distanze a coppie e controlla che siano minori di d
  printf("\ndammi la soglia (valore d) \n");
  scanf("%f",&d);
  k=0;
  for(i=0;i<n;i++) {
   for(j=i;j<n;j++){
      printf("\nDistanza :\n %.3f",distanza(array[i],array[j]));
     if (distanza(array[i],array[j])<d)
 {
    m++;
  }
   }
   
 
  }
   
  printf("Le coppie di punti a distanza minore di %.3f sono %d\n", d, m);
  punto *punti_massimi;
  punti_massimi=distanza_massima(array,n);

  system("PAUSE");	
  return 0;
}
