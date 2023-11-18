#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

//abs valore assoluto

list riempi_lista(list l)
{
 item n;
 printf("inserisci -1 per uscire");
 while(n!=-1)
 {
     input_item(&n);
     if(n==-1){
     break;
     }
     l=consList(n,l);
 }
return l;
}

int lunghezza_lista(list l)
{
    if(emptyList(l)){
        return 0;
    }
    list temp=newList();
    temp=tailList(l); 
    return 1 + lunghezza_lista(temp);
}

int lunghezza_iterando(list l){
    int count=0;
    list t=newList();
    t=l;
    while(!emptyList(t)){
        count++;
        t=tailList(t);
    }
    return count;
}
int quadrato (int n)
{
if (n==1)
{
    return 1;
}
return ((2*n)-1) + quadrato(n-1);

}
//precondizioni n<m
int mcd(int m, int n, int d) //ALGORITMO DI EUCLIDE
{
    if (n==d)
    {
        return d;
    }
    if(m>n)
    {
    return mcd(m-n,n,m-n);
    }
    if(m<n)
    {
        return mcd(n,d,n-d);
    }

}
int stringa_palindroma(char t[])
{
    t[strlen(t)]='\0';
      if(strlen(t)==0 || strlen(t)==1)
    {
        return 1;
    }
    int i;
    if(t[0]==' ')
    {
        for(i=0;i<strlen(t)-1;i++)
        {
        t[i]=t[i+1];
        }
        t[strlen(t)-1]='\0';
        return stringa_palindroma(t);
    }
    if(t[strlen(t)-1]==' ')
    {
        t[strlen(t)-1]='\0';
        return stringa_palindroma(t);
    }
    if(t[0]!=t[strlen(t)-1])
    {
        return 0;
    }
    for(i=0;i<strlen(t)-1;i++)
    {
        t[i]=t[i+1];
    }
    t[strlen(t)-2]='\0';
    return stringa_palindroma(t);

}
//n<m 
//la lista deve esistere
list sottolista_ricorsiva(list l,list t,int n,int m,int i)
{

if (i>m)
{
   return t;
}
if(i<n){
    l=tailList(l);
    i++;
    sottolista_ricorsiva(l,t,n,m,i);
}

t=consList(getFirst(l),t);
l=tailList(l);
i++;
return sottolista_ricorsiva(l,t,n,m,i);

}

int triangolo_di_tartaglia (int r,int c)
{
    if(c==1)
    {
        return 1;
    }
    if(r==c)
    {
        return 1;
    }
    return triangolo_di_tartaglia(r-1,c-1)+triangolo_di_tartaglia(r-1,c);

}
int main ()
{
list l=newList();
l=riempi_lista(l);
int k=0;
int i=0;
list t=newList();
t=sottolista_ricorsiva(l,t,1,2,0);
outputList(t);
//k=lunghezza_iterando(l);
//printf("%d\n",k);
//scanf("%d",&i);
//printf("%d\n",quadrato(25));
//printf("%d",mcd(494,130,k));
/*char *s;
s=malloc(sizeof(char)*101);
fgets(s,100,stdin);
s[strlen(s)-1]='\0';
printf("%d\n",stringa_palindroma(s));*/
//printf("%d",triangolo_di_tartaglia(5,2));

}
