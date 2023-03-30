/*
Se pretende enseñar a unos niños de primaria los número pares y los números impares.
Para esto le han pedido que elabore un algoritmo que lea UN número y que le diga al niño si es par o impar.
Usted debe llevar un contador de número pares y uno de número impares.
El programa sólo deberá terminar cuando el niño haya introducido 5 números pares sin importar la cantidad de números impares. 
Al terminar debe indicar cuantos números pares y/o impares se introdujeron.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numero;
	int cantidadPares = 0;
	int cantidadImpares = 0;

	while (cantidadPares < 5) {

		printf("\nIntroduzca un numero entero: "); scanf("%d", &numero);
		
		if (numero % 2 == 0) {
			printf("El numero %d es Par.\n", numero);
			cantidadPares++;
		} else {
			printf("El numero %d es Impar.\n", numero);
			cantidadImpares++;
		}
		
	} 

	printf("\nSe introdujeron %d numeros Pares.", cantidadPares);
	printf("\nSe introdujeron %d numeros Impares.", cantidadImpares);

	_getche();
	return 0;
}
