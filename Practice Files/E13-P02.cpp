/*
Usando C++ elabore un programa que lea una lista de diez números enteros entre 1 y 1000 (valide) y los almacene 
en un arreglo de diez posiciones, posteriormente ,muestre el siguiente menú: 
  a.	Promedio
  b.	Número Mayor
  c.	Número Menor
  d.	Lista en secuencia de Captura
  e.	Lista Inversa a la Secuencia de Captura
  f.	Ver valor de una posición determinada
  g.	Terminar
La opción “a” Debe mostrar el promedio de los diez números capturados en el arreglo
La opción “b” Debe mostrar el número mayor de la lista
La opción “c” debe mostrar el número menor de la lista
La opción “d” debe mostrar el arreglo en el orden en que fue capturado
La opción “e” debe mostrar el arreglo en forma inversa al que fue capturado
La opción “f” debe pedir un número entre 0 y 9 (valide) y mostrar el valor almacenado en la posición del valor dado,
por ejemplo si el usuario indica un “5”, se debe mostrar el valor almacenado en la posición 5 del arreglo.
La opción “g” debe hacer que el programa termine
El menú debe ser mostrado desde una función que se llame menú() y cada opción debe ser ejecutada por una función diferente.
Puede usar variables globales y locales según lo requiera.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void captura(int arreglo[], int limMin, int limMax) {
	int num;
	for (int i = 0; i < 10; i++) {
		printf("Introduzca un numero entero (%d) (entre %d y %d): ", (i + 1), limMin, limMax); 
		scanf("%d", &num);
		while (num > limMax || num < limMin) {
			printf("Error. Numero fuera de rango.");
			Sleep(2000);
			printf("\rIntroduzca un numero entero (%d) (entre %d y %d): ", (i + 1), limMin, limMax); 
			scanf("%d", &num);
		}
		arreglo[i] = num;
	}
}
char menu() {
	char opcion = 'h';
	printf("\n\nElige una de las siguientes opciones: ");
	printf("\na) Promedio ");
	printf("\nb) N%cmero Mayor", 163);
	printf("\nc) N%cmero Menor", 163);
	printf("\nd) Lista en secuencia de Captura ");
	printf("\ne) Lista Inversa a la Secuencia de Captura");
	printf("\nf) Ver valor de una posici%cn determinada", 162);
	printf("\ng) Terminar ");
	printf("\nOpcion: "); getchar(); opcion = getchar();
	return opcion;
}
void promedio(int arreglo[]) {
	int resultado;
	int suma = 0;
	for (int i = 0; i < 10; i++) {
		suma += arreglo[i];
	}
	resultado = (suma / 10);
	printf("\nPromedio: %d", resultado);
}
void numMayor(int arreglo[]) {
	int mayor;
	int arregloMayor[10];
	for (int i = 1; i < 10; ++i) {
		arregloMayor[i] = arreglo[i];
	}
	for (int i = 1; i < 10; ++i) {
		if (arregloMayor[0] < arregloMayor[i]) {
			arregloMayor[0] = arregloMayor[i];
		}
	}
	mayor = arregloMayor[0];
	printf("\nNumero Mayor: %d", mayor);
}
void numMenor(int arreglo[]) {
	int menor;
	int arregloMenor[10];
	for (int i = 0; i < 10; ++i) {
		arregloMenor[i] = arreglo[i];
	}
	for (int i = 1; i < 10; ++i) {
		if (arregloMenor[0] > arregloMenor[i]) {
			arregloMenor[0] = arregloMenor[i];
		}
	}
	menor = arregloMenor[0];
	printf("\nMenor Numero: %d", menor);
}
void lista(int arreglo[]) {
	printf("\nArreglo: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arreglo[i]);
	}
}
void inversa(int arreglo[]) {
	printf("\nInverso: ");
	for (int i = 9; i >= 0; i--) {
		printf("%d ", arreglo[i]);
	}
}
void posicion(int arreglo[]) {
	int posicion;
	printf("\nIntroduzca una posicion del array (0-9): "); scanf("%d", &posicion);
	while (posicion > 9 || posicion < 0) {
		printf("\nError. Numero indice fuera del array.");
		Sleep(2000);
		printf("\rIntroduzca una posicion del array (0-9): "); scanf("%d", &posicion);
	}
	printf("\nValor en posicion (%d): %d", posicion, arreglo[posicion]);
}

int main() {
	int arreglo[10];
	printf("\n");
	captura(arreglo, 1, 1000);
	char seleccion = 'h';
	while (seleccion != 'g') {
		seleccion = menu();
		if (seleccion == 'a') {
			promedio(arreglo);
		} else if (seleccion == 'b') {
			numMayor(arreglo);
		} else if (seleccion == 'c') {
			numMenor(arreglo);
		} else if (seleccion == 'd') {
			lista(arreglo);
		} else if (seleccion == 'e') {
			inversa(arreglo);
		} else if (seleccion == 'f') {
			posicion(arreglo);
		} else if (seleccion != 'g') {
			printf("\nError. Opcion no valida, debe estar entre (a) y (g).");
		}
	}
	return 0;
}
