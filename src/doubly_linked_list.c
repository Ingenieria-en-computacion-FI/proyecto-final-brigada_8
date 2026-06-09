#include "doubly_linked_list.h"

void dll_insert_after(
    MemoryBlock* block,
    MemoryBlock* new_block
) {

    if (block == NULL || new_block == NULL)
        return;

    new_block->next = block->next;
    new_block->prev = block;

    if (block->next != NULL)
        block->next->prev = new_block;

    block->next = new_block;
}

void dll_remove(
    MemoryBlock* block
) {

    if (block == NULL)
        return;

    if (block->prev != NULL)
        block->prev->next = block->next;

    if (block->next != NULL)
        block->next->prev = block->prev;
}