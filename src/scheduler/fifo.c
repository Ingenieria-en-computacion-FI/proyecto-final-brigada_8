#include <stdlib.h>
#include "scheduler.h"
#include "queue.h"

struct Scheduler {

    Queue* ready_queue;

};

Scheduler* scheduler_create_fifo() {

    Scheduler* scheduler =
        malloc(sizeof(Scheduler));

    if (scheduler == NULL)
        return NULL;

    scheduler->ready_queue =
        queue_create();

    if (scheduler->ready_queue == NULL) {

        free(scheduler);
        return NULL;
    }

    return scheduler;
}

void scheduler_add_process(
    Scheduler* scheduler,
    int pid,
    int burst_time
) {

    (void)burst_time;

    if (scheduler == NULL)
        return;

    enqueue(
        scheduler->ready_queue,
        pid
    );
}

int scheduler_next(
    Scheduler* scheduler
) {

    if (scheduler == NULL)
        return -1;

    return dequeue(
        scheduler->ready_queue
    );
}

void scheduler_destroy(
    Scheduler* scheduler
) {

    if (scheduler == NULL)
        return;

    queue_destroy(
        scheduler->ready_queue
    );

    free(scheduler);
}