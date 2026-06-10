#include <stdio.h>

#include "parser.h"

int parse_processes(
    const char* filename,
    Process processes[],
    int max_processes
) {

    FILE* file = fopen(
        filename,
        "r"
    );

    if (file == NULL)
        return -1;

    int count = 0;

    while (
        count < max_processes
        &&
        fscanf(
            file,
            "%d %d %d",
            &processes[count].pid,
            &processes[count].burst_time,
            &processes[count].memory_required
        ) == 3
    ) {

        processes[count].remaining_time =
            processes[count].burst_time;

        processes[count].priority = 0;

        processes[count].state = READY;

        count++;
    }

    fclose(file);

    return count;
}