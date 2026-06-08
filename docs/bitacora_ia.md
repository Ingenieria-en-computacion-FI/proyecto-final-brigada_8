# Bitácora IA

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
## Prompt utilizado
¿La implementación de los archivos.h faltantes son correctoos respetandoo la estructura del proyecto? (le pasamos los archivos .h correspondientes)

## Respuesa IA
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
