# Reporte de Complejidad de Algoritmos y Estructuras de Datos
## 1. Estructuras de Datos Base
 * **stack.h (Pila)**
   * **Push / Pop / Peek:** O(1)
 * **queue.h (Cola)**
   * **Enqueue / Dequeue:** O(1)
 * **circular_queue.h (Cola Circular)**
   * **Enqueue / Dequeue:** O(1)
 * **linked_list.h (Lista Enlazada)**
   * **Inserción al inicio / fin:** O(1)
   * **Búsqueda / Eliminación:** O(n)
 * **doubly_linked_list.h (Lista Doblemente Enlazada)**
   * **Eliminación con referencia directa:** O(1)
   * **Búsqueda por valor:** O(n)
## 2. Algoritmos de Planificación de la CPU (Schedulers)
 * **round_robin.h (Round Robin)**
   * **Selección del próximo proceso:** O(1)
 * **sjf.h (Shortest Job First)**
   * **Selección con Min-Heap / Árbol de prioridad:** O(\log n)
   * **Selección con lista desordenada:** O(n)
## 3. Gestión y Módulos del Sistema
 * **process.h / timer.h (Gestión de Procesos y Tiempo)**
   * **Actualización de estado:** O(1)
   * **Gestión de alarmas / hilos dormidos:** O(\log n) o O(n)
 * **memory_manager.h (Administrador de Memoria)**
   * **Asignación (First-Fit / Best-Fit):** O(n)
   * **Traducción de direcciones (Paginación):** O(1)
 * **parser.h / algorithms.h (Análisis y Funciones Auxiliares)**
   * **Análisis de sintaxis / Tokenización:** O(m) *(donde m es la longitud de la cadena de entrada)*
