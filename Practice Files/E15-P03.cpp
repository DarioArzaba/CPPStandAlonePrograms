/*
Escribir un programa que tras asignar los números, -2, 5, 8, -9, 10, 15 y –4 a un arreglo calcule,
independientemente, la suma de los elementos positivos y negativos
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> suma;
	int input = -1;
	bool dejarPedir = false;
	int textCounter = 0;
	printf("Bienvenido. \n\n Introduzca cero (0) para dejar de pedir numeros.\n\n");
	while (dejarPedir == false) {
		textCounter++;
		printf("Introduzca un numero entero (%d) al arreglo: " ,textCounter);
		scanf("%d", &input);
		if (input == 0) { dejarPedir = true; break; }
		suma.push_back(input);
	}
	printf("Arreglo: ");
	for (int i = 0; i < suma.size(); ++i) {
		printf("%d , ", suma[i]);
	}
	printf("\b\b ");

	sort(suma.begin(), suma.end());

	printf("\nSuma Negativos: ");
	int resultado = 0;
	for (int i = 0; i < suma.size(); ++i) {
		if (suma[i] < 0) {
			resultado += suma[i];
		}
	}
	printf(" %d", resultado);
	resultado = 0;
	printf("\nSuma Positivos: ");
	for (int i = 0; i < suma.size(); ++i) {
		if (suma[i] > 0) {
			resultado += suma[i];
		}
	}
	printf(" %d", resultado);
	_getche();
	return 0;
}
