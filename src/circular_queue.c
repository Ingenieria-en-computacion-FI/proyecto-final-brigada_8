#include <stdlib.h>
#include "circular_queue.h"

struct CircularQueue {

    int* data;

    int front;
    int rear;

    int size;
    int capacity;
};

/* Crear cola circular */
CircularQueue* cq_create(int capacity) {

    if (capacity <= 0)
        return NULL;

    CircularQueue* queue = malloc(sizeof(CircularQueue));

    if (queue == NULL)
        return NULL;

    queue->data = malloc(capacity * sizeof(int));

    if (queue->data == NULL) {

        free(queue);
        return NULL;
    }

    queue->front = 0;
    queue->rear = 0;

    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

/* Verificar si está vacía */
int cq_is_empty(CircularQueue* queue) {

    if (queue == NULL)
        return 1;

    return queue->size == 0;
}

/* Verificar si está llena */
int cq_is_full(CircularQueue* queue) {

    if (queue == NULL)
        return 0;

    return queue->size == queue->capacity;
}

/* Insertar elemento */
void cq_enqueue(
    CircularQueue* queue,
    int value
) {

    if (queue == NULL || cq_is_full(queue))
        return;

    queue->data[queue->rear] = value;

    queue->rear =
        (queue->rear + 1)
        % queue->capacity;

    queue->size++;
}

/* Eliminar elemento */
int cq_dequeue(
    CircularQueue* queue
) {

    if (queue == NULL || cq_is_empty(queue))
        return -1;

    int value = queue->data[queue->front];

    queue->front =
        (queue->front + 1)
        % queue->capacity;

    queue->size--;

    return value;
}

/* Consultar el frente */
int cq_front(
    CircularQueue* queue
) {

    if (queue == NULL || cq_is_empty(queue))
        return -1;

    return queue->data[queue->front];
}

/* Liberar memoria */
void cq_destroy(
    CircularQueue* queue
) {

    if (queue == NULL)
        return;

    free(queue->data);
    free(queue);
}