/*
Para determinar el área de un círculo la fórmula es: area = pi  * r^2 Pida el valor del radio y muestre el área del círculo.
si el usuario proporciona un valor menor o igual que cero NO determine el área y muestre un mensaje de error.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {

	//Agrege la libreria math.h 
	
	const double PI = 3.1415926535897;
	double radio, areaCirculo;
	printf("Introduzca el Radio del Circulo : "); scanf("%lf", &radio);

	if (radio > 0) {
		areaCirculo = PI * pow(radio, 2.0);
		printf("\nArea del Circulo : %.3f", areaCirculo);
	} else {
		printf("\nError. El radio no puede ser negativo o cero!");
	}

	_getche();
	return 0;
}
