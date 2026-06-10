#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "memory_manager.h"
#include <stdlib.h>

/* Greedy */

MemoryBlock* first_fit(
    MemoryManager* mm,
    int size
);

MemoryBlock* best_fit(
    MemoryManager* mm,
    int size
);

MemoryBlock* worst_fit(
    MemoryManager* mm,
    int size
);

/* Brute Force */

MemoryBlock* brute_force_find(
    MemoryManager* mm,
    int size
);

/* Backtracking */

int backtracking_subset_sum(
    int arr[],
    int n,
    int target
);

/* Divide and Conquer */

void divide_conquer_compact(
    MemoryManager* mm
);

/* Dynamic Programming */

int dp_topdown_fibonacci(
    int n
);

int dp_bottomup_fibonacci(
    int n
);

int incremental_fibonacci(
    int n
);

#endif