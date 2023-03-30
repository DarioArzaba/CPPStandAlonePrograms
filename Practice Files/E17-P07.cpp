/*
Elabore el juego del “Puzzle”, dicho juego consiste en acomodar los 15 número del cuadro de una forma ordenada, 
puede ser: horizontal, vertical o caracol.
Para ello coloque los valores del 1 al 15 dentro de la matriz al azar, por ejemplo:
14	3	1	7
	4	6	9
8	15	12	2
5	10	11	13
Una vez que ha colocado los valores despliegue la matriz dentro de un cuadro.
Ahora debe solicitar una par de valores que estén entre 1 y 15 y deben ser diferentes entre sí, por ejemplo 7,5. 
Una vez recibidos los valores su programa debe intercambiar dichos valores en las celdas correspondientes, OBSERVE:
14	3	1	5
	4	6	9
8	15	12	2
7	10	11	13
El valor 7 y el 5 han sido intercambiados.
Este proceso se debe reptir hasta que el usuario haya completado una de las soluciones del puzzle.
VERTICAL:
1	5	9	13
2	6	10	14
3	7	11	15
4	8	12	
HORIZONTAL:
1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	
CARACOL:
1	2	3	4
12	13	14	5
11		15	6
10	9	8	7
*/
