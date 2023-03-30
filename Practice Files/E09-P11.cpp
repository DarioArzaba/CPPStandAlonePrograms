/*
Elabore un programa que lea un valor entero “X” el cual debe estar entre 1 y 1000 VALIDE DICHA CONDICION.
Cuando el valor “X” es dado correctamente su programa deberá indicar si valor dado es primo o no.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {

	int numUno;
	int limMin = 1;
	int limMax = 1000;

	printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	}

	//Un numero primo solo es divisible entre 1 y si mismo.

	bool esPrimo = true;

	/*Si el numero es menor o igual a 1 entonces NO es primo
	Si encontramos un divisor que no sea 1 o el mismo numero entonces NO es primo
	Solo necesitamos checar la condicion anterior para divisores menores a la raiz del numero
	(o divisores al cuadrado menores al numero.)*/

	if (numUno <= 1) {
		esPrimo = false;
	} else {
		int contador = 2;
		while ((contador*contador) <= numUno) {
			if (numUno%contador == 0) esPrimo = false;
			contador++;
		}
	}

	if (esPrimo == false) {
		printf("\n %d NO es un numero primo.", numUno);
	} else {
		printf("\n %d SI es un numero primo.", numUno);
	}

	_getche();
	return 0;
}
