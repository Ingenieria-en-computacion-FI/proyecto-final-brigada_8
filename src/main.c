#include <stdio.h>
#include <stdlib.h>

#include "scheduler.h"
#include "memory_manager.h"
#include "timer.h"

int main(
    int argc,
    char* argv[]
) {

    int memory_size = 1000;

    if (argc > 1)
        memory_size = atoi(argv[1]);

    printf(
        "\n=================================\n"
    );
    printf(
        "      SIMULADOR DE MINI SISTEMA OPERATIVO\n"
    );
    printf(
        "=================================\n\n"
    );

    printf(
        "Memory Size: %d\n\n",
        memory_size
    );

    timer_start();

    /*
     * Crear memoria
     */
    MemoryManager* mm =
        mm_create(memory_size);

    if (mm == NULL) {

        printf(
            "Error creando memory manager\n"
        );

        return 1;
    }

    /*
     * Crear scheduler FIFO
     */
    Scheduler* scheduler =
        scheduler_create_fifo();

    if (scheduler == NULL) {

        printf(
            "Error creando scheduler\n"
        );

        mm_destroy(mm);
        return 1;
    }

    /*
     * Crear procesos
     */
    printf(
        "Creando proceso...\n"
    );

    scheduler_add_process(
        scheduler,
        1,
        10
    );

    scheduler_add_process(
        scheduler,
        2,
        5
    );

    scheduler_add_process(
        scheduler,
        3,
        8
    );

    printf(
        "PID 1 | Burst 10 | Memoria 100\n"
    );

    printf(
        "PID 2 | Burst 5 | Memoria 200\n"
    );

    printf(
        "PID 3 | Burst 8 | Memoria 150\n"
    );

    /*
     * Asignar memoria
     */
    printf(
        "\nAsignando memoria...\n"
    );

    int pid1 =
        mm_allocate_first_fit(
            mm,
            100
        );

    int pid2 =
        mm_allocate_first_fit(
            mm,
            200
        );

    int pid3 =
        mm_allocate_first_fit(
            mm,
            150
        );

    printf(
        "Bloque asignado en %d\n",
        pid1
    );

    printf(
        "Bloque asignado en %d\n",
        pid2
    );

    printf(
        "Bloque asignado en %d\n",
        pid3
    );

    /*
     * Simular fragmentación
     */
    printf(
        "\nLiberando un proceso...\n"
    );

    mm_free(
        mm,
        pid2
    );

    printf(
        "Block %d freed\n",
        pid2
    );

    /*
     * Coalescencia
     */
    printf(
        "\nEjecutando coalescence...\n"
    );

    mm_coalesce(mm);

    /*
     * Compactación
     */
    printf(
        "Ejecutando compactation...\n"
    );

    mm_compact(mm);

    /*
     * Scheduler FIFO
     */
    printf(
        "\nOrden de ejecucion de FIFO:\n"
    );

    int pid;

    while (
        (pid =
            scheduler_next(
                scheduler
            )
        ) != -1
    ) {

        printf(
            "Ejecutando PID %d\n",
            pid
        );
    }

    double elapsed =
        timer_stop();

    printf(
        "\nTiempo de ejecucion: %.6f segundos\n",
        elapsed
    );

    printf(
        "\nSimulacion completada exitosamente.\n"
    );

    scheduler_destroy(
        scheduler
    );

    mm_destroy(
        mm
    );

    return 0;
}
