#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "memory_manager.h"

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

#endif