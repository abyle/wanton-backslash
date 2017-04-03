#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * This function creates a new singly linked node
 */

dllnode *newDLLNode(void) {
    dllnode *new = malloc(sizeof(dllnode));
    if (new == 0) {
        fprintf(stderr,"Out of Memory");
        exit(-1);
    }
    new->next = NULL;
    new->before = NULL;
    new->value = NULL;
    return new;
}


/*
 * The newDLL function takes a display function and returns a
 *     new doubly linked list that will be able to display the contents.
 */

dll *newDLL(void (*d)(FILE *,void *)) {
    dll *list = malloc(sizeof(dll));
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
 * The insertDLL function inserts a new node at the specified index.
 */

void insertDLL(dll *list,int index,void *value) {
    dllnode *new = newDLLNode();
    new->value = value;
    if (index == 0) {                         //Case if insert is happening at the head
         
        if (list->size == 0) {
            list->head = new;
            list->tail = new;
        }
        else {
            new->next = list->head;
            list->head->before = new;
            list->head = new;
        }
    }
    else if (index == list->size) {       //Case if insert is happening at the tail
        list->tail->next = new;
        new->before = list->tail;
        list->tail = new;
    }
    else {                                    //Case if insert is happening in the middle
        int counter = 0;
        dllnode *current = list->head;
        while (counter < index - 1) {
            current = current->next;
            counter ++;
        }
        new->next = current->next;
        new->next->before = new;
        current->next = new;
        new->before = current;
    }
    list->size ++;
}


/*
 * The removeDLL function removes a node at a specified index and returns the value stored there.
 */

void *removeDLL(dll *list,int index) {
    void *data = 0;
    if (list->size == 1) {
        data = list->head->value;
        list->head = NULL;
        list->tail = NULL;
    }
    else if (index == 0) {                       //Case if remove is at head
        data = list->head->value;
        list->head = list->head->next;
        list->head->before = NULL;
    }
    else {                                       //All removes not at head
        int counter = 0;
        if (index < list->size/2) {
            dllnode *current = list->head;
            while (counter < index - 1) {        // -1 is because we need to edit the node BEFORE the removed node
                current = current->next;
                counter ++;
            }
            data = current->next->value;
            current->next = current->next->next;
            current->next->before = current;
        }
        else {
            counter = list->size - 1;
            dllnode *current = list->tail;
            while (counter > index) {
                current = current->before;
                counter --;
            }
            data = current->value;
            current->before->next = current->next;
            if (index != list->size - 1) {
                current->next->before = current->before;
            }
            else {
                list->tail = current->before;
            }
            
        }
    }
    list->size -= 1;
    return data; 
}


/*
 * The unionDLL function appends one dll to another and makes the donor dll empty.
 */

void unionDLL(dll *to,dll *from) {
    if (to->size == 0) {
        to->head = from->head;
        to->tail = from->tail;
    }
    else if (from->size == 0) {
    }
    else {
        to->tail->next = from->head;
        from->head->before = to->tail;
        to->tail = from->tail;
    }
    to->size += from->size;
    from->size = 0;
    from->head = NULL;
    from->tail = NULL;
}


/*
 * The getDLL function returns the value stored at a specified index.
 */

void *getDLL(dll *list,int index) {
    void *data = 0;
    if (index == 0) {
        data = list->head->value;
    }
    else if (index == list->size - 1) {
        data = list->tail->value;
    }
    else {
        int counter = 0;
        dllnode *temp = list->head;
        while (counter < index) {
            temp = temp->next;
            data = temp->value;
            counter ++;
        }
    }
    return data;
}


/*
 * The sizeDLL function returns the size (number of nodes/values stored) of the dll.
 */

int sizeDLL(dll *list) {
    return list->size;
}


/*
 * The displayDLL function displays the dll using the passed display function.
 */

void displayDLL(FILE *fp,dll *list) {
    if (list->size == 0) {
        fprintf(fp,"[]");
        return;
    }
    int counter = 0;
    dllnode *temp = list->head;
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
