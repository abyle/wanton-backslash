#ifndef _DLL_INCLUDED_
#define _DLL_INCLUDED_

#include <stdio.h>

typedef struct dllnode{
    struct dllnode *next;
    struct dllnode *before;
    void *value;
} dllnode;

typedef struct dll{
    dllnode *head;
    dllnode *tail;
    int size;
    void (*display)(FILE *,void *);
} dll;

dll *newDLL(void (*d)(FILE *,void *));
dllnode *newDLLNode(void);
void insertDLL(dll *items,int index,void *value);
void *removeDLL(dll *items,int index);
void unionDLL(dll *to,dll *from);
void *getDLL(dll *items,int index);
int sizeDLL(dll *items);
void displayDLL(FILE *,dll *items);

#endif
