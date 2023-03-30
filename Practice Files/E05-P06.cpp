/*
Una empresa inmobiliaria que vende casas ofrece a sus clientes la posibilidad de adquirir una casa con un 10% de enganche 
y mensualidades fijas, para ello la empresa pide como requisitos que el aspirante a la compra de la casa tenga al menos:
5 años de antigüedad en su empleo y un ingreso mensual mínimo de  $ 15,000 pesos.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int antiguedadEmpleo;
	double ingresoMensual, costoCasa, enganche;
	printf("Introduzca el costo de la casa : "); scanf("%lf", &costoCasa);
	printf("Introduzca la cantidad de a%cos en su empleo actual : ", 164); scanf("%d", &antiguedadEmpleo);
	printf("Introduzca su ingreso mensual  : "); scanf("%lf", &ingresoMensual);

	if (antiguedadEmpleo >= 5 && ingresoMensual >= 15000) {
		enganche = (costoCasa*(double(10) / 100));
		printf("\nFelicidades, usted puede adquirir una casa con $%.2f de enganche y meses fijos.", enganche);
	} else if (antiguedadEmpleo >= 0 && ingresoMensual >= 1) {
		printf("\nLo sentimos, no cumple con los requisitos para tramitar una casa.");
	} else {
		printf("Error. Valores incorrectos.");
	}
	
	_getche();
	return 0;
}
