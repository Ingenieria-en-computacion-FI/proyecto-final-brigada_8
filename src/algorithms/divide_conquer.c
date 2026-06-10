#include "algorithms.h"
#include "memory_manager.h"

void divide_conquer_compact(
    MemoryManager* mm
) {

    if (mm == NULL)
        return;

    /*
    La compactación reorganiza la memoria
    eliminando fragmentación externa.

    Se reutiliza la implementación
    del gestor de memoria.
    */

    mm_compact(mm);
}