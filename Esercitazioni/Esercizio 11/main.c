//ALBERI ESERCIZIO 10
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "item.h"
#define MAX 50

Btree  inpuBtree(void)
{
	Btree T1, T2;
	int ris;
	item el;
	printf("\nL'albero e' vuoto? (1/0): ");
	scanf("%d", &ris);
	if (ris)  return newBtree();
	printf("\nInserisci la radice: ");
	input_item(&el);
	printf ("costruisco il sottoalbero SX\n");
	T1 = inpuBtree();
	printf ("costruisco il sottoalbero DX\n");
	T2 = inpuBtree();
	return consBtree(el, T1, T2);
}



/*martino soluzione 
pre:i=0;
inputbtee(v[],int i,int newBtree()
if(i<n)
return consBtree(v[i],inputBtree(a,2*i+1,n),inputBtree(a,2*i+1,n));
else
return newBtree();
*/



//Precondizioni:la coda deve esistere    
//i=1
//conoscenza numero elementi 
Btree inputBtree(item v[],int i,int n)
{
   
    Btree T1,T2;
    printf("pos i: %d\n",i);
    printf("v[i] : %d\n",v[i]);
    if(i*2 >= n )
    {
        printf("arrivo qui0\n");
        return newBtree();
    }
    item t=v[i];
    int k=i;
    printf("arrivo qui creo figli\n");
    T1=inputBtree(v,i*2,n);
    T2=inputBtree(v,(k*2)+1,n);
    
    return consBtree(t,T1,T2);
   
}

void prinTree(Btree T)
{
    printf("\n");
    output_item(getItem(T));
}
void outputBtree(Btree t)
{
    if(t==NULL) return;
    prinTree(t);
    outputBtree(figlioSX(t));
    outputBtree(figlioDX(t));
}

int conta_foglie(Btree T)
{

if (T==NULL) return 0;
if(figlioSX(T)==NULL && figlioDX(T)==NULL) return 1;
if(figlioSX(T)!=NULL)
{
if(figlioDX(T)!=NULL)
{
    return conta_foglie(figlioSX(T))+conta_foglie(figlioDX(T));
}
else return conta_foglie(figlioSX(T));
}
else return conta_foglie(figlioDX(T));
}

Btree speculare(Btree spec,Btree T)
{
    if(T==NULL) return spec;
    if(figlioSX(T)==NULL &&figlioDX(T)==NULL)
    {
        return spec;
    }
    spec=consBtree(getItem(T),figlioDX(T),figlioSX(T));
    if(figlioDX(T)!=NULL)
    {
        return speculare(spec,figlioDX(T));
    }
    if(figlioSX(T)!=NULL)
    return speculare(spec,figlioSX(T));
}
Btree max (Btree T,int flag)
{
Btree mas;
if(T==NULL)
{
    return mas;
}
if(flag==0){
setItem(mas,getItem(T));
flag++;
return max(T,flag);
}
item m=getItem(T);
if(getItem(mas)<m)
{
    mas=T;
}
 mas=max(figlioSX(T),flag);
 mas=max(figlioDX(T),flag); 

}

Btree min (Btree T)
{



    
}


/*progetazzione(Btree T, intero k,int liv)

if (T==null)
return 0;

int i =0;
if figlio dx != null +1
if figlio sx != null +1
liv ++
return contanodi(figliosx)+contanodifiglio(dx)

*/



//Precondizioni flag=1
int uguali(Btree T1,Btree T2,int flag)
{
    if(flag==0)return 0;
    if(T1==NULL && T2==NULL) return 1;
    else if(getItem(T1)==getItem(T2))
    {
        return uguali(figlioSX(T1),figlioSX(T2),flag) && uguali(figlioDX(T1),figlioDX(T2),flag);
    } 
    else {
        flag=0 ;
        return 0;
        }
}

void aggiungiNodo(Btree T,item nodo)
{
Btree T1,T2;
if(T==NULL){
T=consBtree(nodo,T1=newBtree(),T2=newBtree());
return ;
}
if(figlioSX(T)==NULL){
    return aggiungiNodo(figlioSX(T),nodo);
}
if(figlioDX(T)==NULL){
    return aggiungiNodo(figlioDX(T),nodo);
}
return aggiungiNodo(figlioSX(T),nodo); ///? come scendo di livello?????

}
int main()
{
    int v[MAX];
    FILE *fp=fopen("interi.txt","rt");
    int i;
    for(i=1;i<8;i++)
    {
        fscanf(fp,"%d",&v[i]);
    }
      for(i=1;i<8;i++)
    {
        printf("%d\n",v[i]);
    }

    fclose(fp);
    Btree T=newBtree();
    Btree N=newBtree();
   // T=inputBtree(v,1,8);
   T=inpuBtree();
    int k=conta_foglie(T);
    printf("foglie :%d\n",k);
      outputBtree(T);
    N=speculare(N,T);
    //outputBtree(N);
    return 0;
}