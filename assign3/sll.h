#ifndef _SLL_INCLUDED_
#define _SLL_INCLUDED_

#include <stdio.h>

typedef struct sllnode{
    struct sllnode *next;
    void *value;
} sllnode;

typedef struct sll{
    sllnode *head;
    sllnode *tail;
    int size;
    void (*display)(FILE *,void *);
} sll;

sll *newSLL(void (*d)(FILE *,void *));
sllnode *newSLLNode(void);
void insertSLL(sll *items,int index,void *value);
void *removeSLL(sll *items,int index);
void unionSLL(sll *to,sll *from);
void *getSLL(sll *items,int index);
int sizeSLL(sll *items);
void displaySLL(FILE *,sll *items);

#endif
