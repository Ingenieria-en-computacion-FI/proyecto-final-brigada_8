#include "algorithms.h"
#include <stdlib.h>
#include "algorithms.h"

MemoryBlock* worst_fit(
    MemoryManager* mm,
    int size
) {

    if (mm == NULL || size <= 0)
        return NULL;

    MemoryBlock* current = mm->head;

    MemoryBlock* worst = NULL;

    while (current != NULL) {

        if (current->free &&
            current->size >= size) {

            if (worst == NULL ||
                current->size >
                worst->size) {

                worst = current;
            }
        }

        current = current->next;
    }

    return worst;
}