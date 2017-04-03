#ifndef __PARSER_DEFINED__
#define __PARSER_DEFINED__

#include "queue.h"
#include <stdio.h>

queue *realParse(FILE *);
queue *intParse(FILE *);
queue *stringParse(FILE *);

#endif
