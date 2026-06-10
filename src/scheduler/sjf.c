#include <stdlib.h>

#include "sjf.h"
#include "linked_list.h"
#include "process.h"

struct SJFScheduler {

    LinkedList* ready_list;

};

SJFScheduler* sjf_create() {

    SJFScheduler* scheduler =
        malloc(sizeof(SJFScheduler));

    if (scheduler == NULL)
        return NULL;

    scheduler->ready_list =
        list_create();

    if (scheduler->ready_list == NULL) {

        free(scheduler);
        return NULL;
    }

    return scheduler;
}

void sjf_add_process(
    SJFScheduler* scheduler,
    int pid,
    int burst_time
) {

    if (scheduler == NULL)
        return;

    Process* process =
        malloc(sizeof(Process));

    if (process == NULL)
        return;

    process->pid = pid;
    process->burst_time = burst_time;
    process->remaining_time = burst_time;

    process->priority = 0;
    process->memory_required = 0;
    process->state = READY;

    list_insert_sorted(
        scheduler->ready_list,
        process
    );
}

int sjf_next(
    SJFScheduler* scheduler
) {

    if (scheduler == NULL)
        return -1;

    Process* process =
        list_pop_front(
            scheduler->ready_list
        );

    if (process == NULL)
        return -1;

    int pid = process->pid;

    free(process);

    return pid;
}

void sjf_destroy(
    SJFScheduler* scheduler
) {

    if (scheduler == NULL)
        return;

    list_destroy(
        scheduler->ready_list
    );

    free(scheduler);
}