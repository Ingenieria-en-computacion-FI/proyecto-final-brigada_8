#include <stdlib.h>
#include "memory_manager.h"

MemoryManager* mm_create(int total_memory) {

    MemoryManager* mm =
        (MemoryManager*) malloc(sizeof(MemoryManager));

    if (mm == NULL)
        return NULL;

    MemoryBlock* initial =
        (MemoryBlock*) malloc(sizeof(MemoryBlock));

    if (initial == NULL) {
        free(mm);
        return NULL;
    }

    initial->start = 0;
    initial->size = total_memory;
    initial->free = 1;
    initial->pid = -1;

    initial->next = NULL;
    initial->prev = NULL;

    mm->head = initial;
    mm->total_memory = total_memory;

    return mm;
}

int mm_allocate_first_fit(
    MemoryManager* mm,
    int size
) {

    if (mm == NULL || size <= 0)
        return -1;

    MemoryBlock* current = mm->head;

    while (current != NULL) {

        if (current->free && current->size >= size) {

            int allocated_start = current->start;

            if (current->size > size) {

                MemoryBlock* remainder =
                    (MemoryBlock*) malloc(sizeof(MemoryBlock));

                if (remainder == NULL)
                    return -1;

                remainder->start = current->start + size;
                remainder->size = current->size - size;
                remainder->free = 1;
                remainder->pid = -1;

                remainder->next = current->next;
                remainder->prev = current;

                if (current->next != NULL)
                    current->next->prev = remainder;

                current->next = remainder;
            }

            current->size = size;
            current->free = 0;

            /*
             * El encabezado obliga a tener pid.
             * Como allocate no recibe pid,
             * usamos start como identificador.
             */
            current->pid = allocated_start;

            return allocated_start;
        }

        current = current->next;
    }

    return -1;
}

void mm_free(
    MemoryManager* mm,
    int pid
) {

    if (mm == NULL)
        return;

    MemoryBlock* current = mm->head;

    while (current != NULL) {

        if (!current->free && current->pid == pid) {

            current->free = 1;
            current->pid = -1;

            mm_coalesce(mm);
            return;
        }

        current = current->next;
    }
}

void mm_coalesce(
    MemoryManager* mm
) {

    if (mm == NULL)
        return;

    MemoryBlock* current = mm->head;

    while (current != NULL &&
           current->next != NULL) {

        if (current->free &&
            current->next->free) {

            MemoryBlock* next = current->next;

            current->size += next->size;
            current->next = next->next;

            if (next->next != NULL)
                next->next->prev = current;

            free(next);

        } else {

            current = current->next;
        }
    }
}

void mm_compact(
    MemoryManager* mm
) {

    if (mm == NULL)
        return;

    MemoryBlock* current = mm->head;

    int next_start = 0;

    /* Reacomodar bloques ocupados */
    while (current != NULL) {

        if (!current->free) {

            current->start = next_start;

            next_start += current->size;
        }

        current = current->next;
    }

    /* Eliminar bloques libres existentes */
    current = mm->head;

    while (current != NULL) {

        MemoryBlock* next = current->next;

        if (current->free) {

            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                mm->head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
        }

        current = next;
    }

    /* Crear un único bloque libre al final */
    MemoryBlock* free_block =
        (MemoryBlock*) malloc(sizeof(MemoryBlock));

    if (free_block == NULL)
        return;

    free_block->start = next_start;

    free_block->size =
        mm->total_memory - next_start;

    free_block->free = 1;
    free_block->pid = -1;

    free_block->next = NULL;
    free_block->prev = NULL;

    if (mm->head == NULL) {

        mm->head = free_block;

    } else {

        MemoryBlock* tail = mm->head;

        while (tail->next != NULL)
            tail = tail->next;

        tail->next = free_block;
        free_block->prev = tail;
    }
}

void mm_destroy(
    MemoryManager* mm
) {

    if (mm == NULL)
        return;

    MemoryBlock* current = mm->head;

    while (current != NULL) {

        MemoryBlock* next = current->next;

        free(current);

        current = next;
    }

    free(mm);
}
