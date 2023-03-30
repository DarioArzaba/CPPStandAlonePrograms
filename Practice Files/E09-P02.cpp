/*
Elabore un programa en “C” que construya una tabla de conversión de pesos a dólares iniciando en 5 pesos y terminando en 100.
Avanzando los pesos de 5 en 5, su tabla debe verse como la del ejercicio de la presentación 12.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double dolares;
	double precioDolar = 13.65;
	printf("     Pesos           D%clares", 162);
	printf("\n ****************************");
	double pesos = 5;
	while (pesos <= 100) {
		
		dolares = (pesos/precioDolar);

		if (pesos == 5) {
			printf("\n     $%.1f            $%.1f", pesos, dolares);
		} else if (pesos == 100) {
			printf("\n     $%.1f          $%.1f", pesos, dolares);
		} else {
			printf("\n     $%.1f           $%.1f", pesos, dolares);
		}
		
		pesos += 5;
	}

	_getche();
	return 0;
}
