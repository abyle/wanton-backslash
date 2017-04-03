#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*This function creates a new using a dll*/

queue *newQueue(void (*d)(FILE *,void *)) {
    queue *new = malloc(sizeof(queue));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->queuelist = newSLL(d);
    return new;
}

/*This function appends a value to the end of the queue*/

void enqueue(queue *items,void *value) {
    if (items->queuelist->size == 0) {
        insertSLL(items->queuelist,0,value);
    }
    else {
        insertSLL(items->queuelist,items->queuelist->size,value);
    }
}

/*This function returns a value from the front of a queue*/

void *dequeue(queue *items) {
    void *data = 0;
    data = removeSLL(items->queuelist,0);
    return data;
}

/*This function shows the value at the front of the queue without removing it*/

void *peekQueue(queue *items) {
    void *data = 0;
    data = getSLL(items->queuelist,0);
    return data;
}

/*This function returns the current size of the queue*/

int sizeQueue(queue *items) {
    int back = 0;
    back = sizeSLL(items->queuelist);
    return back;
}

/*This function displays the current queue*/

void displayQueue(FILE *fp,queue *items) {
    displaySLL(fp,items->queuelist);
}
