/*
Usando C++ elabore un programa que lea una lista de cinco números enteros y los almacene en un arreglo de cinco posiciones, 
esta acción debe estar en un función que se llame captura(). Posteriormente 
a.	Muestre el arreglo en forma de lista en el mismo orden en que los números fueron capturados y haga una pausa (getche()). 
Esta acción debe estar en un función que se llame lista().
b.	Repita el paso “a” pero ahora muestre los números empezando por el último número capturado y terminando por el primero, 
es decir en el orden inverso, esta acción deberá estar en un a función que se llame inverso().
Todas las funciones deben trabajar con variables locales, la única variable global será el propio arreglo.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void captura(int arreglo[]) {
	int num;
	for (int i = 0; i < 5; i++) {
		printf("Introduzca un numero entero (%d): ", (i+1)); scanf("%d", &num);
		arreglo[i] = num;
	}
}
void lista(int arreglo[]) {
	printf("\nArreglo: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arreglo[i]);
	}
}
void inverso(int arreglo[]) {
	printf("\nInverso: ");
	for (int i = 4; i >= 0; i--) {
		printf("%d ", arreglo[i]);
	}
}

int main() {
	int arreglo[5];
	printf("\n");
	captura(arreglo);
	lista(arreglo);
	inverso(arreglo);
	_getche();
	return 0;
}
