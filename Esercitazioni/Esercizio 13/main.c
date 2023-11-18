//CODE A PRIORITA
#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"



int max(PQueue c)
{
    return getMax(c);
}

PQueue leggi_file_pq()
{
FILE *fp=fopen("int.txt","r");
if(fp==NULL)
exit (-1);
PQueue c=newPQ();
int i=0;
while(!feof(fp))
{
    fscanf(fp,"%d",&i);
    insert(c,i);
    printf("arrivo qui1");
}
fclose(fp);
return c;
}
void stampa_pq(PQueue c)
{
    PQueue temp=newPQ();

    while(!emptyPQ(c))
    {
        printf("\n%d",getMax(c));
        insert(temp,getMax(c));
        deleteMax(c);
    }
    while(!emptyPQ(temp))
    {
        insert(c,getMax(temp));
        deleteMax(temp);
    }
}
int main()
{
PQueue c=leggi_file_pq();
stampa_pq(c);
stampa_pq(c);
return 0;
}