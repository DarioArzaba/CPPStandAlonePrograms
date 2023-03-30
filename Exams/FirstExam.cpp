
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, a, b, serie;
	int limMin = 3;
	int limMax = 100;

	printf("Programa Serie Numerica\n");

	//Validacion

	printf("\nIntroduzca el primer numero entero: "); scanf("%d", &numUno);
	while (numUno > limMax || numUno < limMin) {
		printf("\nError. El numero se debe encontrar entre %d y %d", limMin, limMax);
		_getche();
		printf("\nIntroduzca el primer numero entero: "); scanf("%d", &numUno);
	}

	printf("\nIntroduzca el segundo numero entero: "); scanf("%d", &numDos);
	while (numDos > limMax || numDos < limMin) {
		printf("\nError. El numero se debe encontrar entre %d y %d", limMin, limMax);
		_getche();
		printf("\nIntroduzca el segundo numero entero: "); scanf("%d", &numDos);
	}

	//Arreglar numeros si introdujeron primero un numero mas grande

	if (numUno >= numDos) {
		a = numDos;
		b = numUno;
	} else {
		a = numUno;
		b = numDos;
	}
	
	//Imprimir Serie

	int contador = 1;
	printf("\nSerie: ");

	while (a < b) {
		printf("%d, ", a);
		a += contador;
		contador++;
	}

	//Eliminar la ultima coma
	printf("\b\b ");


	_getche();
	return 0;

}