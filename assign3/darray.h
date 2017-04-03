#include <stdio.h>

#ifndef _DARRAY_INCLUDED_
#define _DARRAY_INCLUDED_

typedef struct DArray DArray;

extern DArray *newDArray(void (*display)(FILE *,void *));
extern void insertDArray(DArray *a,void *v);
extern void *removeDArray(DArray *a);
extern void *getDArray(DArray *a,int index);
extern void setDArray(DArray *a,int index,void *value);
extern int sizeDArray(DArray *a);
extern void displayDArray(FILE *,DArray *a);
#endif
