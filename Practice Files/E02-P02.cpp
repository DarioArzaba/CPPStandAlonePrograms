/*
Desplegar el resultado de la suma. Elabore un programa que defina tres variables enteras x, y, r.
Que le asigne un valor de 5 a la variable x, un valor de 10 a la variable y.
Posteriormente debe hacer la suma de los valores x y y en r, es decir, r=x+y.
Para terminar su programa deberá desplegar el mensaje:

	La suma de 5 más 10 es: 15

Donde los valores de 5, 10 y 15 cambiaran en el letrero conforme cambie los valores de las variables x y y dentro de su programa.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x = 5;
	int y = 10;
	int r = x + y;
	printf("La suma de 5 m%cs 10 es: %d", 160, r);
	
	_getche();
	return 0;
}
