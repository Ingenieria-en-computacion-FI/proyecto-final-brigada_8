#include "algorithms.h"

MemoryBlock* best_fit(
    MemoryManager* mm,
    int size
) {

    if (mm == NULL || size <= 0)
        return NULL;

    MemoryBlock* current = mm->head;

    MemoryBlock* best = NULL;

    while (current != NULL) {

        if (current->free &&
            current->size >= size) {

            if (best == NULL ||
                current->size <
                best->size) {

                best = current;
            }
        }

        current = current->next;
    }

    return best;
}