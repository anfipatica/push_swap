# push_swap
- [Resumen](#resumen)
- [Recursos Útiles](#recursos-útiles)
- [Explicación del proyecto](#explicación-del-proyecto)
   - [1. Validación de datos](#1-validación-de-datos)
   - [2. Movimientos](#2-movimientos)
   - [3. Qué son los stacks](#3-qué-son-los-stacks)
   - [4. Seleccionar método de ordenación](seleccionar-método-de-ordenación)
   - [5. El algoritmo turco](#5-el-algoritmo-turco)
- [Consejos](#consejos)

## RESUMEN:
Este proyecto consiste en implementar un algoritmo de ordenación lo más eficiente posible, partiendo de una serie de bases:

1. Los números se encuentran en un "Stack A" y disponemos de un "Stack B" para ayudarnos con la ordenación.
2. Para pasar un número a otro stack, se debe encontrar en la primera posición de su stack.
3. Para colocar un número en la primera posición, podemos: Intercambiar el 1er y 2o número, colocar el primer número al final, o colocar el último número al principio.

## RECURSOS ÚTILES:

Recursos que utilicé durante la realización del proyecto:
- [Video de Thuggonaut explicando el proyecto y el algoritmo turco](https://www.youtube.com/watch?v=wRvipSG4Mmk)
- [Artículo escrito por A. Yigit Ogun explicando cómo funciona el algoritmo turco.](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [El tester creado por gemartin99](https://github.com/gemartin99/Push-Swap-Tester)

## EXPLICACIÓN DEL PROYECTO:
### 1. Validación de datos:
Una parte muy importante del programa es la validación de los datos, es decir, comprobar que los argumentos que le pasa el usuario a nuestro programa son válidos.
Sólo podemos recibir argumentos numéricos, números enteros sin repetir, con o sin comillas, separados por al menos un espacio. Si dentro de un argumento se encuentra algo diferente a espacios o números, o si no se encuentra ningún número, pasa a ser un argumento no válido.

Ejemplos de argumentos válidos:
- `"1 5 2"`
- `"      1     5    "       2`
- `1 5 2`

Ejemplos de argumentos **no** válidos:
- `""` -> Aunque esté vacío, es un argumento. ¿Contiene números? No. No es válido.
- `"      "` -> Los espacios están permitidos como separador entre números, si no hay números, no es un argumento válido.
- `" 1 5 2 a "` -> Una letra es un caracter no permitido.
- `" 1 5 2" "    "` -> Aquí estamos recibiendo dos argumentos, el primero es válido pero el segundo no, ergo el programa debe mostrar error.
- `" 1 1 5 2 "` -> Números duplicados!!

Comentándolo con compañeros hay cierto debate al respecto de cómo actuar con los argumentos "" o "    ". Al final, la decisión de cómo actuar es propia de cada uno y si está bien argumentado se puede defender en la corrección, pero como aviso, el checker proporcionado por 42 los toma como argumentos inválidos.

### 2. Movimientos:
Los movimientos permitidos por el subject son los siguientes, divididos en tres clases:

>*Cuando en los movimientos haya una **?** indica que el mismo movimiento existe tanto para el stack A como para el stack B*

#### 1. Rotación (rotate):
- r?: Coloca el nº en la primera posición del stack en la última. El nº en la 2a posición pasa a la primera, y el último se convierte en penúltimo.
- rr?: Coloca el último nº del stack en la primera posición. El penúltimo pasa al último lugar y el primero se convierte en segundo.
- rr: realiza r? en ambos stacks a la vez.
- rrr: realiza rr? en amos stacks a  la vez.

#### 2. Intercambio (swap):
- s?: Intercambia el primer y segundo número del stack especificado.
>*Como dato, con el algoritmo turco no utilizamos más que **sa** cuando tenemos dos o tres números*

#### 3. Empujar (push):
- pa: Coloca el primer nodo del stack B en el principio del stack A.
- pb: Coloca el primer nodo del stack A en el principio del stack B.

### 3. Qué son los stacks:
Como todo en la programación, no hay una única manera de resolver un problema, por lo que este planteamiento de push_swap es uno más de tantos válidos.

En este caso, he trabajado los stacks como listas doblemente enlazadas. Si en la libft hiciste el bonus te sonarán de algo, pero hasta este proyecto no llegas a entender las listas en su totalidad.

Cada nodo se trata de una estructura en la cual almaceno:
- el valor del número.
- La posición del número en el stack.
- el coste que tendrá mover ese nodo cuando le corresponda.
- una serie de punteros a diferentes nodos:
   - Al siguiente nodo de la lista (next).
   - Al nodo anterior de la lista (prev).
   - Al nodo de la cola de la lista.
   - Al nodo con que le emparejemos en cada movimiento.

Mover los nodos consiste básicamente en modificar a donde apuntan los punteros next y prev, y actualizar los índices de toda la lista.


### 4. Seleccionar método de ordenación:
Una vez se han validado los argumentos y se puede proceder a la ordenación, comprobamos cuantos números tenemos para ordenar:

> [!TIP]
> Sean cuantos sean los números, si comprobamos que nos los han pasado ya ordenados, salimos sin más.

- Si tenemos un único número, simplemente salimos ya que no hay que ordenar.
- Si tenemos dos números desordenados, hacemos **sa**.
- Si tenemos tres números desordenados, comprobaremos si hacer **sa**, **ra** y/o **rra**.
- Si tenemos más de tres números, procedemos a iniciar el algoritmo turco.

### 5. El algoritmo turco.

> [!TIP]
> Recomiendo ver el vídeo de Thuggonaut o leer el artículo original, enlazados en la sección de recursos, para ver sus explicaciones del algoritmo. No obstante, a continuación dejo mi explicación.

1. Pasamos al stack a los primeros dos nodos, siempre y cuando en el stack a queden 3 números. Es decir, si sólo tenemos 4 números, sólo pasamos 1 número.

2. Emparejamos cada nodo del stack a con el siguiente nodo ***más pequeño*** del stack b.
     2.1 Si no encontramos un nodo más pequeño, lo emparejamos con el nodo más grande de todo el stack b.

3. Una vez emparejados, calculamos el coste de colocar ambos nodos en la cabeza de su respectivo stack + el movimiento del push.
     3.1 Si encontramos un coste de 1 o de 2, dejamos de calcular y movemos directamente esos nodos. Si no, seleccionamos los nodos con el coste más barato.

4. Repetimos el paso 2 y 3 hasta que en el stack A sólo queden 3 nodos. En ese momento ordenamos esos 3 nodos y procedemos a pushear desde el stack b.

5. Para pasar de vuelta los nodos al stack A tenemos que volver a emparejar nodos, pero en esta ocasión emparejamos con el siguiente nodo ***más grande*** del stack a.
     5.1. Si no encontramos un nodo más grande, emparejamos con el nodo más pequeño de todo el stack a.

6. Repetimos el proceso de calcular costes y movemos.

7. Cuando hayamos vaciado todo el stack B, tendremos el stack A casi ordenado. Lo más probable es que el número más grande y el más pequeño estén colindantes. Calculamos la posición del nodo más pequeño y en base a eso detectamos si es más rentable hacer **ra** o **rra**, y lo hacemos hasta que el nodo más pequeño esté en la cabeza de la lista.

8. Si todo está bien, deberíamos tener nuestra lista ya ordenada.

## Consejos:

- Si puedo dar algún consejo respecto a este proyecto, sería que no descuides la validación de datos. El testeo del parseo en las evaluaciones será exhaustivo y si está mal no importa lo eficiente que sea el algoritmo. Prueba más cosas de las que prueba el tester ya que hay casos que no contempla.

- Antes de empezar a plantear el algoritmo, familiarízate con las listas. Prueba a crear listas, a imprimir sus valores, a quitar y añadir nodos... Después implementa los movimientos, empieza a pasar nodos de un stack a otro, no con el objetivo de ordenar sino de que todo va funcionando correctamente. Cuando ya tengas todo esto claro, comienza el siguiente desafío que es programar el algoritmo.

- Si tienes dificultades para entender algo, dibújalo. Si no tienes una tablet, usa paint, excalidraw, boli y papel... dibuja los nodos con sus punteros y cambia hacia donde apuntan en cada movimiento. Si usas un medio digital mueve físicamente el nodo. Hasta que no hice esto no terminó de hacerme click el funcionamiento de cada movimiento y creo que puede ayudar mucho si te está costando.

- No dejes que la frustración pueda contigo. El algoritmo turco es complejo de codear pero no es imposible, y es muy reconfortante ver su eficiencia como fruto del esfuerzo.

