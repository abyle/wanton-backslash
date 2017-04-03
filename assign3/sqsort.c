#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "scanner.h"
#include "real.h"
#include "integer.h"
#include "queue.h"
#include "stack.h"
#include "parser.h"
#include "comparator.h"
#include "string.h"

void Fatal(char *fmt, ...) {
    va_list ap;
    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
}


int main(int argc,char *argv[]) {
    queue *inQ,*outQ,*switcher;
    stack *mystack;
    FILE *fp;

    if (argc <= 1) {
        printf("Please use one of the valid flags: -v -d -r OR -s\n");
        return 1;
    }
    else if (argc > 3) {
        printf("This function only accepts up to 2 arguments\n");
        return 1;
    }
    else if (argc == 2) {
        fp = stdin;
    }
    else {
        fp = fopen(argv[2],"r");
        if (fp == NULL) {
            printf("The file could not be opened for reading!\n\n");
            return 1;
        }
    }

    Comparator comp;
    Printer print;
    switch (argv[1][1]) {
        case 'v':   printf("Andrew M. Byle\n");
                    return 0;
        case 'd':   comp = intComparator;
                    print = displayInteger;
                    inQ = intParse(fp);
                    break;
        case 'r':   comp = realComparator;
                    print = displayReal;
                    inQ = realParse(fp);
                    break;
        case 's':   comp = stringComparator;
                    print = displayString;
                    inQ = stringParse(fp);
                    break;
        default:    printf("Flag %s unrecognized. Please use one of the valid flags: -v -d -r OR -s\n",argv[1]);
                    return 1;
    }

    displayQueue(stdout,inQ);
    printf("\n");
    outQ = newQueue(print);
    mystack = newStack(print);
    int isSorted;
    void *temp = 0,*smallest = 0;
    do {
        isSorted = 1;
        while (sizeQueue(inQ) != 0) {
            if ((sizeStack(mystack) != 0) && (comp(peekStack(mystack),peekQueue(inQ)) > 0)) {
                enqueue(outQ,pop(mystack));
            }
            else {
                temp = dequeue(inQ);
                if ((sizeQueue(inQ) == 0 ) || (comp(temp,peekQueue(inQ)) >= 0 )) {
                    if (sizeQueue(outQ) == 0) {
                        smallest = temp;
                    }
                    else if (comp(temp,smallest) > 0) {
                        isSorted = 0;
                    }
                    else {
                        smallest = temp;
                    }
                    enqueue(outQ,temp);
                }
                else if (comp(temp,peekQueue(inQ)) >= 0) {
                    enqueue(outQ,temp);
                }
                else {
                    push(mystack,temp);
                    //isSorted = 0;
                } 
            }
        }
        while (sizeStack(mystack) != 0) {
            enqueue(outQ,pop(mystack));
        }
        switcher = inQ;
        inQ = outQ;
        outQ = switcher;
        displayQueue(stdout,inQ);
        printf("\n");
    } while (isSorted == 0);

        
    return 0;
}
