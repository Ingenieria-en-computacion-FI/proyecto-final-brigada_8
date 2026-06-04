#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "process.h"

typedef struct CircularQueue CircularQueue;

CircularQueue* cq_create();

void cq_enqueue(
    CircularQueue* queue,
    Process* process
);

Process* cq_dequeue(
    CircularQueue* queue
);

Process* cq_current(
    CircularQueue* queue
);

int cq_is_empty(
    CircularQueue* queue
);

void cq_destroy(
    CircularQueue* queue
);

#endif