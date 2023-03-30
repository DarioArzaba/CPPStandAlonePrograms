/*
Usando “C” elabore un programa que lea dos números enteros; el primer número debe estar entre 1 y 10.
De lo contrario se debe mostrar un mensaje de error y regresar a solicitar dicho número. 
El segundo número debe estar entre 40 y 50 de lo contrario se debe mostrar un mensaje de error y regresar a solicitar el mismo número. 
Una vez que ambos valores fueron leídos su algoritmo debe mostrar los números pares que estén entre el primer y segundo valores.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, numMayor, numMenor;
	int primerMin = 1;
	int primerMax = 10;
	int segundoMin = 40;
	int segundoMax = 50;
	
	printf("\nIntroduzca el primer numero entero : "); scanf("%d", &numUno);
	while (numUno >= primerMax || numUno <= primerMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el primer numero entero : "); scanf("%d", &numUno);
	}
	
	printf("\nIntroduzca el segundo numero entero : "); scanf("%d", &numDos);
	while (numDos >= segundoMax || numDos <= segundoMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el segundo numero entero : "); scanf("%d", &numDos);
	}
	
	if (numUno == numDos) {
		printf("\nNo existen numeros entre un mismo numero.");
	} else if (numUno < numDos) {
		numMayor = numDos;
		numMenor = numUno + 1;
	} else {
		numMayor = numUno;
		numMenor = numDos + 1;
	}
	printf("\nPares :  ");
	while (numMenor < numMayor) {
		if (numMenor % 2 == 0) {
			printf("%d, ", numMenor);
		}
		numMenor += 1;
	}
	printf("\b\b  ");

	_getche();
	return 0;
}
