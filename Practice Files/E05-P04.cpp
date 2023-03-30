/*
Un alumno que tiene beca sabe que su beca será suspendida si tiene un promedio menor que 80.
Su beca será condicionada si tiene un promedio mayor o igual que 80 y menor que 85.
Su beca se mantendrá igual si tiene un promedio mayor o igual que 85 y menor que 90.
Su beca será incrementada si tiene un promedio mayor o igual que 90.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double promedio;
	printf("Introduzca su promedio : "); scanf("%lf", &promedio);

	if (promedio < 80) {
		printf("\nLo sentimos, su beca a sido suspendida.");
	} else if (promedio >= 80 && promedio < 85) {
		printf("\nLo sentimos, su beca a sido condicionada.");
	} else if (promedio >= 85 && promedio < 90) {
		printf("\nSu beca se mantendra igual con el promedio actual.");
	} else if (promedio >= 90 && promedio <= 100) {
		printf("\nFelicidades, su beca ha sido incrementada.");
	} else {
		printf("\nError. Promedio no valido.");
	}

	_getche();
	return 0;
}
