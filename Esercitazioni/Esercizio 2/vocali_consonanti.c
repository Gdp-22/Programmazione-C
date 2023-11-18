#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_S 60
void *xmalloc(size_t nbytes)
{
void *s;
s=malloc(nbytes);
if (!s) return NULL;
return s;
}

int vocale (char a)
{
if (a=='a'|| a =='A' ||a=='e'|| a =='e' ||a=='i'|| a =='I' ||a=='o'|| a =='O' ||a=='u'|| a =='U' )
{
return 1;
	}
	return 0;
}
void vocali_consonanti (char *stringa)
{
int i;
char *sv=(char *)xmalloc(sizeof(char)*strlen(stringa));
char *sc=(char *)xmalloc(sizeof(char)*strlen(stringa));
int n=strlen(stringa);
int j=0;
int k=0;
for(i=0;i<n;i++)
{
if(vocale(stringa[i])==1)
{
sv[j]=stringa[i];
j++;
}
else {
sc[k]=stringa[i];
k++;
}
sv[j]='\0';
sc[k]='\0';
}
printf("vocali: %s  consonanti: %s \n",sv,sc);



}
int main (int argc,char **argv)
{
if (argc!=2)
{
printf("Parametri non corretti");
}
vocali_consonanti(argv[1]);

}



