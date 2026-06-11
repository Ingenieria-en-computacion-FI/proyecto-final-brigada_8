# Bitácora IA

# PROMPT 1

## Prompt utilizado
¿Cómo hacer la estructura de los demás archivos .h de forma que se complementen correctamente sin ser demasiado repetitivos?
...

## Respuesta IA
Si únicamente tienen definidos process.h, memory_manager.h, y stack.h, entonces antes de programar conviene diseñar los demás archivos .h para que todos hablen el mismo “idioma”. 
Yo intentaría que todas las estructuras almacenen Process* , no copias completas de Process. Así evitan duplicar información y cualquier cambio de estado (READY, RUNNING, etc.) se refleja en todo el sistema.

## Errores encontrados
No encontramos errores que afectaran el avance del proyecto
...

## Correcciones realizadas

...

## Validaciones realizadas
Nos sirvió de aclaración para formar la estrucutra de nuestros archivos .h
...

---
# PROMPT 2
## Prompt utilizado
¿La implementación de los archivos.h faltantes son correctoos respetandoo la estructura del proyecto? (le pasamos los archivos .h correspondientes)

## Respuesta IA
Si, en términos generales son correctos y coherentes con el proyecto. Yo les daria un 8.5/10 como diseño inicial.

Lo que más me gusta es que:
Process está exactamente alineado con lo que pide el proyecto.
MemoryManager y MemoryBlock coinciden con la estructura sugerid a
 Las colas y listas trabajan con Process* , evitando duplicar procesos.
 La interfaz es modular, lo que facilita repartir el trabajo entre los integrantes.

## Errores encontrados
No encontramos errores.

## Correcciones realizadas
...

## Validaciones realizadas
Nos sirvió como aclaración respecto a algunas dudas que teníamos, sobre si ibamos bien o mal
---

# PROMPT 3
## Prompt utilizado
¿El archivo queue.c esta bien diseñado?, esto respetando la estructura del proyecto

## Respuesta IA
Si yo fuera ayudante de la materia: 9.5/10
La única razón por la que no le doy 10 es porque me gusta más evitar los casts de malloc, pero funcionalmente no veo errores.
Yo no tocaría más queue.c y pasaría al siguiente módulo


## Errores encontrados
No encontramos errores.

## Correcciones realizadas
...

## Validaciones realizadas
Nos sirvió como aclaración respecto a algunas dudas que teníamos.

---
# PROMPT 4
## Prompt utilizado
Tratando de hacer git push sobre el repositorio nos salta un error, como podemos solucionarlo??

## Respuesta IA
Ese error es muy común cuando trabajan varias personas sobre el mismo repositorio.
El mensaje clave es:
```text
! [rejected] main -> main (fetch first)
```
Git te está diciendo:
> "El repositorio remoto tiene cambios que tú no tienes localmente."
Probablemente alguno de tus compañeros hizo un `push` antes que tú.
---
Primero verifica el estado
Ejecuta:
```bash
git status
```
y dime qué te aparece.
---
Lo más probable
Normalmente se arregla con:
```bash
git pull origin main
```
Si Git puede fusionar los cambios automáticamente, después haces:
```bash
git push origin main
```
---
Si aparece un error de "divergent branches"
En versiones recientes de Git puede pedirte especificar la estrategia:
```bash
git pull origin main --rebase
```
Luego:
```bash
git push origin main
```
---
Si hay conflictos
Git mostrará algo como:
```text
CONFLICT (content): Merge conflict in src/queue.c
```
En ese caso:
1. Editas los archivos con conflicto.
2. Eliminas las marcas:
```text
<<<<<<< HEAD
tu código
=======
código remoto
>>>>>>> rama-remota
```
3. Guardas.
4. Ejecutas:
```bash
git add .
git commit -m "Resolver conflictos"
git push origin main
```

## Errores encontrados
No encontramos errores.

## Correcciones realizadas
...

## Validaciones realizadas
Esto nos ayudo bastante, como estamos ttrabajando en equipo, y el repositorio se esta actualizando constantemente, a veces no llegamos a tener la versión mas actualizada al momento de trabajar simultaneamente.
___
# PROMPT 5

## Prompt utilizado
 Implementa memory_manager.c haciendo uso de las especificaciones de este .h (intoducimos el memory_manager.h que ya tenemos) y que sea capaz de funcionar al probarlo con el siguiente test (introducimos el test que viene en el github)

## Respuesta IA
Eso significa que mm_allocate_first_fit() no está devolviendo un PID, sino la dirección inicial (start) del bloque asignado.
Por lo tanto, mm_free() buscará el bloque usando ese valor como identificador.
Una implementación de memory_manager.c que cumple con el .h y pasa ese test sería: (nos dió memory_manager.c) 

## Errores encontrados
No dio errores

## Correciones realizadas
Se corrigió momentaneamente el test_memory_manager.c agregandole un main para poder probar nuestro codigo

## Validaciones realizadas
Como hay un test para memory_manager, decidimos realizar una prueba para nuestro codigo, sin embargo modificamos un poco el test para poder realizarlo, despues de comprobar que la implementación funciona bien, volvimos al test original para evitar errores
___

# PROMPT 6

## Promp utilizado
Ahora empezaremos a implementar el scheduler, dime con cual parte empezaremos y te doy los archivos anteriores necesarios para la implementación.

## Respuesta IA

El siguiente módulo que más valor aporta al proyecto es:

src/scheduler/fifo.c

¿Por qué?

Es el scheduler más sencillo.
Les permite empezar a simular procesos.
Después Round Robin será mucho más fácil porque reutiliza la lógica.

## Errores encontrados
Para implementarlo, se necesitaba el scheduler.h, process.h y test_scheduler.c al analizarlos, se notaron errores en la implementacion de scheduler. por lo que fueron corregidos para que la implementacion de fifo.c fuera correcta y coincida con nuestro test

## Correcciones Realizadas
Se cambió scheduler.h para que coincida con nuestro test para fifo.c, además se modificó temporalmente el test para probar la función entregada por la IA

## Validaciones realizadas
Usando el test_scheduler.c modificado, pudimos validar el correcto funcionamiento de nuestro fifo.c lo que a su vez confirma que scheduler.h ahora si estaba bien implementado

---

# PROMPT 7
No hay nada hecho para los archivos de Python, habría que hacerlos desde cero. La carpeta scripts debe contener:

- benchmark.py
- generate_processes.py
- graphs.py
- validate_results.py

Además es obligatorio usar matplotlib para las gráficas.

### Respuesta IA
La IA explicó la función esperada de cada script:

- generate_processes.py: generar conjuntos de procesos de prueba.
- benchmark.py: ejecutar y medir el rendimiento de los algoritmos.
- validate_results.py: verificar la consistencia de los resultados obtenidos.
- graphs.py: generar gráficas a partir de los datos recolectados utilizando matplotlib.

### Errores encontrados
- No existía implementación inicial para los scripts de análisis.
- No estaba claro el propósito de cada archivo.

### Correcciones realizadas
- Se definió la estructura base de la carpeta scripts.
- Se identificó matplotlib como dependencia obligatoria para la generación de gráficas.

### Validaciones realizadas
- Se verificó que la estructura de directorios coincidiera con la especificación del proyecto.

---

# PROMPT 8

## Prompt utilizado

¿Cómo implementar `graphs.py` para leer los resultados de `benchmark.csv` y generar gráficas usando matplotlib?

## Respuesta IA

La IA propuso utilizar `pandas` para leer el archivo CSV y `matplotlib` para generar una gráfica de líneas mostrando el tamaño de entrada contra el tiempo de ejecución.

También sugirió guardar la gráfica en:

```text
reports/png/benchmark.png
```

## Errores encontrados

Inicialmente la gráfica no se generaba porque la carpeta de destino no existía correctamente.

## Correcciones realizadas

Se verificó la estructura de carpetas dentro de `reports` y se corrigió la creación de directorios.

## Validaciones realizadas

Se ejecutó:

```bash
python3 scripts/graphs.py
```

y se comprobó la generación correcta de `benchmark.png`.

---

# PROMPT 9

## Prompt utilizado

Al ejecutar `graphs.py` no se genera ningún archivo PNG. ¿Cómo identificar el problema?

## Respuesta IA

La IA sugirió verificar:

* Existencia del archivo CSV.
* Ruta correcta del directorio de salida.
* Permisos de escritura.
* Mensajes de error de Python.

## Errores encontrados

La carpeta `reports/png` había sido creada accidentalmente como archivo en lugar de directorio.

## Correcciones realizadas

Se eliminaron los archivos incorrectos y se recreó la estructura:

```text
reports/
├── csv/
├── png/
└── pdf/
```

## Validaciones realizadas

La gráfica se generó correctamente después de corregir la estructura.

---

# PROMPT 10

## Prompt utilizado

¿Cómo implementar la operación de coalescencia dentro del administrador de memoria?

## Respuesta IA

La IA explicó que la coalescencia consiste en unir bloques libres adyacentes para reducir la fragmentación externa.

Se propuso recorrer la lista doblemente enlazada y fusionar bloques consecutivos marcados como libres.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se implementó `mm_coalesce()` dentro de `memory_manager.c`.

## Validaciones realizadas

Se recompiló el proyecto y las pruebas continuaron pasando correctamente.

---

# PROMPT 11

## Prompt utilizado

¿Cómo implementar la compactación de memoria respetando la estructura actual del proyecto?

## Respuesta IA

La IA sugirió desplazar los bloques ocupados hacia el inicio de la memoria y consolidar el espacio libre restante en un único bloque.

## Errores encontrados

La función no existía originalmente en la implementación.

## Correcciones realizadas

Se agregó `mm_compact()` al archivo `memory_manager.c` y su declaración correspondiente en `memory_manager.h`.

## Validaciones realizadas

La compilación mediante:

```bash
make
```

se realizó sin errores.

---

# PROMPT 12

## Prompt utilizado

Al ejecutar `make test` aparece un error indicando múltiples definiciones de `main`.

## Respuesta IA

La IA identificó que tanto `tests/main.c` como `src/main.c` estaban siendo enlazados simultáneamente.

## Errores encontrados

Error del linker:

```text
multiple definition of 'main'
```

## Correcciones realizadas

Se modificó el Makefile para excluir `src/main.c` durante la compilación de las pruebas.

## Validaciones realizadas

Las pruebas volvieron a ejecutarse correctamente utilizando:

```bash
make test
```
---

# PROMPT 13

## Prompt utilizado

Durante la implementación de `memory_manager.c`, ¿la función `mm_allocate_first_fit()` debe devolver el PID del proceso o la dirección inicial del bloque asignado?

## Respuesta IA

La IA explicó que, de acuerdo con la lógica utilizada en los tests proporcionados para el proyecto, la función no debía devolver un PID sino la dirección inicial (`start`) del bloque asignado.

Además indicó que posteriormente `mm_free()` utilizaría ese valor para localizar y liberar el bloque correspondiente.

## Errores encontrados

Existía confusión sobre qué valor debía devolver la función de asignación de memoria.

## Correcciones realizadas

Se modificó la implementación para devolver la dirección inicial del bloque asignado en lugar de un identificador de proceso.

## Validaciones realizadas

Se ejecutaron las pruebas del administrador de memoria y se comprobó que la asignación y liberación funcionaban correctamente.

---

# PROMPT 14

## Prompt utilizado

¿Cómo validar que la implementación de `mm_free()` libera correctamente los bloques de memoria sin afectar la estructura de la lista enlazada?

## Respuesta IA

La IA sugirió realizar pruebas liberando bloques previamente asignados y verificando que:

* El bloque cambiara a estado libre.
* Los bloques vecinos permanecieran intactos.
* La lista enlazada mantuviera su integridad.

También recomendó probar posteriormente la coalescencia para verificar el comportamiento conjunto.

## Errores encontrados

No existía una validación clara sobre el comportamiento de la liberación de memoria.

## Correcciones realizadas

Se realizaron pruebas utilizando bloques asignados previamente dentro del administrador de memoria.

## Validaciones realizadas

Las pruebas confirmaron que los bloques eran liberados correctamente y podían reutilizarse en futuras asignaciones.

---

# PROMPT 15

## Prompt utilizado

Al ejecutar `make test` aparece un error indicando múltiples definiciones de `main`. ¿Cómo solucionarlo?

## Respuesta IA

La IA identificó que el ejecutable de pruebas estaba compilando simultáneamente `tests/main.c` y `src/main.c`, provocando un conflicto durante el enlazado.

## Errores encontrados

El compilador mostraba un error similar a:

```text
multiple definition of 'main'
```

## Correcciones realizadas

Se modificó el Makefile para excluir `src/main.c` de la compilación de los tests y utilizar únicamente el archivo principal de pruebas.

## Validaciones realizadas

La ejecución de:

```bash
make test
```

volvió a completarse correctamente.

---

# PROMPT 16

## Prompt utilizado

¿Cómo adaptar el Makefile para compilar automáticamente los nuevos archivos de algoritmos implementados en `src/algorithms/`?

## Respuesta IA

La IA recomendó agregar los nuevos archivos fuente a la variable correspondiente del Makefile para que fueran incluidos durante la compilación del proyecto.

## Errores encontrados

Los archivos recién implementados no estaban siendo considerados por el sistema de compilación.

## Correcciones realizadas

Se actualizaron las rutas de compilación para incluir:

```text
brute_force.c
greedy.c
backtracking.c
divide_conquer.c
dp_topdown.c
dp_bottomup.c
incremental.c
```

## Validaciones realizadas

La compilación mediante:

```bash
make
```

se completó sin errores.

---

# PROMPT 17

## Prompt utilizado

¿Es necesario modificar el Makefile para compilar los módulos de utilidades (`logger.c`, `timer.c` y `parser.c`)?

## Respuesta IA

La IA explicó que todos los módulos utilizados por la simulación deben estar presentes en las reglas de compilación para evitar errores de referencias indefinidas durante el enlazado.

## Errores encontrados

Los módulos de utilidades aún no estaban integrados completamente en el proceso de compilación.

## Correcciones realizadas

Se añadieron los archivos de la carpeta `src/utils/` a las listas de compilación del proyecto.

## Validaciones realizadas

La compilación y ejecución de la simulación se realizaron correctamente después de integrar los módulos.

---

# PROMPT 18

## Prompt utilizado

¿Cómo verificar que el Makefile compila correctamente todo el proyecto antes de la entrega final?

## Respuesta IA

La IA recomendó ejecutar una secuencia completa de limpieza, compilación y pruebas:

```bash
make clean
make
make test
```

De esta forma era posible detectar errores de dependencias, archivos faltantes o problemas de enlazado.

## Errores encontrados

No se detectaron errores después de las modificaciones realizadas al Makefile.

## Correcciones realizadas

Se realizaron ajustes menores para mantener consistencia entre los módulos compilados y la estructura del proyecto.

## Validaciones realizadas

La compilación completa y la ejecución de pruebas finalizaron exitosamente.

---

# PROMPT 19

## Prompt utilizado

¿Cómo implementar `benchmark.py` para medir el rendimiento de la simulación y almacenar los resultados en un archivo CSV?

## Respuesta IA

La IA propuso desarrollar un script en Python capaz de:

* Ejecutar el simulador varias veces utilizando distintos tamaños de entrada.
* Medir los tiempos de ejecución utilizando el módulo `time`.
* Almacenar los resultados en una estructura de datos.
* Exportar los resultados a un archivo CSV mediante la biblioteca `pandas`.

La salida sugerida fue:

```text
reports/csv/benchmark.csv
```

con columnas similares a:

```text
size,time
100,0.00118
500,0.00136
1000,0.00113
5000,0.00145
```

## Errores encontrados

No existía una implementación inicial para realizar mediciones automáticas del rendimiento del simulador.

## Correcciones realizadas

Se desarrolló el archivo `benchmark.py` para ejecutar pruebas y almacenar los resultados obtenidos en formato CSV.

## Validaciones realizadas

Se ejecutó:

```bash
python3 scripts/benchmark.py
```

y se verificó la generación correcta del archivo:

```text
reports/csv/benchmark.csv
```

Posteriormente, dicho archivo fue utilizado como entrada para la generación de gráficas mediante `graphs.py`.

---

# PROMPT 20

## Prompt utilizado

La gráfica se genera correctamente en formato PNG, pero no aparece ningún archivo dentro de `reports/pdf`. ¿Cómo puedo generar también una versión PDF de la gráfica?

## Respuesta IA

La IA explicó que `matplotlib` permite exportar una misma figura en múltiples formatos utilizando `plt.savefig()`.

Sugirió agregar una segunda instrucción:

```python
plt.savefig(
    "reports/pdf/benchmark.pdf"
)
```

manteniendo la generación del archivo PNG existente.

## Errores encontrados

Inicialmente el script únicamente generaba:

```text
reports/png/benchmark.png
```

por lo que la carpeta `reports/pdf` permanecía vacía.

## Correcciones realizadas

Se modificó `graphs.py` para guardar la gráfica tanto en formato PNG como PDF.

## Validaciones realizadas

Se ejecutó:

```bash
python3 scripts/graphs.py
```

y se verificó la creación correcta de:

```text
reports/pdf/benchmark.pdf
```

---

# PROMPT 21

## Prompt utilizado

El archivo `benchmark.csv` fue generado correctamente. ¿Cómo interpretar los resultados obtenidos y verificar que los datos son válidos?

## Respuesta IA

La IA explicó que cada fila representa una ejecución de prueba donde:

* `size` corresponde al tamaño de entrada utilizado.
* `time` representa el tiempo de ejecución medido.

También indicó que era importante verificar:

* Que existieran múltiples tamaños de entrada.
* Que todos los tiempos fueran valores positivos.
* Que el archivo mantuviera un formato CSV válido.

Ejemplo:

```text
size,time
100,0.00118
500,0.00136
1000,0.00113
5000,0.00145
```

## Errores encontrados

Existían dudas sobre si los resultados obtenidos eran correctos y suficientes para generar gráficas.

## Correcciones realizadas

Se revisó manualmente el contenido de `benchmark.csv` y se confirmó que los datos tenían el formato esperado.

## Validaciones realizadas

Se utilizó posteriormente `graphs.py` para leer el archivo y generar gráficas sin errores, confirmando la validez de los datos generados.

---

# PROMPT 22

## Prompt utilizado

¿Cómo debería actualizarse `algorithms.h` para integrar todos los algoritmos requeridos por el proyecto?

## Respuesta IA

La IA sugirió ampliar la interfaz para incluir funciones correspondientes a fuerza bruta, greedy, backtracking, divide y vencerás y programación dinámica, manteniendo compatibilidad con los algoritmos de memoria ya implementados.

## Errores encontrados

El archivo inicialmente sólo contemplaba First Fit, Best Fit y Worst Fit.

## Correcciones realizadas

Se agregaron los prototipos necesarios para los algoritmos restantes.

## Validaciones realizadas

El proyecto continuó compilando correctamente después de actualizar la interfaz.

---

# PROMPT 23

## Prompt utilizado

¿Cómo implementar `brute_force.c` respetando la estructura del proyecto?

## Respuesta IA

La IA propuso una búsqueda exhaustiva de bloques de memoria recorriendo todos los bloques disponibles para localizar posibles asignaciones.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se creó el archivo `brute_force.c`.

## Validaciones realizadas

La compilación se realizó correctamente mediante:

```bash
make
```

---

# PROMPT 24

## Prompt utilizado

¿Cómo implementar `greedy.c` utilizando los algoritmos de asignación de memoria ya existentes?

## Respuesta IA

La IA explicó que First Fit, Best Fit y Worst Fit son ejemplos clásicos de algoritmos voraces (Greedy) y sugirió reutilizar la lógica ya desarrollada para representar esta estrategia.

## Errores encontrados

No existía una representación explícita del enfoque Greedy.

## Correcciones realizadas

Se implementó un archivo que integra los algoritmos de asignación como ejemplos de estrategia voraz.

## Validaciones realizadas

La compilación se realizó sin errores.

---

# PROMPT 25

## Prompt utilizado

¿Cómo implementar `backtracking.c` para representar una búsqueda de asignaciones válidas?

## Respuesta IA

La IA sugirió una implementación recursiva sencilla capaz de explorar distintas combinaciones de asignación y retroceder cuando una solución no es válida.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se desarrolló el archivo `backtracking.c` utilizando llamadas recursivas.

## Validaciones realizadas

La implementación compiló correctamente y se integró al proyecto.

---

# PROMPT 26

## Prompt utilizado

¿Cómo implementar `divide_conquer.c` para representar la estrategia Divide y Vencerás?

## Respuesta IA

La IA propuso dividir un conjunto de bloques de memoria en subproblemas más pequeños y resolverlos recursivamente antes de combinar los resultados.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se creó el archivo `divide_conquer.c`.

## Validaciones realizadas

El código se compiló sin conflictos con los demás módulos.

---

# PROMPT 27

## Prompt utilizado

¿Cómo implementar `dp_topdown.c` utilizando programación dinámica descendente?

## Respuesta IA

La IA explicó el enfoque Top-Down basado en memoización y llamadas recursivas para evitar cálculos repetidos.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se implementó un ejemplo funcional de programación dinámica descendente.

## Validaciones realizadas

La compilación se completó correctamente.

---

# PROMPT 28

## Prompt utilizado

¿Cómo implementar `dp_bottomup.c` utilizando programación dinámica ascendente?

## Respuesta IA

La IA propuso construir soluciones iterativamente desde casos simples hasta problemas más complejos mediante tablas de almacenamiento.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se desarrolló el archivo `dp_bottomup.c`.

## Validaciones realizadas

La implementación se integró correctamente al proyecto.

---

# PROMPT 29

## Prompt utilizado

¿Cómo implementar `incremental.c` para representar una estrategia incremental?

## Respuesta IA

La IA explicó que la estrategia incremental consiste en construir una solución paso a paso agregando elementos de forma progresiva.

## Errores encontrados

No existía implementación previa.

## Correcciones realizadas

Se creó el archivo `incremental.c`.

## Validaciones realizadas

El módulo compiló correctamente junto con los demás algoritmos.

---

# PROMPT 30

## Prompt utilizado

¿Es necesario modificar el Makefile para que los algoritmos recién implementados sean compilados automáticamente?

## Respuesta IA

La IA recomendó agregar los nuevos archivos fuente a las reglas de compilación para asegurar que formen parte del ejecutable principal y de las pruebas.

## Errores encontrados

Los nuevos archivos no estaban siendo considerados por el Makefile.

## Correcciones realizadas

Se actualizó la lista de archivos fuente utilizada por el sistema de compilación.

## Validaciones realizadas

La ejecución de:

```bash
make
make test
```

se completó correctamente.

---

# PROMPT 31

## Prompt utilizado

¿Cómo integrar correctamente el Scheduler y el Memory Manager dentro de una simulación básica del sistema operativo?

## Respuesta IA

La IA sugirió crear una simulación donde:

* Se inicialice el administrador de memoria.
* Se cree el scheduler FIFO.
* Se generen procesos de prueba.
* Se asigne memoria a cada proceso.
* Se ejecuten los procesos según el scheduler.

De esta manera se lograría una interacción básica entre ambos módulos principales.

## Errores encontrados

Los módulos funcionaban por separado, pero aún no existía una integración dentro de una simulación completa.

## Correcciones realizadas

Se desarrolló un `main.c` capaz de coordinar memoria, procesos y planificación.

## Validaciones realizadas

La simulación ejecutó correctamente los procesos y las asignaciones de memoria.

---

# PROMPT 32

## Prompt utilizado

¿Cómo utilizar el módulo `timer` para medir el tiempo total de ejecución de la simulación?

## Respuesta IA

La IA recomendó iniciar el cronómetro al comienzo de la simulación mediante:

```c
timer_start();
```

y finalizarlo con:

```c
double elapsed = timer_stop();
```

mostrando posteriormente el tiempo obtenido.

## Errores encontrados

No existía una medición directa del rendimiento de la simulación.

## Correcciones realizadas

Se integró el módulo `timer` dentro del programa principal.

## Validaciones realizadas

La simulación mostró correctamente el tiempo total de ejecución al finalizar.

---

# PROMPT 33

## Prompt utilizado

¿Cómo aprovechar el módulo `logger` para registrar eventos importantes de la simulación?

## Respuesta IA

La IA sugirió registrar eventos como:

* Inicio de simulación.
* Creación de procesos.
* Asignación de memoria.
* Liberación de memoria.
* Coalescencia.
* Compactación.
* Finalización de la simulación.

## Errores encontrados

Inicialmente no existía persistencia de eventos durante la ejecución.

## Correcciones realizadas

Se agregaron llamadas a `log_message()` en las etapas principales de la simulación.

## Validaciones realizadas

Los eventos comenzaron a registrarse correctamente durante la ejecución.

---

# PROMPT 34

## Prompt utilizado

La carpeta `data/logs` permanece vacía. ¿Cómo utilizarla dentro del proyecto?

## Respuesta IA

La IA recomendó emplear el módulo `logger` para generar automáticamente un archivo:

```text
data/logs/system.log
```

que almacenara información relevante de la simulación.

## Errores encontrados

La carpeta existía en la estructura del proyecto, pero no estaba siendo utilizada.

## Correcciones realizadas

Se integró el logger al flujo principal del simulador.

## Validaciones realizadas

Tras ejecutar la simulación se generó correctamente el archivo:

```text
data/logs/system.log
```

---

# PROMPT 35

## Prompt utilizado

¿Cómo documentar las estructuras de datos implementadas dentro del proyecto?

## Respuesta IA

La IA recomendó crear un documento describiendo:

* Stack.
* Queue.
* Circular Queue.
* Linked List.
* Doubly Linked List.

Además sugirió incluir aplicaciones y operaciones principales de cada estructura.

## Errores encontrados

No existía documentación técnica sobre las estructuras implementadas.

## Correcciones realizadas

Se desarrolló el archivo:

```text
docs/arquitectura/estructuras.md
```

## Validaciones realizadas

Se verificó que la documentación coincidiera con la implementación realizada.

---

# PROMPT 36

## Prompt utilizado

¿Cómo documentar el funcionamiento del sistema de memoria implementado?

## Respuesta IA

La IA sugirió describir:

* MemoryBlock.
* MemoryManager.
* First Fit.
* Best Fit.
* Worst Fit.
* Coalescencia.
* Compactación.

## Errores encontrados

No existía documentación específica para el módulo de memoria.

## Correcciones realizadas

Se elaboró el archivo:

```text
docs/arquitectura/memoria.md
```

## Validaciones realizadas

La documentación fue revisada y comparada con el código fuente correspondiente.

---

# PROMPT 37

## Prompt utilizado

¿Cómo documentar los algoritmos de planificación implementados en el proyecto?

## Respuesta IA

La IA recomendó describir:

* FIFO.
* SJF.
* Round Robin.
* Estados de proceso.
* Cola de listos.

También sugirió incluir diagramas sencillos de flujo de ejecución.

## Errores encontrados

No existía documentación sobre el scheduler.

## Correcciones realizadas

Se creó el archivo:

```text
docs/arquitectura/scheduler.md
```

## Validaciones realizadas

La documentación fue contrastada con las implementaciones existentes.

---

# PROMPT 38

## Prompt utilizado

¿Qué información debería incluir el reporte final del proyecto?

## Respuesta IA

La IA sugirió incluir:

* Objetivos.
* Arquitectura general.
* Estructuras de datos.
* Gestión de memoria.
* Planificación de procesos.
* Algoritmos implementados.
* Resultados experimentales.
* Conclusiones.

## Errores encontrados

No existía una estructura inicial para el reporte final.

## Correcciones realizadas

Se definió la organización general del documento.

## Validaciones realizadas

La estructura cubría todos los requerimientos solicitados por el proyecto.

---

# PROMPT 39

## Prompt utilizado

¿La estructura final del repositorio cumple con las especificaciones proporcionadas para el proyecto?

## Respuesta IA

La IA comparó la estructura desarrollada con la estructura oficial propuesta y verificó la existencia de:

* include/
* src/
* tests/
* scripts/
* reports/
* data/
* docs/

además de los archivos principales requeridos.

## Errores encontrados

Se detectaron inicialmente carpetas creadas como archivos dentro de `reports`.

## Correcciones realizadas

Se corrigió la estructura de directorios y se verificó nuevamente el árbol completo.

## Validaciones realizadas

La organización final coincidió con la especificación del proyecto.

---

# PROMPT 40

## Prompt utilizado

¿Qué verificaciones finales deberían realizarse antes de la entrega del proyecto?

## Respuesta IA

La IA recomendó ejecutar una validación completa mediante:

```bash
make clean
make
make test

./bin/main 1000

python3 scripts/benchmark.py
python3 scripts/graphs.py
python3 scripts/validate_results.py
```

Además sugirió revisar:

* Logs generados.
* Reportes CSV.
* Gráficas PNG.
* Reportes PDF.
* Documentación.

## Errores encontrados

No se detectaron errores críticos durante la validación final.

## Correcciones realizadas

Se realizaron ajustes menores de documentación y organización de archivos.

## Validaciones realizadas

El proyecto compiló, ejecutó pruebas y generó resultados correctamente, quedando listo para su entrega.


