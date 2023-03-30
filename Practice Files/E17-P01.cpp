/*
Lea 9 valores enteros entre 1 y 999 (incluidos) en un arreglo de dos dimensiones (3X3), 
despliegue la matriz en pantalla dentro de un cuadro, debe verse:
125	32	1
18	345	21
57	88	91
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
				printf("\nError. El numero no esta entre %d y %d", rangoMin, rangoMax);
				printf("Introduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &numero);
			}
			matriz[i][j] = numero;
		}
	}
	printf("\n\n");
	printf("   -------------------------------------------\n");
	for (int i = 0; i < maxFilas; i++) {
		printf("   |");
		for (int j = 0; j < maxColumnas; j++) {
			printf("     %d     | ", matriz[i][j]);
		}
		printf("\n");
		printf("   -------------------------------------------\n");
	}
	_getche();
	return 0;
}
