#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "punto.h"
#include "item.h"


void inserisci_punti(queue q)
{
  printf("Inserisci i punti  (digita -1 per terminare l'inserimento)\n");
  int i=0;
  punto p;
  float x,y;
  while(i==0){
    scanf("%f",&x);
    if(x==-1)
    {
        break;
    } 
    scanf("%f",&y);
    if(y==-1)
    {
        break;
    } 
  p=creapunto(x,y);
  enqueue(p,q);

  }
}

void sottocode(queue q,queue q1, queue q2 ,queue q3, queue q4)
{
    q1=newQueue();
    q2=newQueue();
    q3=newQueue();
    q4=newQueue();
    float x,y;
    item p;
    while(!emptyQueue(q));
    p=dequeue(q);
    x=ascissa(p);
    y=ordinata(p);
    if(x>=0 && y>=0){
        enqueue(p,q1);
    }
    if(x<0 && y>=0){
        enqueue(p,q2);
    }
    if(x<0 && y<0){
        enqueue(p,q3);
    }
    if(x>=0 && y<0){
        enqueue(p,q4);
    }

}

queue concatenazione (queue q1, queue q2)
{
queue concat=newQueue();
item p;
while(!emptyQueue(q1) && !emptyQueue(q2)){
   if(emptyQueue(q1))
   {
       p=dequeue(q2);
       enqueue(p,concat);
   } else if(emptyQueue(q2))
   {
       p=dequeue(q1);
       enqueue(p,concat);
   } else {
       p=dequeue(q1);
       enqueue(p,concat);
       p=dequeue(q2);
       enqueue(p,concat);

   }
   return concat;
}

}
float spezzata (queue q)
{
 queue temp;
 float spez=0;
 item p1,p2;
 copia_queue(temp,q);
 while (!emptyQueue(temp)){
     p1=dequeue(temp);
     p2=dequeue(temp);
     spez+=distanza(p1,p2);

 }
 return spez;
}
int main()
{
queue q,q1,q2,q3,q4;
q=newQueue();
inserisci_punti(q);
//sottocode(q,q1,q2,q3,q4);
//queue c;
//c=concatenazione(concatenazione(q1,q2),concatenazione(q3,q4));

copia_queue(q1,q);
//printf("q\n");
//while(!emptyQueue(q)){
//stampa(dequeue(q));}
//printf("copia\n");
while(!emptyQueue(q1)){
stampa(dequeue(q1));}
}