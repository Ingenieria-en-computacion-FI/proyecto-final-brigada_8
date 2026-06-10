#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/* Nodo interno */
typedef struct Node {

    Process* process;
    struct Node* next;

} Node;

/* Lista */
struct LinkedList {

    Node* head;

};

/* Crear lista */
LinkedList* list_create() {

    LinkedList* list =
        (LinkedList*) malloc(sizeof(LinkedList));

    if (list == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

/* Insertar ordenado por burst_time */
void list_insert_sorted(
    LinkedList* list,
    Process* process
) {

    if (list == NULL || process == NULL)
        return;

    Node* new_node =
        (Node*) malloc(sizeof(Node));

    if (new_node == NULL)
        return;

    new_node->process = process;
    new_node->next = NULL;

    /* Insertar al inicio */
    if (list->head == NULL ||
        process->burst_time <
        list->head->process->burst_time) {

        new_node->next = list->head;
        list->head = new_node;

        return;
    }

    Node* current = list->head;

    while (current->next != NULL &&
           current->next->process->burst_time
           <= process->burst_time) {

        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

/* Buscar por PID */
Process* list_find_pid(
    LinkedList* list,
    int pid
) {

    if (list == NULL)
        return NULL;

    Node* current = list->head;

    while (current != NULL) {

        if (current->process->pid == pid)
            return current->process;

        current = current->next;
    }

    return NULL;
}

/* Imprimir lista */
void list_print(
    LinkedList* list
) {

    if (list == NULL)
        return;

    Node* current = list->head;

    while (current != NULL) {

        printf(
            "PID=%d Burst=%d\n",
            current->process->pid,
            current->process->burst_time
        );

        current = current->next;
    }
}

/* Liberar lista */
void list_destroy(
    LinkedList* list
) {

    if (list == NULL)
        return;

    Node* current = list->head;

    while (current != NULL) {

        Node* next = current->next;

        free(current);

        current = next;
    }

    free(list);
}


/*Para facilitar la construcción de sjf*/
Process* list_pop_front(
    LinkedList* list
) {

    if (list == NULL || list->head == NULL)
        return NULL;

    Node* temp = list->head;

    Process* process = temp->process;

    list->head = temp->next;

    free(temp);

    return process;
}
