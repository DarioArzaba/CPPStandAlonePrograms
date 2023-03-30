/*
Lea dos valores enteros a y b y determine si son iguales o diferentes. Muestre un mensaje en pantalla que indique el resultado
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int a, b;
	printf("Introduzca el Primer Numero Entero : "); scanf("%d", &a);
	printf("Introduzca el Segundo Numero Entero : "); scanf("%d", &b);

	if (a == b) {
		printf("\nEl numero %d es igual a %d.", a, b);
	} else {
		printf("\nEl numero %d es distinto a %d.", a, b);
	}

	_getche();
	return 0;
}
