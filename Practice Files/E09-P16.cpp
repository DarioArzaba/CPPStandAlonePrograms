/*
Elabore un algoritmo que pida tres valores enteros y que valide que dichos valores estén entre 1 y 100 (incluidos). 
Si el valor es correcto deberá pedir el siguiente valor.
De lo contrario deberá mostrar un mensaje de error y regresar a pedir el mismo valor. 
Una vez leídos todos los valores deberá desplegar el siguiente menú:
	1)	Promedio
	2)	Número mayor
	3)	Número menor
	4)	Pares
	5)	Impares
	6)	Terminar
El menú deberá estar CICLADO y sólo podrá terminar cuando el usuario seleccione la opción “6) Terminar”.
Recuerde que debe validar el valor de la opción dentro del rango de opciones.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numUno, numDos, numTres;
	int limMin = 1;
	int limMax = 100;

	printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ",limMin, limMax); scanf("%d", &numUno);

	while (numUno > limMax || numUno < limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	}

	printf("\nIntroduzca el segundo numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numDos);

	while (numDos > limMax || numDos < limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numDos);
	}

	printf("\nIntroduzca el tercer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numTres);

	while (numTres > limMax || numTres < limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numTres);
	}

	bool terminar = false;
	int seleccion;

	while (terminar == false) {

		printf("\n\n--------------------------------------------------------\n");
		printf("\n1) Promedio");
		printf("\n2) N%cmero Mayor", 163);
		printf("\n3) N%cmero Menor", 163);
		printf("\n4) N%cmeros Pares", 163);
		printf("\n5) N%cmeros Impares", 163);
		printf("\n6) Terminar");

		printf("\n\nElije una opci%cn : ", 162); scanf("%d", &seleccion);

		if (seleccion >= 1 && seleccion <= 6) {
			if (seleccion == 1) {
			
				double promedio = (numUno + numDos + numTres) / double(3);
				printf("\nPromedio: %.2f", promedio);

			} else if (seleccion == 2) {

				int numMayor;
				if (numUno >= numDos && numUno >= numTres) {
					numMayor = numUno;
				} else if (numDos >= numUno && numDos >= numTres) {
					numMayor = numDos;
				} else {
					numMayor = numTres;
				}
				printf("\nN%cmero Mayor: %d", 163, numMayor);

			} else if (seleccion == 3) {

				int numMenor;
				if (numUno <= numDos && numUno <= numTres) {
					numMenor = numUno;
				} else if (numDos <= numUno && numDos <= numTres) {
					numMenor = numDos;
				} else {
					numMenor = numTres;
				}
				printf("\nN%cmero Menor: %d", 163, numMenor);

			} else if (seleccion == 4) {

				bool existenPares = false;
				printf("\nN%cmeros Pares: ", 163);
				if (numUno % 2 == 0) { printf(" %d ,", numUno);  existenPares = true; }
				if (numDos % 2 == 0) { printf(" %d ,", numDos);  existenPares = true; }
				if (numTres % 2 == 0) { printf(" %d ,", numTres);  existenPares = true; }
				if (existenPares == false) { printf("No hay numeros pares."); } else { printf("\b "); }

			} else if (seleccion == 5) {

				bool existenImpares = false;
				printf("\nN%cmeros Impares: ", 163);
				if (numUno % 2 != 0) { printf(" %d ,", numUno);  existenImpares = true; }
				if (numDos % 2 != 0) { printf(" %d ,", numDos); existenImpares = true; }
				if (numTres % 2 != 0) { printf(" %d ,", numTres);  existenImpares = true; }
				if (existenImpares == false) { printf("No hay numeros impares."); } else { printf("\b "); }

			} else if (seleccion == 6) {
				terminar = true;
			}
		} else {
			printf("\nError. Esa no es una opcion valida.");
		}

	}

	return 0;
}
