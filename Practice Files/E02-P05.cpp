/*
De grados Centígrados a grados Farenheit. Sabiendo que la fórmula para convertir de grados centígrados a farenheit es:

	°F = ((°C*9)/5)+32

Elabore una tabla de conversión de °C a °F avanzando de 10 en 10, su tabla debe verse de la siguiente forma:

	°C		°F
	****************
	10		50
	20		68
	30		86
	40		104
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double centigrados = 10;
	double fareheit = ((centigrados * 9) / 5) + 32;
	printf("  %cC         %cF", 248, 248);
	printf("\n ****************");
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 20; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 30; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 40; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 50; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 60; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 70; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 80; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 90; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f         %.0f", centigrados, fareheit); centigrados = 100; fareheit = ((centigrados * 9) / 5) + 32;
	printf("\n  %.0f        %.0f", centigrados, fareheit);
	
	_getche();
	return 0;
}
