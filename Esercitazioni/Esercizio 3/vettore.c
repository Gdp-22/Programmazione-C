// FILE:   vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

int confronta_array(int a[], int b[], int n) 
{  
 int i; int p;
 p=1;
 for(i=0;i<n;i++)
 {
 if(a[i]!=b[i]){
 p=0;}
 }
 return p;
}

void foutput_array(char *file_name, int a[], int n) 
{  
	int i;  
	FILE *fd; 	

    //aprire il file in scrittura
    fd=fopen(file_name,"w");
    //controllare che il file sia stato aperto correttamente
    if(!fd)
    {printf("errore apertura file");
    //e scrivere il contenuto (fprintf()) di a in fd
	for(i=0;i<n;i++)
	{
	fprintf(fd,"%d\n",a[i]);
	}
	
	// chiudere il file
	fclose(fd);
}
}

void finput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;

    //apertura file in lettura
	fd=fopen(file_name,"r");
	
	//Controllare se il file esiste e
	if(!fd)
    {printf("file inesistente");
	//leggere il contenuto (fscanf()) da scrivere in array a
	for(i=0;i<n;i++)
	{
	fscanf(fd,"%d",&a[i]);
	}
	
	//chiudere il file
	fclose(fd);
}
}
void ordina(int a[], int n)
{
   {
int i,j,app;
app=0;
for(i=0;i<n-1;i++)
{
	for(j=i+1;j<n;j++)
	{
	if(a[i]>a[j]){
	scambia(&a[i],&a[j]);
	}
	}
}
}
}
