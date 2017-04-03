#ifndef _QUEUE_INCLUDED_
#define _QUEUE_INCLUDED_

#include <stdio.h>
#include "sll.h"

typedef struct queue{
    sll *queuelist;
} queue;

queue *newQueue(void (*d)(FILE *,void *));
void enqueue(queue *items,void *value);
void *dequeue(queue *items);
void *peekQueue(queue *items);
int sizeQueue(queue *items);
void displayQueue(FILE *,queue *items);

#endif
