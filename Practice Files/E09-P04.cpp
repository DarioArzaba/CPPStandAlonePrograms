/*
Elabore un programa en “C” que solicite un número entero “X” y un número entero “Y”.
Posteriormente muestre los valores enteros que estén entre X y Y.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int primerNumero, segundoNumero, numMayor, numMenor;
	printf("\nIntroduzca el primer numero entero : "); scanf("%d", &primerNumero);
	printf("\nIntroduzca el segundo numero entero : "); scanf("%d", &segundoNumero);
	if (primerNumero == segundoNumero) {
		printf("\nError. No existen numeros entre un mismo numero.");
	} else if (primerNumero < segundoNumero)  {
		numMayor = segundoNumero;
		numMenor = primerNumero + 1;
	} else {
		numMayor = primerNumero;
		numMenor = segundoNumero + 1;
	}
	while (numMenor < numMayor) {
		printf("\n %d", numMenor);
		numMenor += 1;
	}

	_getche();
	return 0;
}
