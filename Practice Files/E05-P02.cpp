/*
Una persona desea obtener su credencial de elector en la ciudad de Toluca.
Para poder obtener su credencial en esta ciudad la persona debe tener 18 años o más de edad y vivir en la ciudad de Toluca.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int edad, viveToluca;
	
	printf("Introduzca su edad : "); scanf("%d", &edad);
	printf("Actualmente recide en Toluca? 1 = Si , 2 = No");
	printf("\nRespuesta : "); scanf("%d", &viveToluca);
	
	if (edad >= 18 && viveToluca == 1) {
		printf("\nCumple con los requisitos para obtener una credencial de elector.");
	} else {
		printf("\nNo cumple con totos los requisitos para obtener una credencial de elector.");
	}

	_getche();
	return 0;
}
