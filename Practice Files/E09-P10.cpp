/*
Elabore un programa que lea un valor entero “X” el cual debe estar entre 1 y 10 VALIDE DICHA CONDICION.
Cuando el valor “X” es dado correctamente su programa deberá mostrar el factorial del valor dado.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {

	int numUno;
	int limMin = 1;
	int limMax = 10;
	printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	}

	int contador = 1;
	int factorial = 1;

	while (contador <= numUno) {
		
		factorial = factorial * contador;
		contador++;
	}

	printf("\nFactorial : %d", factorial);
	
	_getche();
	return 0;
}
