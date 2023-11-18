#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "item.h"
#define MAX_S 50
int puntiminorix(list l)
{
float x;
int n=0;
printf("Dammi la soglia x per vedere i punti con distanza minore di x\n");
scanf("%f", &x);
float d=0;
int i=0;
int k=0;
int j=0;
list pu;
pu=l;
k=sizeList(l);

for(int i=0; i<k;i++){
	for(j=i+1;j<k;j++){
	d=distanza(getItem(pu,i),getItem(pu,j));
	printf("distanza :%f punto:%d punto:%d \n",d,i,j);
	if(d<x){
		n++;
	}
	
	}
}
printf("I PUNTI MINORI DI X sono %d \n",n);
return n;

}
char *leggi_stringa()
{
int n;
char *s;
fgets(s,MAX_S+1,stdin);
n=strlen(s);
s=malloc(sizeof(char)*n);
if (s[n-1]=='\n'){
s[n-1]='\0';
return s;
}
}

list distanza_massima(list l){
int i=0;
int k=0;
int j=0;
float max=0;
list l2;
l2=newList();
int pos1,pos2;
pos1=pos2=0;
l2=l;
list pu;
pu=newList();
float d=0;
k=sizeList(l);
for(i=0;i<k-1;i++){
	for(j=i+1;j<k;j++)
	{
		d=distanza(getItem(l2,i),getItem(l2,j));
		if(max<d){
		max=d;
		pos1=i;
		pos2=j;
		}

	}
	}
printf("la distanza massima e' %f dei punti:%d %d\n",max,pos1,pos2);
printf("punti distanza massima:(%f,%f),(%f,%f)\n",ascissa(getItem(l,pos1)),ordinata(getItem(l,pos1)),ascissa(getItem(l,pos2)),ordinata(getItem(l,pos2)));
pu=consList(getItem(l,pos1),pu);
pu=consList(getItem(l,pos2),pu);
return pu;
}
void riordina(list l,char criterio)
{
int i;
int j;
item temp;
temp=creaItem();
for(i=0;i<sizeList(l);i++){
	for(j=0;j<sizeList(l)-1;j++){
	 if(ascissa(getItem(l,i))>ascissa(getItem(l,j)))
	 {
		temp=input_item(getItem(l,i),ascissa(getItem(l,i)),ordinata(getItem(l,i)));
		
	 }
	}
}

}

int main (int argc, char *argv[]){
    int k=argc-1;
	list l1 =newList();
int i;
float x=0;
float y=0;
item punto;
for(i=1;i<argc;i=i+2){
punto=creaItem(punto);
x=atof(argv[i]);
y=atof(argv[i+1]);
punto=input_item(punto,x,y);
l1=consList(punto,l1);
}
list massimi;
//	i=puntiminorix(l1);
//massimi=distanza_massima(l1);
//outputList(massimi);

printf("decide per quale criterio ordinare la lista: ascissa , ordinata");
//char*cri =leggi_stringa();
//riordina(l1,cri);
	return 0;

}
