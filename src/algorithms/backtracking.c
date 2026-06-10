#include "algorithms.h"

/* Función auxiliar recursiva */
static int subset_sum_recursive(
    int arr[],
    int n,
    int target,
    int index
) {

    /* Encontró una solución */
    if (target == 0)
        return 1;

    /* Se acabaron los elementos */
    if (index >= n)
        return 0;

    /* Evitar objetivos negativos */
    if (target < 0)
        return 0;

    /* Incluir elemento actual */
    if (subset_sum_recursive(
            arr,
            n,
            target - arr[index],
            index + 1))
        return 1;

    /* Excluir elemento actual */
    return subset_sum_recursive(
        arr,
        n,
        target,
        index + 1
    );
}

int backtracking_subset_sum(
    int arr[],
    int n,
    int target
) {

    return subset_sum_recursive(
        arr,
        n,
        target,
        0
    );
}