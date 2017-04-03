#include <stdlib.h>
#include <stdio.h>
#include "comparator.h"
#include "integer.h"
#include "real.h"
#include "string.h"
#include <string.h>

int intComparator(void *x,void *y) {
    if (((integer *) x)->value - ((integer *) y)->value > 0) return 1;
    else if (((integer *) x)->value - ((integer *) y)->value < 0) return -1;
    else return 0;
}

int realComparator(void *x,void *y) {
    if (((real *) x)->value - ((real *) y)->value > 0) return 1;
    else if (((real *) x)->value - ((real *) y)->value < 0) return -1;
    else return 0;
}

int stringComparator(void *x,void *y) {
    if (strcmp((char *) x,(char *) y) > 0) return 1;
    else if(strcmp((char *) x,(char *) y) < 0) return -1;
    else return 0;
}
