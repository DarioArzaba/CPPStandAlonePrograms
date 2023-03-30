/*
Elabore un algoritmo que lea una lista de cinco números enteros, posteriormente, muestre la siguiente información: 
	Promedio de los cinco números
	El número mayor
	El número menor
	Los números pares
	Los números impares
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, numTres, numCuatro, numCinco;
	printf("Introduce el primer numero entero: "); scanf("%d", &numUno);
	printf("Introduce el segundo numero entero: "); scanf("%d", &numDos);
	printf("Introduce el tercer numero entero: "); scanf("%d", &numTres);
	printf("Introduce el cuarto numero entero: "); scanf("%d", &numCuatro);
	printf("Introduce el quinto numero entero: "); scanf("%d", &numCinco);

	double promedio = (numUno + numDos + numTres + numCuatro + numCinco) / 5;
	int numMayor, numMenor;

	if (numUno >= numDos && numUno >= numTres && numUno >= numCuatro && numUno >= numCinco) { numMayor = numUno; } 
	else if (numDos >= numUno && numDos >= numTres && numDos >= numCuatro && numDos >= numCinco) { numMayor = numDos; } 
	else if (numTres >= numUno && numTres >= numDos && numTres >= numCuatro && numTres >= numCinco) { numMayor = numTres; } 
	else if (numCuatro >= numUno && numCuatro >= numDos && numCuatro >= numTres && numCuatro >= numCinco) { numMayor = numCuatro; }
	else { numMayor = numCinco; }

	if (numUno <= numDos && numUno <= numTres && numUno <= numCuatro && numUno <= numCinco) { numMenor = numUno; } 
	else if (numDos <= numUno && numDos <= numTres && numDos <= numCuatro && numDos <= numCinco) { numMenor = numDos; } 
	else if (numTres <= numUno && numTres <= numDos && numTres <= numCuatro && numTres <= numCinco) { numMenor = numTres; } 
	else if (numCuatro <= numUno && numCuatro <= numDos && numCuatro <= numTres && numCuatro <= numCinco) { numMenor = numCuatro; } 
	else { numMenor = numCinco; }

	printf("\nPromedio: %.2f", promedio);
	printf("\nNumero Mayor: %d", numMayor);
	printf("\nNumero Menor: %d", numMenor);

	printf("\nPares: ");

	bool existenPares = false;
	bool existenImpares = false;

	if (numUno % 2 == 0) { printf(" %d ,", numUno);  existenPares = true; }
	if (numDos % 2 == 0) { printf(" %d ,", numDos);  existenPares = true; }
	if (numTres % 2 == 0) { printf(" %d ,", numTres);  existenPares = true; }
	if (numCuatro % 2 == 0) { printf(" %d ,", numCuatro);  existenPares = true; }
	if (numCinco % 2 == 0) { printf(" %d ,", numCinco);  existenPares = true; }

	if (existenPares == false) { printf("No hay numeros pares."); printf(" \nImpares: ");}
	else { printf("\b \nImpares: "); }

	if (numUno % 2 != 0) { printf(" %d ,", numUno);  existenImpares = true;}
	if (numDos % 2 != 0) { printf(" %d ,", numDos); existenImpares = true;}
	if (numTres % 2 != 0) { printf(" %d ,", numTres);  existenImpares = true;}
	if (numCuatro % 2 != 0) { printf(" %d ,", numCuatro);  existenImpares = true;}
	if (numCinco % 2 != 0) { printf(" %d ,", numCinco); existenImpares = true;}

	if (existenImpares == false) { printf("No hay numeros impares.");}
	else { printf("\b "); }
	
	_getche();
	return 0;
}
