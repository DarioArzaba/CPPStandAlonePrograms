/*
Para determinar la forma de una figura lea el valor de la base y el valor de la altura.
Si son iguales se trata de un cuadrado, de lo contrario se trata de un rectángulo. 
Muestre un mensaje en pantalla que indique el resultado.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double base, altura;
	printf("Introduzca la Base : "); scanf("%lf", &base);
	printf("Introduzca la Altura : "); scanf("%lf", &altura);

	if (base == altura) {
		printf("\nLa figura es un cuadrado!");
	} else {
		printf("\nLa figura es un rectangulo!");
	}

	_getche();
	return 0;
}
