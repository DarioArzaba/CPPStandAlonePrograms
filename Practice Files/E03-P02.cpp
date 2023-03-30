/*
Leer y desplegar una variable entera y una flotante
Elabore un programa que defina una variable entera x, y una variable flotante y.
Lea dos valores que le proporcione el usuario, uno entero y uno flotante.
Posteriormente despliegue los valores capturados por el usuario indicando cual es el entero y cual el flotante
Use dos líneas de salida distintas para esto.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x;
	double y;
	printf("Introdusca un Valor Entero:  "); scanf("%d", &x);
	printf("Introdusca un Valor Flotante:  "); scanf("%lf", &y);
	printf("\nValor Entero Introducido: %d", x);
	printf("\nValor Flotante Introducido: %.2f", y);
	
	_getche();
	return 0;
}
