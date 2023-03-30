/*
Elabore un programa que lea 5 números enteros, cada número debe estar entre 1 y 1000 (incluyendo los límites). 
Sólo podrá solicitar el siguiente valor si el valor leído cumple con la condición solicitada, 
de lo contrario su programa deberá desplegar un mensaje de error y terminar. 
Una vez que se han leído correctamente los 5 valores su programa deberá desplegar el siguiente menú:
	1) Promedio
	2) Número Mayor
	3) Número Menor
	4) Números pares
	5) Números impares
Posteriormente debe solicitar la opción deseada y desplegar SOLO el valor o valores de acuerdo a la opción solicitada.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, numTres, numCuatro, numCinco, seleccion, numMenor, numMayor;
	double promedio;
	bool existenPares = false;
	bool existenImpares = false;
	int limMin = 1;
	int limMax = 1000;

	printf("\nIntroduce el primer numero entero entre %d y %d : ", limMin, limMax); scanf("%d", &numUno);
	if (numUno >= limMin && numUno <= limMax) {

		printf("Introduce el segundo numero entero entre %d y %d : ", limMin, limMax); scanf("%d", &numDos);
		if (numDos >= limMin && numDos <= limMax) {
		
			printf("Introduce el tercer numero entero entre %d y %d : ", limMin, limMax); scanf("%d", &numTres);
			if (numTres >= limMin && numTres <= limMax) {
			
				printf("Introduce el cuarto numero entero entre %d y %d : ", limMin, limMax); scanf("%d", &numCuatro);
				if (numCuatro >= limMin && numCuatro <= limMax) {
				
					printf("Introduce el quinto numero entero entre %d y %d : ", limMin, limMax); scanf("%d", &numCinco);
					if (numCinco >= limMin && numCinco <= limMax) {

						printf("\n\n1) Promedio");
						printf("\n2) N%cmero Mayor", 163 );
						printf("\n3) N%cmero Menor", 163);
						printf("\n4) N%cmeros Pares", 163);
						printf("\n5) N%cmeros Impares", 163);

						printf("\n\nOpcion Numero : "); scanf("%d", &seleccion);

						if (seleccion == 1) {
							
							promedio = (numUno + numDos + numTres + numCuatro + numCinco) / 5;
							printf("\n\nPromedio: %.2f", promedio);
						
						} else if (seleccion == 2) {
						
							if (numUno >= numDos && numUno >= numTres && numUno >= numCuatro && numUno >= numCinco) { numMayor = numUno; } 
							else if (numDos >= numUno && numDos >= numTres && numDos >= numCuatro && numDos >= numCinco) { numMayor = numDos; } 
							else if (numTres >= numUno && numTres >= numDos && numTres >= numCuatro && numTres >= numCinco) { numMayor = numTres; } 
							else if (numCuatro >= numUno && numCuatro >= numDos && numCuatro >= numTres && numCuatro >= numCinco) { numMayor = numCuatro; }
							else { numMayor = numCinco; }
							printf("\n\nN%cmero Mayor: %d", 163, numMayor);
						
						} else if (seleccion == 3) {
						
							if (numUno <= numDos && numUno <= numTres && numUno <= numCuatro && numUno <= numCinco) { numMenor = numUno; } 
							else if (numDos <= numUno && numDos <= numTres && numDos <= numCuatro && numDos <= numCinco) { numMenor = numDos; } 
							else if (numTres <= numUno && numTres <= numDos && numTres <= numCuatro && numTres <= numCinco) { numMenor = numTres; } 
							else if (numCuatro <= numUno && numCuatro <= numDos && numCuatro <= numTres && numCuatro <= numCinco) { numMenor = numCuatro; } 
							else { numMenor = numCinco; }
							printf("\n\nN%cmero Menor: %d", 163, numMenor);
						
						} else if (seleccion == 4) {
						
							printf("\n\nN%cmeros Pares: ", 163);
							if (numUno % 2 == 0) { printf(" %d ,", numUno);  existenPares = true; }
							if (numDos % 2 == 0) { printf(" %d ,", numDos);  existenPares = true; }
							if (numTres % 2 == 0) { printf(" %d ,", numTres);  existenPares = true; }
							if (numCuatro % 2 == 0) { printf(" %d ,", numCuatro);  existenPares = true; }
							if (numCinco % 2 == 0) { printf(" %d ,", numCinco);  existenPares = true; }
							if (existenPares == false) { printf("No hay numeros pares."); } else { printf("\b "); }

						} else if (seleccion == 5) {
						
							printf("\n\nN%cmeros Impares: ", 163);
							if (numUno % 2 != 0) { printf(" %d ,", numUno);  existenImpares = true; }
							if (numDos % 2 != 0) { printf(" %d ,", numDos); existenImpares = true; }
							if (numTres % 2 != 0) { printf(" %d ,", numTres);  existenImpares = true; }
							if (numCuatro % 2 != 0) { printf(" %d ,", numCuatro);  existenImpares = true; }
							if (numCinco % 2 != 0) { printf(" %d ,", numCinco); existenImpares = true; }
							if (existenImpares == false) { printf("No hay numeros impares."); } else { printf("\b "); }

						}

					} else {
						printf("\nError. El valor no esta dentro del rango indicado.");
					}
				} else {
					printf("\nError. El valor no esta dentro del rango indicado.");
				}
			} else {
				printf("\nError. El valor no esta dentro del rango indicado.");
			}
		} else {
			printf("\nError. El valor no esta dentro del rango indicado.");
		}
	} else {
		printf("\nError. El valor no esta dentro del rango indicado.");
	}

	_getche();
	return 0;
}

