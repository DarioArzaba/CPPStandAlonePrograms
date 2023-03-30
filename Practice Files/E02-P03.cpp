
/*
Desplegar el resultado de las cuatro operaciones fundamentales. Elabore un programa que defina tres variables enteras x, y, r.
Que le asigne un valor de 5 a la variable x, un valor de 10 a la variable y.
Posteriormente debe hacer la suma y desplegar el resultado de la suma. La resta y desplegar el resultado de la resta.
La multiplicación y desplegar el resultado de la multiplicación. Por último debe hacer la división y desplegar el resultado de la división:
	
	La suma de 5 más 10 es: 15
	La resta de 5 menos 10 es: -5
	La multiplicación de 5 por 10 es: 50
	La división de 5 entre 10 es: 0

Donde los valores de 5, 10 y los resultados cambiaran en el letrero conforme cambie los valores de las variables x y y dentro de su programa.
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
	r = x - y;
	printf("\nLa resta de 5 menos 10 es: %d", r);
	r = x * y;
	printf("\nLa multiplicaci%cn de 5 por 10 es: %d", 162, r);
	double r2 = double(x) / double(y);
	printf("\nLa divisi%cn de 5 entre 10 es: %.2f", 162, r2);
	
	_getche();
	return 0;
}
