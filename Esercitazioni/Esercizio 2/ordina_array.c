#include <stdlib.h>
#include <stdio.h>

void *xmalloc(size_t nbytes)
{
void *s;
s=malloc(nbytes);
if (!s) return NULL;
return s;
}

void ordina(int *array,int n)
{
int i,j,app;
app=0;
for(i=0;i<n-1;i++)
{
	for(j=i+1;j<n;j++)
	{
	if(array[i]>array[j]){
	app=array[i];
	array[i]=array[j];
	array[j]=app;
	}
	}
}
}
void stampa_array(int v[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d ",v[i]);
}
}

int main(int argc, char**argv) {

int d;
d=argc-1;

int *v=(int *)xmalloc(sizeof(int)*d);
int i;
int j=0;
for(i=0;i<d;i++)
{
j=i+1;
v[i]=atoi(argv[j]);

}

ordina(v,d);
stampa_array(v,d);
printf("\n");
return 0;
}





















