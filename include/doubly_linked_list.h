#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "memory_manager.h"

void dll_insert_after(
    MemoryBlock* block,
    MemoryBlock* new_block
);

void dll_remove(
    MemoryBlock* block
);

#endif