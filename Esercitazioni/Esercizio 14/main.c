#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list riempi_lista(list l);
// precondizioni:La lista deve esistere     post: La lista viene riempita tramite inserimento da tastiera
int punti_minori_di_x (list l, float x);
// (list,float)---->integer
// pre:La lista deve esistere   post: la funzione resituisce il numero delle coppie di punti a distanza minore di x
void riordina(list l,char oridinata,char criterio);
//pre: nessuna post:la lista vieni ordinata a seconda dei criteri inseriti da tastiera
//(list,char,char)---->void
list sotto_lista(list l,int n,int m);
// precondizioni:la lista deve esistere 
// postcondizioni:la funzione restituisce una nuova lista contenente gli item
// dalla posizione n a m della vecchia lista, la lista originale invece conterrà gli elementi all'esterno dell'intervallo
// se i cirteri per la sottolista sono sbagliati la funzione restituisce la lista nulla. 
// (list,integer,integer)---->list
list inserisci_lista(list l, list k ,int m);
//pre: le liste devono esistere e m dev'essere minore della lunghezza della lisa originale
list riempi_da_file (list l);
int main ()
{
    list l;
    l=newList();
    l=riempi_da_file(l);
    //int c=punti_minori_di_x(l,55);
    //printf("i punti minori di 55 sono %d\n",c);
    //riordina(l,'y','>');
  /*  list l1=newList();
    l1=riempi_lista(l1);
    l=inserisci_lista(l,l1,3);
    printf("l prima\n");
     outputList(l);
    l1=sotto_lista(l,1,3);
    printf("l dopo\n");
    outputList(l);
    printf("L1\n");
    outputList(l1);
  */
 outputList(l);
   return 0;

}

list riempi_da_file(list l){
FILE *fp = fopen("punti.txt","rt");
item p;
float x,y;
int i=1;
while(!feof(fp)){
fscanf(fp,"%f",&x);
fscanf(fp,"%f",&y);
p=creapunto(x,y);
l=consList(p,l);
}
fclose(fp);
return l;

}
list riempi_lista(list l)
{
    
    item p;
    int i=0;
   while(i==0)
   {
      
       p=input_item();
       l=consList(p,l); //aggiungiamo elemento all'inizio della lista
       printf("Digita 0 per continuare e 1 per terminare l'inserimento\n");
        scanf("%d",&i);
   }
  return l;
}

// progettazione
/*Per contare il numero delle coppie minori di un valore x preso come parametro dobbiamo verificare scorrendo la lista
che la distanza fra i punti sia minore di x in questo caso incrementiamo il contatore.
Per scorrere la lista dobbiamo salvare l'indirizzo iniziale cosi da non cancellarla logicamente;
creiamo due puntatore alla lista che ci permettono di scorrerla.
Un puntatore punterà al nodo corrente un altro al successivo in modo tale che potremmo verificare la distanza punto
per punto
Infine ritorniamo il contatore.
   */
int punti_minori_di_x (list l, float x)
{
    list corrente,successivo;
    corrente=newList();
    successivo=newList();
    corrente=l;
    successivo=tailList(l);
    int n=sizeList(l);
    int c=0; //contatore
    int i=0;
    int j;
    item p1,p2;
    float d=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
        p1=getFirst(corrente);
        p2=getFirst(successivo);
        d=distanza(p1,p2);
        if(d<x)
        {
            c++;
        }
        
        successivo=tailList(successivo);//avanziamo di nodo
    }
    corrente=tailList(corrente);//avanziamo di nodo
    successivo=tailList(corrente);
    }
   return c;

}
/* Progettazione:
 Ricevi come parametro una lista di punti come parametro del
 Ricevi il valore per cui devi ordinare (x o y) e ricevi se devi ordinare in ordine crescente '<' o decrescente '>'
 crea lista temporanea per nodo corrente il valore
 crea lista temporenea per nodo successivo per poi poterli confrontare.
 se la lista successivo non è vuota fai
 il confronto che se è soddisfatto per i criteri specificati allora scambia gli item fra i nodi
 infine scorri le liste 
*/
void riordina(list l,char oridinata,char criterio)
{
    list corrente=newList();
    list successivo=newList();
    corrente=l;
    successivo=tailList(l);
    item p1,p2;
    switch (oridinata){
    case 'x':{
    if(criterio=='<'){
        printf("siamo nel caso x <");
     while(!emptyList(corrente))
    {
        while(!emptyList(successivo)){
        p1=getFirst(corrente);
        p2=getFirst(successivo);
        if(ascissa(p1)>ascissa(p2))
        {
            assegna(corrente,p2);
            assegna(successivo,p1);
        }
        
        successivo=tailList(successivo);
        }
        corrente=tailList(corrente);
        successivo=tailList(corrente);
    }
    }
    if(criterio=='>'){
        printf("siamo nel caso x >");
    while(!emptyList(corrente))
    {
        while(!emptyList(successivo)){
        p1=getFirst(corrente);
        p2=getFirst(successivo);
        if(ascissa(p1)<ascissa(p2))
        {
            assegna(corrente,p2);
            assegna(successivo,p1);
        }
        
        successivo=tailList(successivo);
    }   
    corrente=tailList(corrente);
    successivo=tailList(corrente);
    }
    }
    }

    case 'y': {
        if(criterio=='<'){
            printf("siamo nel caso y <");
    while(!emptyList(corrente))
    {
        while(!emptyList(successivo)){
        p1=getFirst(corrente);
        p2=getFirst(successivo);
        if(ordinata(p1)>ordinata(p2))
        {
            assegna(corrente,p2);
            assegna(successivo,p1);
        }
        
        successivo=tailList(successivo);
        }
        corrente=tailList(corrente);
        successivo=tailList(corrente);

    }
    }
     if(criterio=='>'){
         printf("siamo nel caso y >");
     while(!emptyList(corrente))
    {
        while(!emptyList(successivo)){
        p1=getFirst(corrente);
        p2=getFirst(successivo);
        if(ordinata(p1)<ordinata(p2))
        {
            assegna(corrente,p2);
            assegna(successivo,p1);
        }
        successivo=tailList(successivo);
        
        }
        corrente=tailList(corrente);
        successivo=tailList(corrente);
    }   
    }
    }
    }

}

//progettazione
/*  
Ricevi come parametro la lista
Controlla che n sia minore di m e che m sia minore del numero degli elementi della lista in caso contrario
restituisci la lista nulla.
scorri la lista fino ad arrivare alla posizione n-1 salva l'item e inseriscilo nella nuova sottolista
e poi elimina il nodo dalla lista originale questo fino ad arrivare alla posizione m
infine restituisci la nuova sottolista creata. 


*/
list sotto_lista(list l,int n,int m)
{
    list sotto_lista=newList();
    list temp=newList();
    if(!(n<m && m<sizeList(l)))
    {
        return sotto_lista;
    }
    int c=sizeList(l); //lunghezza lista
    int i;
    temp=l;
    int k=0; // salva l'indice
    for(i=0; i<n-1; i++)
    {
        temp=tailList(temp);
        k=i;
    }
    item p;
    list successivo=newList();
    
    while(k<m)
    {
        successivo=tailList(temp);
        p=getFirst(successivo);
        sotto_lista=consList(p,sotto_lista);
        elimina_nodo_successivo(temp);
        k++;
    }
 return sotto_lista;
}
/*PROGETTAZIONE
Grazie alla funzione insertList implementata nel modulo list.c possiamo inserire un nuovo nodo a una lista
nella posizione desiderata.
Cosi facendo possiamo scorrere la lista k finchè non è vuota ricavandone l'item e inserirlo nella lista l
in posizione m incrementando la m a ogni ciclo 
useremo una lista temporanea per k in modo tale che la lista k non venga cancellata logicamente 
 */
list inserisci_lista(list l, list k ,int m)
{
    list temp =newList();
    temp=k;
    item p;
    while(!emptyList(k))
    {
        p=getFirst(k);
        l=insertList(l,m,p);
        m++;
        k=tailList(k);
    }
    return l;
}