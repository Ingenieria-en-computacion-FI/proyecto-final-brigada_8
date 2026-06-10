#include <stdio.h>
#include <time.h>

#include "logger.h"

void log_message(
    const char* message
) {

    FILE* file =
        fopen(
            "data/logs/system.log",
            "a"
        );

    if (file == NULL)
        return;

    time_t now = time(NULL);

    fprintf(
        file,
        "[%ld] %s\n",
        now,
        message
    );

    fclose(file);
}