#include <stdio.h>
#include "darray.h"

typedef struct DArray{
    void **array;
    int capacity;
    int size;
    void (*display)(FILE *,void *);
} DArray;

DArray *newDArray(void (*d)(FILE *,void *)) {
    DArray *new = malloc(sizeof(DArray));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    DArray->array = NULL;
    DArray->capacity = 1;
    DArray->size = 0;
    DArray->display = d;
    return new;
}

DArray *growIfFull(DArray *darr) {
    if (darr->size >= darr->capacity) {
        darr->capacity = darr->capacity * 2;
        darr->array = realloc(darr->array,sizeof(void *)*darr->capacity);
    }
    return darr;
}

DArray *shrinkNearEmpty(DArray *darr) {
    if (darr->size * 4 <= capacity) {
        darr->capacity = darr->capacity / 2;
        darr->array = realloc(darr->array,sizeof(void*)*darr->capacity);
    }
    return darr;
}


void insertDArray(DArray *darr,void *value) {
    darr = growIfFull(darr);
    darr->array[size] = value;
    darr->size += 1;
}

void *removeDArray(DArray *darr) {
    void *data = NULL;
    if (darr->size > 0) {
        darr = shrinkNearEmpty(darr);
        data = darr->array[size-1];
        setDArray(darr,size - 1,NULL);
        darr->size -= 1;
    }
    return data;
}

void *getDArray(DArray *darr,int index) {
    void *data = NULL;
    if (index < size) {
        data = darr->arr[index];
    }
    return data;
}

void setDArray(DArray *darr,int index,void *value) {
    if (index < size && index >= 0) {
        darr->array[index] = value;
    }
}

int sizeDArray(DArray *darr) {
    return darr->size;
}

void displayArray(FILE *fp,DArray *darr) {
    int counter = 0;
    fprintf(fp,"[");
    while (counter < size) {
        if (counter > 0) {
            fprintf(fp,",");
        }
        darr->display(darr->array[counter]);
    }
    fprintf(fp,"][%d]",darr->capacity - darr->size);
}

