/*
Lea un valor entero y determine si dicho valor es mayor que 100 o menor que 100. 
Muestre un mensaje en pantalla que indique el resultado
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x; int y = 100;
	printf("Introduzca un Numero Entero : "); scanf("%d", &x);

	if (x > y) {
		printf("\nEl numero es mayor que %d.", y);
	} else if (x < 100) {
		printf("\nEl numero es menor que %d.", y);
	} else {
		printf("\nEl numero es %d.", y);
	}

	_getche();
	return 0;
}
