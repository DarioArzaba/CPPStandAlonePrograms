/*
En una matriz de 3X3 coloque de forma desordenada los números del 1 al 9, su matriz debe quedar de la siguiente forma:
3	7	1
5	9	8
2	4	6
Una vez que los valores han sido capturados su programa debe pedir un par de números, ambos valores deben estar entre 1 y 9 
y ser diferentes entre si, por ejemplo suponga que los valores dados son: 3 y 6, 
con esta acción su programa debe intercambiar los valores en la matriz, quedando ahora de la siguiente forma:
6       7	   1
5	9	   8
2       4	   3
Observe como el 3 y el 6 han sido intercambiados, esta acción debe repetirse hasta que TODAS las columnas, 
TODOS los renglones y AMBAS diagonales sumen 15, este es un ejemplo:
	      		15
    4  	3	8	15
    9  	5	1	15
    2  	7	6	15
15	15	15	15
*/

#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

const int filas = 3, columnas = 3;
int maxFilas = filas, maxColumnas = columnas;
int matriz[filas][columnas];
int contador = 0;
bool salir = false;

void crearMatriz() {
	
	srand(unsigned(time(0)));
	vector<int> myvector;
	for (int i = 1; i < 10; ++i) { myvector.push_back(i); }
	random_shuffle(myvector.begin(), myvector.end());

	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			matriz[i][j] = myvector[contador];
			contador++;
		}
	}
}

void mostrarMatriz() {
	printf("\n");
	int suma;
	for (int i = 0; i < maxFilas; i++) {
		for (int j = 0; j < maxColumnas; j++) {
			printf("     %d    ", matriz[i][j]);
		}
		suma = (matriz[i][0]) + (matriz[i][1]) + (matriz[i][2]);
		printf("     %d    ", suma);
		printf("\n");
	}
	for (int i = 0; i < maxColumnas; i++) {
		suma = (matriz[0][i]) + (matriz[1][i]) + (matriz[2][i]);
		printf("    %d    ", suma);

	}
	suma = (matriz[0][0]) + (matriz[1][1]) + (matriz[2][2]);
	printf("     %d    ", suma);
	printf("\n");
}

int sumaDiagonal, colUno, colDos, colTres, renUno, renDos, renTres;
int numeroUno, numeroDos, tempUno, tempDos, coordXUno, coordYUno, coordXDos, coordYDos;

void tomarValores() {

	int rangoMin = 1, rangoMax = 9;
	mostrarMatriz();
	sumaDiagonal = (matriz[0][0]) + (matriz[1][1]) + (matriz[2][2]);
	colUno = (matriz[0][0]) + (matriz[1][0]) + (matriz[2][0]);
	colDos = (matriz[0][1]) + (matriz[1][1]) + (matriz[2][1]);
	colTres = (matriz[0][2]) + (matriz[1][2]) + (matriz[2][2]);
	renUno = (matriz[0][0]) + (matriz[0][1]) + (matriz[0][2]);
	renDos = (matriz[1][0]) + (matriz[1][1]) + (matriz[1][2]);
	renTres = (matriz[2][0]) + (matriz[2][1]) + (matriz[2][2]);

	if (sumaDiagonal == 15 && colUno == 15 && colDos == 15 && colTres == 15 && renUno == 15 && renDos == 15 && renTres == 15) {
		salir = true;
	} else {

		printf("\nIntroduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax);
		scanf("%d", &numeroUno);
		while (numeroUno > rangoMax || numeroUno < rangoMin) {
			printf("Error. El numero no esta entre %d y %d\n", rangoMin, rangoMax);
			printf("\nIntroduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax);
			scanf("%d", &numeroUno);
		}

		printf("\nIntroduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax);
		scanf("%d", &numeroDos);
		while (numeroDos > rangoMax || numeroDos < rangoMin) {
			printf("Error. El numero no esta entre %d y %d\n", rangoMin, rangoMax);
			printf("\nIntroduzca un numero (Entre %d y %d) : ", rangoMin, rangoMax);
			scanf("%d", &numeroDos);
		}

		for (int i = 0; i < maxFilas; i++) {
			for (int j = 0; j < maxColumnas; j++) {
				if (numeroUno == matriz[i][j]) {
					tempUno = matriz[i][j];
					coordXUno = i;
					coordYUno = j;
				}
				if (numeroDos == matriz[i][j]) {
					tempDos = matriz[i][j];
					coordXDos = i;
					coordYDos = j;
				}
			}
		}

		matriz[coordXUno][coordYUno] = tempDos;
		matriz[coordXDos][coordYDos] = tempUno;

	}

}

int main() {
	printf("\n Todas las sumas deben dar 15 \n\n");
	printf("\n");
	crearMatriz();
	while (salir == false) {
		tomarValores();
	}
	printf("\n Ganaste! \n");
	_getche();
	return 0;
} 
