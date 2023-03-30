/*
Una persona desea obtener su credencial del INSEN (Instituto Nacional de la Senectud).
Con esta credencial tiene acceso a descuentos en varias tiendas de autoservicio. 
Para poder obtener la credencial la persona debe tener 60 años o más de edad.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int edad;
	printf("Introduzca su edad: "); scanf("%d", &edad);
	if (edad >= 60) {
		printf("\nTiene la edad requerida para obtener una credencial del INSEN.");
	} else {
		printf("\nNo tiene la edad requerida para obtener una credencial del INSEN.");
	}

	_getche();
	return 0;
}
