#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
#include "btree.h"
#include "list.h"
#define MAX 50


int nodi_intervallo(int a,int b,BST T);
BST crea_bilanciato(item v[],int n,int i,BST A,int flag);

void prinTree(BST T)
{
    output_item(getItem(T));
}

void print2DBST(BST T,int space)
{
    // Base case
    if (T == NULL) return;
    space+=10;
    print2DBST(figlioDX(T),space);
    printf("\n");
    for(int i=10;i<space;i++)
        printf(" ");
    prinTree(T);
    print2DBST(figlioSX(T),space);
}
void printBST(BST T)
{
    print2DBST(T,0);
}

BST crea_bilanciato(item v[],int n,int i,BST A,int flag)
{
    printf("\ni=%d\n",i);
if(i>=n)
{
    return A;
}
if(i==1){
flag=1;
A=insert(A,v[n/2+n/4]);
}

if(i<n && flag==1){
    if(contains(A,v[i]))
    {
    return crea_bilanciato(v,n,i+1,A,flag);
    }
    else {
    A=insert(A,v[i]);
    return crea_bilanciato(v,n,i+1,A,flag);
 }
 }
 if(flag==0){
 A=insert(A,v[i]);
return crea_bilanciato(v,n,i/2,A,flag); }
}


int nodi_intervallo(int a,int b,BST T) 
{ 
if(emptyBST(T))
{
    return 0;
}

if(maggiore_uguale(getItem(T),a)&& minore_uguale(getItem(T),b))
{
    prinTree(T);
    printf("\n");
    return 1 + nodi_intervallo(a,b,figlioSX(T))+ nodi_intervallo(a,b,figlioDX(T));
}  

if(minore(getItem(T),a))
{
return nodi_intervallo(a,b,figlioDX(T));
}
if(maggiore(getItem(T),b))
{
    return nodi_intervallo(a,b,figlioSX(T));
}



}
void ordina_array(item v[],int n)
{
int j,i;
    for(i=1;i<n-1;i++)
    {
        for(j=i+1;j<n;j++){
            if(maggiore(v[i],v[j]))
            {
                scambia_item(&v[i],&v[j]);
            }
        }
    }
}
BST nodi_livello_k(BST T,int k,BST A)
{
    if(k==1)
    {
        A=insert(A,getItem(T));
        return A;
    }
    return nodi_livello_k(figlioSX(T),k-1,nodi_livello_k(figlioDX(T),k-1,A));
}
/*
int mediano(item U)
{

}
list nodi_albero(BST T,list l)
{
    if(emptyBST(T)){
        return newList();
    }
     l=consList(getItem(T),l);
     
     
     return nodi_albero(getItem(figlioSX(T)),l);

}*/
int main (){
int i;
int n;
i=1;n=8;
FILE *fp=fopen("albero.txt","r");
item v[MAX];
for(i=1;i<=n;i++)
{
fscanf(fp,"%d",&v[i]);
}
i=1;
//Btree T;
//T=newBtree();
//T=inputBtree(v,i,n);
//print2d(T);
//int k;
//k=isBST(T);
//printf("\n%d\n",k);
//k=15;
//k=nodi_intervallo(21,22,T);
ordina_array(v,n);
for(i=1;i<n;i++)
{
printf("%d\n",v[i]);
}
BST A=newBST();
BST T=newBST();
n=8;
A=crea_bilanciato(v,n,n/2,A,0);
printBST(A);printf("\n");
i=nodi_intervallo(1,6,A);
printf("numero =%d\n",i);
T=nodi_livello_k(A,2,T);
printBST(T);

return 0;
}