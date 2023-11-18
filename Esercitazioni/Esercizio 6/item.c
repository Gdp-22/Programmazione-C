#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

struct puntoitem{
       float x;
       float y;
};

int eq(item a, item b){
   if((a->x==b->x)&&(a->y==b->y)){
   return 1;}
   return 0;
}

item creaItem(){
    item p;
    p=(item)malloc(sizeof(item));
    if(p==NULL){
        return NULLITEM;
    }
    return p;
}

item input_item(item p,float a, float o){
 p->x=a;
 p->y=o;
 return p;
}
float ascissa(item p){
     float x1=p->x;
     return x1;
      }

float ordinata(item p){
     float y1=p->y;
     return y1;
      }

float distanza(item p1, item p2){
float pa1,pa2;
pa1=(ascissa(p1)-ascissa(p2));
pa2=(ordinata(p1)-ordinata(p2));
float radice=sqrt((pa1*pa1)+(pa2*pa2));
    
    return radice;
}
      

void output_item(item it){
     
     printf("\n%f %f",ascissa(it),ordinata(it));
}
