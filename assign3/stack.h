#ifndef _STACK_INCLUDED_
#define _STACK_INCLUDED_

#include <stdio.h>
#include "dll.h"

typedef struct stack{
    dll *stacklist;
} stack;

stack *newStack(void (*d)(FILE *,void *));
void push(stack *items,void *value);
void *pop(stack *items);
void *peekStack(stack *items);
int sizeStack(stack *items);
void displayStack(FILE *,stack *items);


#endif

