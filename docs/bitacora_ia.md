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