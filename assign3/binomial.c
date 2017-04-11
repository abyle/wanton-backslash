#include "binomial.h"
#include <stdio.h>

/*
TO DO:

-CODE This entire (bastardized) class
-???
-Profit.
-Error: command 'Profit.' not permitted
-sudo Profit.
*/

typedef struct BinomialNode{
    struct BinomialNode *parent;
    DArray *children;
    void *value;
    void (*display)(FILE *,void *);
} BinomialNode;

BinomialNode *newBinomialNode(void (*display)(FILE *,void *),void *value) {
    BinomialNode *new = malloc(sizeof(BinomialNode));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->parent = NULL;
    new->children = NULL;
    new->value = value;
    new->display = display;
    return new;    
}

void displayBinomialNode(FILE *fp,BinomialNode *n) {
    n->display(fp,n->value);
    return;
}

typedef struct Binomial{
    DArray *rootlist;
    int (*compare)(void *,void *);
    void (*update)(void *,BinomialNode *);
    void (*display)(FILE *,void *);
    BinomialNode *extreme;
    int size;
} Binomial;

Binomial *newBinomial(
        void (*d)(FILE *,void *),
        int (*c)(void *,void *),
        void (*u)(void *,BinomialNode *)
        ) {
    Binomial *new = malloc(sizeof(Binomial));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->rootlist = newDArray(new->display);
    new->compare = c;
    new->display = d;
    new->update = u;
    new->extreme = NULL;
    new->size = 0;
    return new;
}


