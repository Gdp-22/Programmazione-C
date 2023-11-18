#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

int cerca_elemento (list l,item *val)
{
    int i=0;
    item ricerca;
    ricerca=*val;
    item temp;
    list k=l;
    while(!emptyList(k))
    {
        temp=getFirst(k);
        if(eq(temp,ricerca)==1){
            i=1;
        }
        k=tailList(k);
    }
    if(i==1){
        printf("elemento trovato\n");
        return 1;}
        else{
            printf("elemento non trovato\n");
            return 0;
        }
    }

    int pos_item (list l,item *ric){
 int i=-1;
 item val;
 val= *ric;
    item temp;
    list k=l;
    int c=0;
    while(!emptyList(k))
    {
        
         temp=getFirst(k);
        if(eq(temp,val)){
            i=c;
    }
    c++;
    k=tailList(k);
    }
  
    if(i>=0){
        printf("elemento trovato in posizione %d \n",i);
        return i;
    }
    else{
        printf("elemento non trovato \n ritorno -1");
        return i;
    }
    }

    void switch_a_coppie (list l)
    {
        item temp1,temp2;
        list nuova;
        list corrente,successivo;
        corrente=l;
        successivo=tailList(l);
        int i=0;
        while(i<(sizeList(l)-1)){
            temp1=getFirst(corrente);
            temp2=getFirst(successivo);
            assegna(corrente,temp2);
            assegna(successivo,temp1);
            i=i+2;
            successivo=tailList(successivo);
            successivo=tailList(successivo);
            corrente=tailList(corrente);
            corrente=tailList(corrente);

        }
        outputList(l);
    }

    void rimuovi_centrale (list l)
    {
        list t;
        t=l;
        int i=sizeList(t);
        i=(i/2)-1;
        int k=0;
        while(k<i){
            t=tailList(t);
            k++;
        }
        elimina_nodo_successivo(t);



    }

int main (){
    list l;
    l=newList();  
    int n;
    item x;
    printf("numero di interi da inserire nella lista\n");
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        input_item(&x);
        
        l=consList(x,l);
    }
    item k;
    int p;
    input_item(&k);
    switch_a_coppie(l);
    cerca_elemento(l,&k);
    pos_item(l,&k);
    rimuovi_centrale(l);
    outputList(l);
    return 0;
}
