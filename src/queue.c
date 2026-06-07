#include <stdlib.h>
#include "queue.h"

/* Nodo interno de la cola */
typedef struct QueueNode {

    Process* process;
    struct QueueNode* next;

} QueueNode;

/* Definición real de Queue */
struct Queue {

    QueueNode* front;
    QueueNode* rear;

};

/* Crear cola vacía */
Queue* queue_create() {

    Queue* queue = (Queue*) malloc(sizeof(Queue));

    if (queue == NULL)
        return NULL;

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

/* Verificar si está vacía */
int queue_is_empty(Queue* queue) {

    if (queue == NULL)
        return 1;

    return queue->front == NULL;
}

/* Insertar al final */
void queue_enqueue(
    Queue* queue,
    Process* process
) {

    if (queue == NULL || process == NULL)
        return;

    QueueNode* new_node =
        (QueueNode*) malloc(sizeof(QueueNode));

    if (new_node == NULL)
        return;

    new_node->process = process;
    new_node->next = NULL;

    /* Cola vacía */
    if (queue->rear == NULL) {

        queue->front = new_node;
        queue->rear = new_node;

        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

/* Eliminar del frente */
Process* queue_dequeue(
    Queue* queue
) {

    if (queue_is_empty(queue))
        return NULL;

    QueueNode* temp = queue->front;

    Process* process = temp->process;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return process;
}

/* Consultar el frente sin eliminar */
Process* queue_front(
    Queue* queue
) {

    if (queue_is_empty(queue))
        return NULL;

    return queue->front->process;
}

/* Liberar memoria */
void queue_destroy(
    Queue* queue
) {

    if (queue == NULL)
        return;

    while (!queue_is_empty(queue))
        queue_dequeue(queue);

    free(queue);
}
