#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "queue.h"

struct node {
     item value;
     struct node *next;
};

struct c_queue {
     struct node *head,*tail;
     int numel;
};

queue newQueue(void)
{
     struct c_queue *q;
     q = malloc (sizeof(struct c_queue));
     if (q == NULL) 
	return NULL;
     q->numel = 0;
     q->head = NULL;
     q->tail = NULL;
     return q;
} 

int emptyQueue(queue q)
{
     if (q==NULL)
            return -1;
     return q->numel == 0;
}

int enqueue(item val, queue q)
{
    if (q==NULL)
            return -1;

    struct node *nuovo;
    nuovo = malloc (sizeof(struct node));
    if (nuovo == NULL) 
	return 0;
    nuovo->value = val;
    nuovo->next= NULL;

    if(q->head==NULL)
         q->head = nuovo;
    else 
         q->tail->next= nuovo;   //inserimento in coda

    q->tail = nuovo;              // il nuovo nodo è la fine della coda
    (q->numel)++;
   return 1;     
}

item dequeue(queue q)
{
      if (q==NULL || q->numel == 0)
	return NULLITEM;

      item result;
      struct node *temp;
      temp= malloc (sizeof(struct node));
      temp = q->head;
      result = temp->value;
      q->head = q->head->next;
      free(temp);
      (q->numel)--;

      return result;
}

void copia_queue(queue dest, queue src){
     dest=newQueue();
    queue temp=newQueue();
    item p;
   while(!emptyQueue(src)){
        p=dequeue(src);
        enqueue(p,temp);
        enqueue(p,dest);
   }
   while(!emptyQueue(temp)){
        p=dequeue(temp);
        enqueue(p,src);
   }

}