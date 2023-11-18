#include <stdio.h>
#include <stdlib.h>

#include "item.h" 
#include "stack.h"
#include "list.h"

struct c_stack {
     list top;
};

stack newStack(void)
{
     stack s;
     s = malloc (sizeof(struct c_stack));
     if (s == NULL) 
	return NULL;

     s->top = newList();
     return s;
}

int emptyStack(stack s)
{
     return emptyList(s->top);
}

int push(item val, stack s)
{  
     s->top=insertList(s->top, 0, val);
     return 0;
}

int pop (stack s)
{   
    s->top=removeList(s->top, 0);
    return 0;
}


item top (stack s)
{
    return getFirst(s->top);
}
