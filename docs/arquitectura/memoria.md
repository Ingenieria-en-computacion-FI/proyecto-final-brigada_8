# Gestión de Memoria

## Introducción

El simulador implementa un administrador de memoria dinámica encargado de asignar, liberar y reorganizar bloques de memoria para los procesos simulados.

La memoria se representa mediante una lista doblemente enlazada de bloques, donde cada bloque almacena información sobre su tamaño, estado y ubicación.

---

## Estructura MemoryBlock

Cada bloque de memoria contiene:

- Dirección inicial.
- Tamaño del bloque.
- Estado (libre u ocupado).
- Identificador del proceso asociado.
- Referencias al bloque anterior y siguiente.

```c
typedef struct MemoryBlock {

    int start;

    int size;

    int free;

    int pid;

    struct MemoryBlock* next;

    struct MemoryBlock* prev;

} MemoryBlock;
```

---

## Estructura MemoryManager

El administrador de memoria mantiene una referencia al primer bloque y la cantidad total de memoria disponible.

```c
typedef struct MemoryManager {

    MemoryBlock* head;

    int total_memory;

} MemoryManager;
```

---

## First Fit

First Fit busca el primer bloque libre que sea suficientemente grande para satisfacer una solicitud de memoria.

### Ventajas

- Implementación sencilla.
- Baja complejidad de búsqueda.

### Desventajas

- Puede generar fragmentación externa.

---

## Best Fit

Best Fit busca el bloque libre más pequeño que pueda contener la solicitud.

### Ventajas

- Reduce el desperdicio inmediato de memoria.

### Desventajas

- Mayor tiempo de búsqueda.
- Puede generar muchos fragmentos pequeños.

---

## Worst Fit

Worst Fit selecciona el bloque libre más grande disponible.

### Ventajas

- Mantiene bloques grandes disponibles.

### Desventajas

- Puede desperdiciar memoria considerablemente.

---

## Liberación de Memoria

Cuando un proceso finaliza, el bloque asociado se marca como libre.

```text
Antes:

[P1][P2][P3]

Después de liberar P2:

[P1][Libre][P3]
```

---

## Coalescencia

La coalescencia combina bloques libres adyacentes para reducir la fragmentación.

```text
Antes:

[P1][Libre][Libre][P3]

Después:

[P1][Libre Grande][P3]
```

### Objetivo

- Reducir fragmentación externa.
- Incrementar bloques libres disponibles.

---

## Compactación

La compactación reorganiza los bloques ocupados para moverlos hacia el inicio de la memoria.

```text
Antes:

[P1][Libre][P3][Libre]

Después:

[P1][P3][Libre Grande]
```

### Beneficios

- Elimina fragmentación externa.
- Genera bloques continuos de memoria libre.

---

## Simulación

Durante la ejecución:

1. Se crea el administrador de memoria.
2. Se asignan bloques a los procesos.
3. Se libera memoria.
4. Se ejecuta coalescencia.
5. Se ejecuta compactación.

Estos eventos son registrados mediante el módulo Logger y almacenados en:

```text
data/logs/system.log
```

---

## Pruebas

La funcionalidad del administrador de memoria fue validada mediante pruebas unitarias incluidas en:

```text
tests/test_memory_manager.c
```

Las pruebas verifican:

- Asignación.
- Liberación.
- Integridad de bloques.
- Funcionamiento correcto de los algoritmos de memoria.