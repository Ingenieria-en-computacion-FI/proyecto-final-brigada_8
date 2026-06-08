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
