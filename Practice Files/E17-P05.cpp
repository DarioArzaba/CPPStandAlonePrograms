/*
Lea 9 valores enteros entre 1 y 999 (incluidos) en una matriz de 3X3, posteriormente despliegue la matriz 
agregando una columna en la que debe mostrar los resultados de la suma de cada uno de los renglones, 
al final agregue un renglón en el que deberá mostrar la suma de cada una de las columnas, debe verse de la siguiente forma:
25	21	48	94
31	5	16	52
10	21	57	88
66	47	121	X
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

	int matrizUno[filas][columnas];

	int rangoMin = 1, rangoMax = 999;

	int numero, contador = 0;
	
	printf("\n - Suma de Columnas y Filas - \n\n");

	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			contador++;
			printf("%d.- Introduzca un numero (Entre %d y %d) : ", contador, rangoMin, rangoMax);
			scanf("%d", &numero);
			while (numero > rangoMax || numero < rangoMin) {
				printf("Error. El numero no esta entre %d y %d\n", rangoMin, rangoMax);
				printf("%d.- Introduzca un numero (Entre %d y %d) : ", contador, rangoMin, rangoMax);
				scanf("%d", &numero);
			}
			matrizUno[i][j] = numero;
		}
	}
	
	printf("\n");

	int suma;

	for (int i = 0; i < maxFilas; i++) {
		
		for (int j = 0; j < maxColumnas; j++) {
			printf("       %d      ", matrizUno[i][j]);
		}

		suma = (matrizUno[i][0])+(matrizUno[i][1])+(matrizUno[i][2]);
		
		printf("       %d      ", suma);

		printf("\n");
	}

	for (int i = 0; i < maxColumnas; i++) {

		suma = (matrizUno[0][i]) + (matrizUno[1][i]) + (matrizUno[2][i]);
		printf("       %d      ", suma);
	
	}

	printf("       X      ");

	_getche();
	return 0;
}
