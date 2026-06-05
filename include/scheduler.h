#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void fifo_schedule(
    Process processes[],
    int count
);

void round_robin_schedule(
    Process processes[],
    int count,
    int quantum
);

void sjf_schedule(
    Process processes[],
    int count
);

#endif