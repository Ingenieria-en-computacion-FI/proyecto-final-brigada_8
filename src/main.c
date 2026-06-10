#include <stdio.h>
#include <stdlib.h>

int main(
    int argc,
    char* argv[]
) {

    int size = 0;

    if (argc > 1)
        size = atoi(argv[1]);

    printf(
        "Simulation size: %d\n",
        size
    );

    return 0;
}