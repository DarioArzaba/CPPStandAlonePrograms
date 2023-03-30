/*
Repita el ejercicio “1” pero ahora después de desplegar la matriz solicite un par de coordenadas (x,y) 
y despliegue el valor de las coordenadas indicadas, por ejemplo si las coordenadas son (0,1) el valor a desplegar es: 18.
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
	int coordX, coordY;
	printf("\n\nIntroduzca una coordenada X (Entre %d y %d) : ", 0, (maxFilas - 1));
	scanf("%d", &coordX);
	while (coordX > (maxFilas - 1) || coordX < 0) {
		printf("Error. La coordenada no esta entre %d y %d\n", 0, (maxFilas - 1));
		printf("Introduzca una coordenada X (Entre %d y %d) : ", 0, (maxFilas - 1));
		scanf("%d", &coordX);
	}
	printf("Introduzca una coordenada Y (Entre %d y %d) : ", 0, (maxColumnas - 1));
	scanf("%d", &coordY);
	while (coordY > (maxColumnas - 1) || coordY < 0) {
		printf("Error. La coordenada no esta entre %d y %d\n", 0, (maxColumnas - 1));
		printf("Introduzca una coordenada Y (Entre %d y %d) : ", 0, (maxColumnas - 1));
		scanf("%d", &coordY);
	}
	printf("\nValor en coordenadas (%d, %d):  %d", coordX, coordY, matriz[coordY][coordX]);
	_getche();
	return 0;
}
