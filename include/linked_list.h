#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "process.h"

typedef struct LinkedList LinkedList;

LinkedList* list_create();

void list_insert_sorted(
    LinkedList* list,
    Process* process
);

Process* list_find_pid(
    LinkedList* list,
    int pid
);

void list_print(
    LinkedList* list
);

void list_destroy(
    LinkedList* list
);

#endif