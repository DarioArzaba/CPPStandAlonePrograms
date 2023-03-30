/*
Lea la edad de una persona y determine si es mayor de edad o no lo es.
Eecuerde que una persona se considera mayor de edad si tiene 18 años o más. 
Muestre un mensaje en pantalla que indique el resultado, en este mismo programa ahora determine si la persona es adulto mayor o no.
Recuerde que un adulto mayor debe tener 60 años o más de edad. En este caso se deben ver dos letreros.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int edad;
	printf("Introduzca su Edad : "); scanf("%d", &edad);

	if (edad >= 18 && edad >= 60) {
		printf("\nEres mayor de edad.");
		printf("\nEres un adulto mayor.");
	} else if (edad >= 18 && edad < 60) {
		printf("\nEres mayor de edad.");
	} else {
		printf("\nNo eres mayor de edad.");
	}

	_getche();
	return 0;
}
