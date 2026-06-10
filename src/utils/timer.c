#include <time.h>

#include "timer.h"

static clock_t start_time;

void timer_start(void) {

    start_time = clock();
}

double timer_stop(void) {

    clock_t end_time = clock();

    return (double)
        (end_time - start_time)
        / CLOCKS_PER_SEC;
}