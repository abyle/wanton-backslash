#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * This function creates a new singly linked node
 */

sllnode *newSLLNode(void) {
    sllnode *new = malloc(sizeof(sllnode));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->next = NULL;
    new->value = NULL;
    return new;
}


/*
 * The newSLL function takes a display function and returns a
 *     new singly linked list that will be able to display the contents.
 */

sll *newSLL(void (*d)(FILE *,void *)) {
    sll *list = malloc(sizeof(sll));
    if (list == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->display = d;
    return list;
}

/*
 * This function inserts a new node at the specified index.
 */

void insertSLL(sll *list,int index,void *value) {
    sllnode *new = newSLLNode();
    new->value = value;
    if (index == 0) {                         //Case if insert is happening at the head
        if (list->size == 0) {
            list->tail = new;
            list->head = new;
        }
        else {
            new->next = list->head;
            list->head = new;
        }
    }
    else if (index == list->size) {       //Case if insert is happening at the tail
        list->tail->next = new;
        list->tail = new;
    }
    else {                                    //Case if insert is happening in the middle
        int counter = 0;
        sllnode *current = list->head;
        while (counter < index - 1) {
            current = current->next;
            counter ++;
        }
        new->next = current->next;
        current->next = new;
    }
    
    list->size ++;
}


/*
 * This function removes a node at the specified index.
 */

void *removeSLL(sll *list,int index) {
    void *data = 0;
    if (list->size == 1) {
        data = list->head->value;
        list->head = NULL;
        list->tail = NULL;
    }
    else if (index == 0) {                    //Case if remove is at head
        data = list->head->value;
        list->head = list->head->next;
    }
    else {                                    //All removes not at head
        int counter = 0;
        sllnode *current = list->head;
        while (counter < index - 1) {         // -1 is because we need to edit the node BEFORE the removed node
            current = current->next;
            counter ++;
        }
        data = current->next->value;
        current->next = current->next->next;
        if (index == list->size - 1) {
            list->tail = current;
        }
    }
    list->size -= 1;
    return data; 
}


/*
 * This function appends one list to another and makes the donor empty.
 */

void unionSLL(sll *to,sll *from) {
    if (to->size == 0) {
        to->head = from->head;
        to->tail = from->tail;
    }
    else if (from->size == 0) {
    }
    else {
        to->tail->next = from->head;
        to->tail = from->tail;
    }
    to->size += from->size;
    from->size = 0;
    from->head = NULL;
    from->tail = NULL;
}


/*
 * This function returns the value of a specified node in the list.
 */

void *getSLL(sll *list,int index) {
    void *data = 0;
    if (index == 0) {
        data = list->head->value;
    }
    else if (index == list->size - 1) {
        data = list->tail->value;
    }
    else {
        int counter = 0;
        sllnode *temp = list->head;
        while (counter < index) {
            temp = temp->next;
            data = temp->value;
            counter ++;
        }
    }
    return data;
}


/*
 * This function returns the size of the list (number of values/nodes the list contains).
 */

int sizeSLL(sll *list) {
    return list->size;
}


/*
 * This function displays the list using the passed display function.
 */

void displaySLL(FILE *fp,sll *list) {
    if (list->size == 0) {
        fprintf(fp,"[]");
        return;
    }
    int counter = 0;
    sllnode *temp = list->head;
    fprintf(fp,"[");
    do {
        list->display(fp,temp->value);
        temp = temp->next;
        if (!(counter + 1 >= list->size)) {
            fprintf(fp,",");
        }
        counter ++;
    } while (counter < list->size);
    fprintf(fp,"]");
    return;
}
