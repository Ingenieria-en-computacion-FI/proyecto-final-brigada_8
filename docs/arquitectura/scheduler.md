# Planificador de Procesos

## Introducción

El planificador de procesos (Scheduler) es el componente encargado de determinar el orden en que los procesos son ejecutados dentro del simulador.

Se implementaron distintos algoritmos clásicos de planificación utilizados en sistemas operativos.

---

## Estructura Process

Cada proceso es representado mediante la estructura:

```c
typedef struct {

    int pid;

    int burst_time;

    int remaining_time;

    int priority;

    int memory_required;

    ProcessState state;

} Process;
```

---

## Estados de Proceso

Los procesos pueden encontrarse en alguno de los siguientes estados:

```c
typedef enum {

    READY,
    RUNNING,
    BLOCKED,
    FINISHED

} ProcessState;
```

### READY

El proceso está listo para ejecutarse.

### RUNNING

El proceso está utilizando el procesador.

### BLOCKED

El proceso se encuentra esperando algún recurso.

### FINISHED

El proceso terminó su ejecución.

---

## FIFO (First In First Out)

FIFO ejecuta los procesos en el mismo orden en que llegan al sistema.

### Funcionamiento

```text
Entrada:

P1 -> P2 -> P3

Salida:

P1 -> P2 -> P3
```

### Implementación

FIFO utiliza una cola tradicional (Queue).

Operaciones principales:

- scheduler_create_fifo()
- scheduler_add_process()
- scheduler_next()
- scheduler_destroy()

### Ventajas

- Implementación sencilla.
- Bajo costo computacional.

### Desventajas

- Puede generar tiempos de espera elevados.
- No favorece procesos cortos.

---

## SJF (Shortest Job First)

SJF ejecuta primero el proceso con menor tiempo de ráfaga.

### Funcionamiento

```text
Procesos:

P1 = 10
P2 = 5
P3 = 8

Orden:

P2 -> P3 -> P1
```

### Ventajas

- Minimiza el tiempo promedio de espera.

### Desventajas

- Puede provocar inanición de procesos largos.

---

## Round Robin

Round Robin distribuye el tiempo de CPU utilizando un quantum fijo.

### Funcionamiento

```text
Quantum = 2

P1 -> P2 -> P3 -> P1 -> P2 ...
```

Cada proceso recibe una porción de tiempo antes de regresar a la cola.

### Ventajas

- Equidad entre procesos.
- Adecuado para sistemas interactivos.

### Desventajas

- Puede aumentar el número de cambios de contexto.

---

## Cola de Listos

Los procesos listos para ejecutarse son almacenados en estructuras de cola.

Dependiendo del algoritmo:

- Queue para FIFO.
- Circular Queue para Round Robin.
- Estructuras auxiliares para SJF.

---

## Simulación

Durante la ejecución del sistema:

1. Se crean procesos.
2. Los procesos ingresan al estado READY.
3. El scheduler selecciona el siguiente proceso.
4. El proceso pasa a RUNNING.
5. Al finalizar pasa a FINISHED.

Ejemplo:

```text
READY
  ↓
RUNNING
  ↓
FINISHED
```

---

## Integración con Memoria

Antes de ejecutarse, cada proceso solicita memoria al administrador de memoria.

El scheduler trabaja conjuntamente con:

- Memory Manager.
- Algoritmos de asignación.
- Logger.
- Timer.

---

## Pruebas

Las pruebas de planificación se encuentran en:

```text
tests/test_scheduler.c
```

Estas pruebas verifican:

- Inserción de procesos.
- Orden correcto de ejecución.
- Funcionamiento de FIFO.
- Correcta liberación de recursos.

