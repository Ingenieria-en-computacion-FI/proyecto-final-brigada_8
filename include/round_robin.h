#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

typedef struct RRScheduler RRScheduler;

RRScheduler* rr_create(
    int quantum
);

void rr_add_process(
    RRScheduler* scheduler,
    int pid,
    int burst_time
);

int rr_next(
    RRScheduler* scheduler
);

void rr_destroy(
    RRScheduler* scheduler
);

#endif