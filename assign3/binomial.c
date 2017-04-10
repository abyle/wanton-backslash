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

-
