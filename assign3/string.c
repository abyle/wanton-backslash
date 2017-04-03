#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "string.h"
#include <string.h>

extern void Fatal(char *,...);

void displayString(FILE *fp,void *v) {

    fprintf(fp,"\"%s\"",(char *) v);

}

int compareString(void *v,void *w) {
    
    return (strcmp((char *) v,((char *) w)));

}
