/*
Repita el ejercicio “1” pero ahora después de desplegar la matriz solicite un valor, posteriormente busque dicho valor en la matriz,
si el valor NO existe en la matriz, despliegue un mensaje de error y regrese a solicitar el valor. 
En caso de que el valor si exista despliegue las coordenadas de donde se encuentra el valor, 
por ejemplo si nos indican el valor “88” la coordenadas son (1,2).
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

int main() {
	const int filas = 3, columnas = 3;
	int maxFilas = filas, maxColumnas = columnas;
	int matriz[filas][columnas];
	int rangoMin = 1, rangoMax = 999;
	int numero;
	printf("\n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("Introduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &numero);
			while (numero > rangoMax || numero < rangoMin) {
				printf("Error. El numero no esta entre %d y %d\n", rangoMin, rangoMax);
				printf("Introduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &numero);
			}
			matriz[i][j] = numero;
		}
	}
	printf("\n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("       %d      ", matriz[i][j]);
		}
		printf("\n");
	}

	int valor;
	bool repetir = true; bool encontrado = false;
	while (repetir == true) {
		printf("\n\nIntroduzca un valor (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &valor);
		while (valor > rangoMax || valor < rangoMin) {
			printf("Error. El valor no esta entre %d y %d\n", rangoMin, rangoMax);
			printf("Introduzca un valor (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &valor);
		}
		for (int i = 0; i < maxFilas; i++) {
			for (int j = 0; j < maxColumnas; j++) {
				if (valor == matriz[i][j]) {
					printf("\nEl valor se encontro en la coordenada (%d, %d).", j, i);
					encontrado = true;
					repetir = false;
				}
			}
		}
		if (encontrado == false) {
			printf("\nError. El valor no se encontro en la matriz.");
			repetir = true;
		}
	}
	
	_getche();
	return 0;
}
