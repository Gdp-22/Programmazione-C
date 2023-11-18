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


void leggi_stringa(char *s)
{
int n;
fgets(s,MAX_S+1,stdin);
n=strlen(s);
if (s[n-1]=='\n'){
s[n-1]='\0';
}
}

char *alloca_stringa()
{
int n;
char *s,*s1;
s=(char *) xmalloc(sizeof(char)*(MAX_S+1));
leggi_stringa(s);
n=strlen(s)+1;  //troviamo lo spazio necessario aggiungendo il carattere terminatore
s1=(char *) xmalloc(n*sizeof(char));
strcpy(s1,s);
free(s);
return s1;
}


char minimo (char *uno)
{
	return uno[0];
}

char **crea_matrice()
{
	char **matrice;
	char *nome;
	char *cognome;
		matrice=(char **)xmalloc(sizeof(char*)*3);
		printf("Inserisci il nome \n");
		nome=alloca_stringa();
		printf("Inserisci il cognome \n");
		cognome=alloca_stringa();
int n;


		matrice[0]=nome;
		matrice[1]=cognome;
		
		return matrice;

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

char *incastona (char *s1,char *s2)
{
	//N.2
	int n1,n2,n3,n4;
	n1=strlen(s1);
	n2=strlen(s2);
	n3=0;
	n4=0;
	char *nuovas;
	
	int i;
	if (n1==n2)
	{
		printf("Le stringhe hanno stessa lunghezza \n");
		return NULL;
	}
	int j;
	if(n1>n2)
	{
		j=0;
		nuovas=(char *)xmalloc(sizeof(char)*n1);
		n3=n2/2;
		n4=n1/2;
		nuovas[n1]='\0';
		for(i=0;i<n4-n3;i++)
		{
			nuovas[i]=s1[i];
		}
		for(i=n4-n3;i<n2+(n4-n3);i++)
		{
			nuovas[i]=s2[j++];
		}
		for(i=n2+(n4-n3);i<n1;i++)
		{
			nuovas[i]=s1[i];
		}
	}
		if(n1<n2)
		{
		j=0;
		nuovas=(char *)xmalloc(sizeof(char)*n2);
		nuovas[n2]='\0';
	/*	n3=n2/2;
		n4=n1/2;
		for(i=0;i<n3-n4;i++)
		{
			nuovas[i]=s2[i];
		}
		for(i=n3-n4;i<n1+(n3-n4);i++)
		{
			nuovas[i]=s1[j++];
		}
		for(i=n1+(n4-n3);i<n2;i++)
		{
			nuovas[i]=s2[i];
		}
	}*/
		
		n3=n1/2;
		n4=n2/2;
		for(i=0;i<n4-n3;i++)
		{
			nuovas[i]=s2[i];
		}
		for(i=n4-n3;i<n2+(n4-n3);i++)
		{
			nuovas[i]=s1[j++];
		}
		for(i=n2+(n4-n3);i<n1;i++)
		{
			nuovas[i]=s2[i];
		}

}

	return nuovas;
}

void inverti(char **persona)
{
	//N.3
	char *app;
	int n1=strlen(persona[0])+1;
	app=(char *)xmalloc(sizeof(char)*n1);
	strcpy(app,persona[0]);
	strcpy(persona[0],persona[1]);
	strcpy(persona[1],app);
	free(app);
	app=NULL;
}

void crea(char **persona)
{
	//N.4
	char *terza;
	persona[2]=(char *)xmalloc(sizeof(char)*7);
	persona[2][6]='\0';
	int i,j;
	for(i=0;i<3;i++)
	{
		persona[2][i]=persona[0][i];
	}
	j=strlen(persona[1])-3;
	for(i=3;i<6;i++)
	{
		persona[2][i]=persona[1][j++];
	}
	
	
}


void ordina (char *stringa)
 {
 	//N.5
 	int i,j;
 
	char c;
 	for(i=0;i<strlen(stringa)-1;i++)
 	{
 		for(j=0;j<strlen(stringa)-1;j++){
		 
 		if(stringa[j]>stringa[j+1])	{
 		c=stringa[j];
 		stringa[j]=stringa[j+1];
 		stringa[j+1]=c;
	}
	 }
 	
	}
 }

int main (void){

char **persona;
persona=crea_matrice();
	
	printf("%s %s\n",persona[0],persona[1]);
char *mer;
mer=merge(persona[0],persona[1]);
printf("%s\n",mer);	
char *inca;
inca=incastona(persona[0],persona[1]);
printf("%s\n",inca);
char *inv;
inverti(persona);
printf("%s %s\n",persona[0],persona[1]);
crea(persona);
printf("%s \n",persona[2]);
ordina(persona[2]);
printf("%s \n",persona[2]);

	return 0;
}





