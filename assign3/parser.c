#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "scanner.h"
#include "real.h"
#include "integer.h"
#include "queue.h"
#include "string.h"

queue *realParse(FILE *fp) {
    queue *new = newQueue(displayReal);
    void *temp = 0;
    float myreal = 0;
    while (1) {
        myreal = readReal(fp);
        temp = newReal(myreal);
        //fprintf(stdout,"\nThe number is: "); displayReal(stdout,temp); fprintf(stdout,"\n");
        if (feof(fp) != 0) break;
        enqueue(new,temp);
    }
    //printf("The queue is: \n");
    //displayQueue(stdout,new);

    return new;
}

queue *intParse(FILE *fp) {
    queue *new = newQueue(displayInteger);
    void *temp = 0;
    int myint = 0;
    while (1) {
        myint = readInt(fp);
        temp = newInteger(myint);
        //fprintf(stdout,"\nThe number is: "); displayInteger(stdout,temp); fprintf(stdout,"\n");
        if (feof(fp) != 0) break;
        enqueue(new,temp);
    }
    //printf("The queue is: \n");
    //displayQueue(stdout,new);

    return new;
}

queue *stringParse(FILE *fp) {
    queue *new = newQueue(displayString);
    void *temp = 0;
    char *mystring = "";
    while (1) {
        mystring = readString(fp);
        temp = mystring;
        if (feof(fp) != 0) break;
        enqueue(new,temp);
    }
    return new;
}
