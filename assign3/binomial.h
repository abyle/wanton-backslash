#include <stdio.h>
#include "darray.h"

#ifndef _BINOMIAL_INCLUDED_
#define _BINOMIAL_INCLUDED_

typedef struct BinomialNode BinomialNode;

BinomialNode *newBinomialNode(void (*display)(FILE *,void *),void *value);
void displayBinomialNode(FILE *fp,BinomialNode *n);

typedef struct Binomial Binomial;

Binomial *newBinomial(
        void (*d)(FILE *,void *),
        int (*c)(void *,void *),
        void (*u)(void *,BinomialNode *)
        );
BinomialNode *insertBinomial(Binomial *b,void *value);
int sizeBinomial(Binomial *b);
void deleteBinomial(Binomial *b,BinomialNode *n);
void decreaseKeyBinomial(Binomial *b,BinomialNode *n,void *value);
void *extractBinomial(Binomial *b);
void displayBinomial(FILE *fp,Binomial *b);

#endif
