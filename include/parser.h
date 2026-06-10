#ifndef PARSER_H
#define PARSER_H

#include "process.h"

int parse_processes(
    const char* filename,
    Process processes[],
    int max_processes
);

#endif