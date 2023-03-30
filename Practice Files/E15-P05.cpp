/*
Que lea 10 números por teclado, los almacene en un array y muestre la suma, resta, multiplicación y división de todos.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

int main() {
	vector<int> operaciones;
	int input, suma = 0, resta = 0, mult = 1;
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		printf("Introduzca un numero entero al arreglo (%d) : ", (i+1));
		scanf("%d", &input);
		operaciones.push_back(input);
	}
	printf("\n\nArreglo: ");
	for (int i = 0; i < operaciones.size(); ++i) {
		printf("%d , ", operaciones[i]);
	}
	double div = operaciones[0];
	printf("\b\b ");
	for (int i = 0; i < operaciones.size(); ++i) {
		suma += operaciones[i];
		if (i == 0) {
			resta += operaciones[i];
		} else {
			resta -= operaciones[i];
		}
		mult *= operaciones[i];
		if (operaciones[i] != 0) {
			div = (div)/(double)(operaciones[i]);
		}
	}
	printf("\n\nSuma: %d", suma);
	printf("\nResta: %d", resta);
	printf("\nMultiplicacion: %d", mult);
	printf("\nDivision: %.15f", div);

	_getche();
	return 0;
}
