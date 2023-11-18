
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_S 60

void *xmalloc(size_t nbytes)
{
void *s;
s=malloc(nbytes);
if (!s) return NULL;
return s;
}

char *merge(char *nome,char *cognome)
{
	//N.1
	char *concat;
	int n;
	n=0;
	n=strlen(nome)+strlen(cognome)+1;
	concat=(char *)xmalloc(sizeof(char)*n);
	concat[n]='\0';

	int j;
	j=0;
	int i;
	for (i=0;i<n;i=i+2)
	{
		concat[i]=nome[j++];
		
	}
		j=0;
	for (i=1;i<n;i=i+2)
	{
		concat[i]=cognome[j++];
		
	}
	
	return concat;
}

int main(int argc, char**argv) {
	if(argc!=3)
		{
			fprintf(stderr,"\nNumero parametri non corretto");
		}
		char *concat;
		concat=merge(argv[1],argv[2]);
		printf("\nparametri passati :%d",argc);
		printf("\n%s\n",concat);
	return 0;
}


















