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



