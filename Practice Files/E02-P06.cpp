/*
De dólares a pesos. Sabiendo que el dólar tiene un valor de 13.65 pesos elabore una tabla de conversión 
de dólares a pesos avanzando de 10 en 10. Su tabla debe verse de la siguiente forma:

	Dólares	Pesos
	*****************
	10		136.5
	20		273
	30		409.5
	40		546
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double dolares = 10;
	double precioDolar = 13.65;
	double pesos = (dolares*precioDolar);
	printf("   D%clares        Pesos", 162);
	printf("\n ************************");
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 20; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 30; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 40; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 50; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 60; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 70; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 80; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 90; pesos = (dolares*precioDolar);
	printf("\n   %.1f           %.1f", dolares, pesos); dolares = 100; pesos = (dolares*precioDolar);
	printf("\n   %.1f          %.1f", dolares, pesos);
	
	_getche();
	return 0;
}
