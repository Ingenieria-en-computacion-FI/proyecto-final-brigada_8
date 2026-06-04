#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

typedef struct Queue Queue;

Queue* queue_create();

void queue_enqueue(
    Queue* queue,
    Process* process
);

Process* queue_dequeue(
    Queue* queue
);

Process* queue_front(
    Queue* queue
);

int queue_is_empty(
    Queue* queue
);

void queue_destroy(
    Queue* queue
);

#endif