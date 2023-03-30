/*
Lea dos valores flotantes a y b y si el valor b, es diferente de cero haga y muestre la división.
De lo contrario indique que no se puede hacer división entre cero.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double a, b, r;
	printf("Introduzca el Primer Numero Flotante : "); scanf("%lf", &a);
	printf("Introduzca el Segundo Numero Flotante : "); scanf("%lf", &b);

	if (b != 0) {
		r = a / b;
		printf("\nEl resultado de dividir %.2f entre %.2f es: %.2f", a, b, r);
	} else {
		printf("\nNo se puede realizar la division si el denominador es cero!");
	}

	_getche();
	return 0;
}
