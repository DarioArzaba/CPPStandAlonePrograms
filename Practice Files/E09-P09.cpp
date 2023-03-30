/*
Elabore un programa que lea un valor entero “X” el cual debe estar entre 1 y 10 VALIDE DICHA CONDICION.
Cuando el valor “X” es dado correctamente su programa deberá solicitar un segundo valor entero “Y” que esté entre 1 y 5 
Cuando ambos valores sean proporcionados correctamente su programa deberá mostrar el resultado de elevar el valor X a la potencia Y.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, resultado, numDosTexto;
	int primerMin = 1;
	int primerMax = 10;
	int segundoMin = 1;
	int segundoMax = 5;

	printf("\nIntroduzca el primer numero entero  (Entre %d y %d) : ", primerMin, primerMax); scanf("%d", &numUno);
	while (numUno >= primerMax || numUno <= primerMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el primer numero entero : "); scanf("%d", &numUno);
	}

	printf("\nIntroduzca el segundo numero entero (Entre %d y %d) : ", segundoMin, segundoMax); scanf("%d", &numDos);
	while (numDos >= segundoMax || numDos <= segundoMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el segundo numero entero : "); scanf("%d", &numDos);
	}

	numDosTexto = numDos;
	resultado = numUno;

	while (numDos > 1) {
		resultado *= numUno;
		numDos -= 1;
	}

	printf("\nResultado de elevar %d a la %d : %d ",numUno, numDosTexto, resultado);

	_getche();
	return 0;
}
