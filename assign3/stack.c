#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*This function creates a new stack using a dll*/

stack *newStack(void (*d)(FILE *,void *)) {
    stack *new = malloc(sizeof(stack));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->stacklist = newDLL(d);
    new->stacklist->display = d;
    return new;
}

/*This function pushes a value to the top of a stack*/

void push(stack *items,void *value) {
    insertDLL(items->stacklist,0,value);
}

/*This function pops a value from the top of a stack*/

void *pop(stack *items) {
    void *data = 0;
    data = removeDLL(items->stacklist,0);
    return data;
}

/*This function shows the value at the top of the stack without removing it*/

void *peekStack(stack *items) {
    void *data = 0;
    data = getDLL(items->stacklist,0);
    return data;
}

/*This function returns the current size of the stack*/

int sizeStack(stack *items) {
    int back = 0;
    back = sizeDLL(items->stacklist);
    return back;
}

/*This function displays the current stack*/

void displayStack(FILE *fp,stack *items) {
    displayDLL(fp,items->stacklist);
}
