#ifndef SJF_H
#define SJF_H

typedef struct SJFScheduler SJFScheduler;

SJFScheduler* sjf_create();

void sjf_add_process(
    SJFScheduler* scheduler,
    int pid,
    int burst_time
);

int sjf_next(
    SJFScheduler* scheduler
);

void sjf_destroy(
    SJFScheduler* scheduler
);

#endif