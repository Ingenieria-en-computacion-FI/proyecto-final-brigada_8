# Estructuras de Datos

## Introducción

Para la implementación del simulador de sistema operativo se desarrollaron diversas estructuras de datos fundamentales que permiten administrar procesos, memoria y colas de planificación.

---

## Pila (Stack)

La estructura Stack sigue el principio LIFO (Last In, First Out).

### Operaciones implementadas

- push()
- pop()
- peek()
- is_empty()

### Aplicaciones

- Gestión temporal de información.
- Ejemplificación de estructuras básicas requeridas por el proyecto.

---

## Cola (Queue)

La estructura Queue sigue el principio FIFO (First In, First Out).

### Operaciones implementadas

- enqueue()
- dequeue()
- front()
- is_empty()

### Aplicaciones

- Implementación del scheduler FIFO.
- Administración de procesos listos para ejecución.

---

## Cola Circular (Circular Queue)

La cola circular reutiliza espacios liberados mediante índices circulares.

### Operaciones implementadas

- enqueue()
- dequeue()
- is_empty()

### Aplicaciones

- Base para el algoritmo Round Robin.
- Administración eficiente de procesos.

---

## Lista Enlazada (Linked List)

Permite almacenamiento dinámico mediante nodos enlazados.

### Aplicaciones

- Gestión flexible de elementos.
- Apoyo para estructuras auxiliares.

---

## Lista Doblemente Enlazada (Doubly Linked List)

Cada nodo almacena referencias al nodo anterior y siguiente.

### Aplicaciones

- Administración de bloques de memoria.
- Implementación de coalescencia y compactación.

---

## Pruebas

Se desarrollaron pruebas unitarias para validar:

- Inserción.
- Eliminación.
- Acceso.
- Comportamiento esperado de cada estructura.

Todas las pruebas fueron ejecutadas mediante:

```bash
make test
```