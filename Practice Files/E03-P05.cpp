/*
Desplegar el resultado de las cuatro operaciones fundamentales
Elabore un programa que lea dos valores flotantes proporcionados por el usuario.
Posteriormente despliegue el resultado de la suma, resta, multiplicación y división de dichos valores.
Mostrar cada resultado en una línea de salida diferente, su salida debe verse así:
	La suma de 5 más 10 es: 15
	La resta de 5 menos 10 es: -5
	La multiplicación de 5 por 10 es: 50
	La división de 5 entre 10 es: 0
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double x, y, r;
	printf("Introdusca el Primer Valor    : "); scanf("%lf", &x);
	printf("Introdusca el Segundo Valor : "); scanf("%lf", &y);
	r = x + y;
	printf("\n La suma de %.1f m%cs %.1f es :  %.1f", x, 160, y, r);
	r = x - y;
	printf("\n La resta de %.1f menos %.1f es :  %.1f", x, y, r);
	r = x * y;
	printf("\n La multiplicaci%cn de %.1f por %.1f es :  %.1f", 162, x, y, r);
	r = x / y;
	printf("\n La divisi%cn de %.1f entre %.1f es :  %.1f", 162, x, y, r);

	_getche();
	return 0;
}
