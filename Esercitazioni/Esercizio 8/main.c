#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "item.h"

stack copia_stack(stack source);
void stampa_stack(stack s);
stack crea_stack();
stack stack_inverso(stack s);
void append(stack s1,stack s2);
stack append1(stack s1,stack s2);
void copia_s(stack dst,stack src);

int main()
{
 stack s;
 stack inverso;
 s=crea_stack();
 stack s1;
 s1=newStack();
 copia_s(s1,s);
 stampa_stack(s1);
 
return 0;


}
void copia_s(stack dst,stack src)
{
    stack temp;
    temp=newStack();
    item t;
    while(!emptyStack(src))
    {
        t=top(src);
        push(t,temp);
        pop(src);
    }

    while(!emptyStack(temp))
    {
        t=top(temp);
        push(t,src);
        push(t,dst);
        pop(temp);
    }
}


void append(stack s1, stack s2)
{
	stack temp1=newStack();
	temp1=copia_stack(s1);
	stack temp2=copia_stack(s2);//ora che abbiamo una copia degli stack possiamo svuotare lo stack s1 per poi riempirlo
	temp1=stack_inverso(temp1);//con l'ordine desiderato.Li invertiamo per poi inserirli nello stack con l'ordine esatto	
	temp2=stack_inverso(temp2); //svuotiamo completamente s1;
	while(!emptyStack(s1))
	{
		pop(s1);
		
	}
	while(!emptyStack(temp2))
	{
		push(top(temp2),s1);
		pop(temp2);
	}
	while(!emptyStack(temp1))
	{
		push(top(temp1),s1);
		pop(temp1);
	}
	free(temp1);
	free(temp2);
}

stack copia_stack(stack source){
stack dest;
dest=newStack();
 stack s;
 s=newStack();
 stack s1=newStack();
 while(!emptyStack(source))
 {
      push(top(source),s);
      pop(source);
 }
 while(!emptyStack(s)){
   push(top(s),dest);
   push(top(s),source);
   pop(s);
}
free(s);
free(s1);
return dest;
}

void stampa_stack(stack s)
{
     stack s1;
     s1=newStack();
     copia_s(s1,s);
     item t;
while(!emptyStack(s1)){
t=top(s1);
output_item(t);
pop(s1);
}
free(s1);
}

stack crea_stack()
{
item n;
 stack s;
 s=newStack();
 printf("Riempi lo stack e digita -1 per terminare\n");
 n=0;
 int i=0;
 while (i==0){ 
 input_item(&n);
 if(n==-1)
 {
    break;
 }
 push(n,s);
 }
 return s;
}

stack stack_inverso(stack s)
{
    stack s1;
    stack tmp;
    tmp=newStack(); 
    tmp=copia_stack(s);
    s1=newStack();
  if(s==NULL){
      return s;
  }
 item n;
 while(!emptyStack(tmp)){
     n=top(tmp);
     push(n,s1);
     pop(tmp);
 }
 free(tmp);
 return s1;
}
