#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct CircularQueue CircularQueue;

CircularQueue* cq_create(int capacity);
void cq_enqueue(CircularQueue* queue, int value);
int cq_dequeue(CircularQueue* queue);
int cq_front(CircularQueue* queue);
int cq_is_empty(CircularQueue* queue);
int cq_is_full(CircularQueue* queue);
void cq_destroy(CircularQueue* queue);

#endif