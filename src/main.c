#include <stdio.h>
#include <stdlib.h>

#include "scheduler.h"
#include "memory_manager.h"
#include "timer.h"
#include "logger.h"

int main(
    int argc,
    char* argv[]
) {

    int memory_size = 1000;

    if (argc > 1)
        memory_size = atoi(argv[1]);

    printf(
        "\n================================================\n"
    );
    printf(
        "      SIMULADOR DE MINI SISTEMA OPERATIVO\n"
    );
    printf(
        "================================================\n\n"
    );

    printf(
        "Tamaño de memoria: %d\n\n",
        memory_size
    );

    log_message(
        "Simulacion iniciada"
    );

    timer_start();

    /*
     * Crear memoria
     */
    MemoryManager* mm =
        mm_create(memory_size);

    if (mm == NULL) {

        printf(
            "Error creando administrador de memoria\n"
        );

        log_message(
            "Error creando administrador de memoria"
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

        log_message(
            "Error creando scheduler"
        );

        mm_destroy(mm);

        return 1;
    }

    /*
     * Crear procesos
     */
    printf(
        "Creando procesos...\n"
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

    log_message(
        "Procesos creados"
    );

    printf(
        "PID 1 | Rafaga 10 | Memoria 100\n"
    );

    printf(
        "PID 2 | Rafaga 5 | Memoria 200\n"
    );

    printf(
        "PID 3 | Rafaga 8 | Memoria 150\n"
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

    log_message(
        "Memoria asignada"
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
     * Simular fragmentacion
     */
    printf(
        "\nLiberando un proceso...\n"
    );

    mm_free(
        mm,
        pid2
    );

    printf(
        "Bloque %d liberado\n",
        pid2
    );

    log_message(
        "Bloque de memoria liberado"
    );

    /*
     * Coalescencia
     */
    printf(
        "\nEjecutando coalescencia...\n"
    );

    mm_coalesce(mm);

    log_message(
        "Coalescencia ejecutada"
    );

    /*
     * Compactacion
     */
    printf(
        "Ejecutando compactacion...\n"
    );

    mm_compact(mm);

    log_message(
        "Compactacion ejecutada"
    );

    /*
     * Scheduler FIFO
     */
    printf(
        "\nOrden de ejecucion FIFO:\n"
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

    log_message(
        "Planificacion FIFO completada"
    );

    double elapsed =
        timer_stop();

    printf(
        "\nTiempo de ejecucion: %.6f segundos\n",
        elapsed
    );

    printf(
        "\nSimulacion completada exitosamente.\n"
    );

    log_message(
        "Simulacion finalizada"
    );

    scheduler_destroy(
        scheduler
    );

    mm_destroy(
        mm
    );

    return 0;
}