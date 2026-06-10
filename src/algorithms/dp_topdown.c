#include "algorithms.h"

#define MAX_N 100

static int memo[MAX_N];

/* Función auxiliar recursiva */
static int fibonacci_memo(
    int n
) {

    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] =
        fibonacci_memo(n - 1)
        + fibonacci_memo(n - 2);

    return memo[n];
}

int dp_topdown_fibonacci(
    int n
) {

    if (n < 0 || n >= MAX_N)
        return -1;

    for (int i = 0; i < MAX_N; i++)
        memo[i] = -1;

    return fibonacci_memo(n);
}