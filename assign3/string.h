#include <stdio.h>

#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

typedef struct string
    {
    char *value;
    } string;

extern void displayString(FILE *,void *);
extern int compareString(void *,void *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
