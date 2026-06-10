#include "algorithms.h"

MemoryBlock* brute_force_find(
    MemoryManager* mm,
    int size
) {

    if (mm == NULL)
        return NULL;

    MemoryBlock* current = mm->head;

    while (current != NULL) {

        if (current->free &&
            current->size >= size) {

            return current;
        }

        current = current->next;
    }

    return NULL;
}