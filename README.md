# push_swap

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

### 3. Seleccionar método de ordenación:
Una vez se han validado los argumentos y se puede proceder a la ordenación, comprobamos cuantos números tenemos para ordenar:

> [!TIP]
> Sean cuantos sean los números, si comprobamos que nos los han pasado ya ordenados, salimos sin más.

- Si tenemos un único número, simplemente salimos ya que no hay que ordenar.
- Si tenemos dos números desordenados, hacemos **sa**.
- Si tenemos tres números desordenados, comprobaremos si hacer **sa**, **ra** y/o **rra**.
- Si tenemos más de tres números, procedemos a iniciar el algoritmo turco.

### 4. El algoritmo turco.

1. Pasamos al stack a los primeros dos nodos, siempre y cuando en el stack a queden 3 números. Es decir, si sólo tenemos 4 números, sólo pasamos 1 número.
2. Emparejamos cada nodo del stack a con el siguiente nodo <u> más pequeño <u> del stack b.



