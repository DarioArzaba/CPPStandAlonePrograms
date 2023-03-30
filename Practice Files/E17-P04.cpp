/*
Lea 9 valores enteros entre 1 y 999 (incluidos) en un arreglo de dos dimensiones (3X3), 
repita la acción en un segundo arreglo de 3X3. En un tercer arreglo guarde la suma de los valores de las dos matrices anteriores. 
Finalmente despliegue las tres matrices. Debe verse de la siguiente forma:
Primera Matriz
25	21	48
31	5	16
10	21	57
Segunda Matriz
16	1	12
30	25	61
100	200	215
Resultados
41	22	60
61	30	77
110	221	272
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
	int matrizDos[filas][columnas];
	int matrizTres[filas][columnas];
	int rangoMin = 1, rangoMax = 999;
	int numero, contador = 0;
	printf("\n - Primer Matriz - \n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			contador++;
			printf("%d.- Introduzca un numero (Entre %d y %d) : ", contador,rangoMin, rangoMax); 
			scanf("%d", &numero);
			while (numero > rangoMax || numero < rangoMin) {
				printf("Error. El numero no esta entre %d y %d\n", rangoMin, rangoMax);
				printf("%d.- Introduzca un numero (Entre %d y %d) : ", contador,rangoMin, rangoMax); 
				scanf("%d", &numero);
			}
			matrizUno[i][j] = numero;
		}
	}
	contador = 0;
	printf("\n - Segunda Matriz - \n\n");
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
			matrizDos[i][j] = numero;
		}
	}
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			matrizTres[i][j] = (matrizUno[i][j]) + (matrizDos[i][j]);
		}
	}

	printf("\n              - Primer Matriz - \n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("       %d      ", matrizUno[i][j]);
		}
		printf("\n");
	}
	printf("\n              - Segunda Matriz - \n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("       %d      ", matrizDos[i][j]);
		}
		printf("\n");
	}
	printf("\n              - Suma Matrices - \n\n");
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("       %d      ", matrizTres[i][j]);
		}
		printf("\n");
	}
	
	_getche();
	return 0;
}
