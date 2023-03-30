/*
Leer y sumar dos valores. Elabore un programa que lea dos valores enteros proporcionados por el usuario.
Posteriormente sume dichos valores y despliegue el resultado de la suma MOSTRANDO los dos valores capturados y la suma de los mismos.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x, y, suma;
	printf("Introdusca Primer Valor Entero:  "); scanf("%d", &x);
	printf("Introdusca Segundo Valor Entero:  "); scanf("%d", &y);
	suma = x + y;
	printf("\nPrimer Valor: %d", x);
	printf("\nSegundo Valor: %d", y);
	printf("\nSuma Valores: %d", suma);
	
	_getche();
	return 0;
}
