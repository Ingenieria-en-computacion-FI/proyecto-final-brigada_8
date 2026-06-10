#include <stdlib.h>

#include "round_robin.h"
#include "circular_queue.h"
#include "process.h"

#define MAX_PROCESSES 100

struct RRScheduler {

    Process processes[MAX_PROCESSES];

    int count;

    CircularQueue* ready_queue;

    int quantum;
};

/* Buscar proceso por PID */
static Process* find_process(
    RRScheduler* scheduler,
    int pid
) {

    for (int i = 0;
         i < scheduler->count;
         i++) {

        if (scheduler->processes[i].pid == pid)
            return &scheduler->processes[i];
    }

    return NULL;
}

/* Crear scheduler */
RRScheduler* rr_create(
    int quantum
) {

    if (quantum <= 0)
        return NULL;

    RRScheduler* scheduler =
        malloc(sizeof(RRScheduler));

    if (scheduler == NULL)
        return NULL;

    scheduler->count = 0;
    scheduler->quantum = quantum;

    scheduler->ready_queue =
        cq_create(MAX_PROCESSES);

    if (scheduler->ready_queue == NULL) {

        free(scheduler);
        return NULL;
    }

    return scheduler;
}

/* Agregar proceso */
void rr_add_process(
    RRScheduler* scheduler,
    int pid,
    int burst_time
) {

    if (scheduler == NULL)
        return;

    if (scheduler->count >= MAX_PROCESSES)
        return;

    Process* process =
        &scheduler->processes[
            scheduler->count
        ];

    process->pid = pid;

    process->burst_time =
        burst_time;

    process->remaining_time =
        burst_time;

    process->priority = 0;

    process->memory_required = 0;

    process->state = READY;

    scheduler->count++;

    cq_enqueue(
        scheduler->ready_queue,
        pid
    );
}

/* Ejecutar siguiente quantum */
int rr_next(
    RRScheduler* scheduler
) {

    if (scheduler == NULL)
        return -1;

    if (cq_is_empty(
            scheduler->ready_queue))
        return -1;

    int pid =
        cq_dequeue(
            scheduler->ready_queue
        );

    Process* process =
        find_process(
            scheduler,
            pid
        );

    if (process == NULL)
        return -1;

    process->state = RUNNING;

    if (process->remaining_time >
        scheduler->quantum) {

        process->remaining_time -=
            scheduler->quantum;

        process->state = READY;

        /* Reinserción */
        cq_enqueue(
            scheduler->ready_queue,
            pid
        );

    } else {

        process->remaining_time = 0;

        process->state = FINISHED;
    }

    return pid;
}

/* Liberar scheduler */
void rr_destroy(
    RRScheduler* scheduler
) {

    if (scheduler == NULL)
        return;

    cq_destroy(
        scheduler->ready_queue
    );

    free(scheduler);
}