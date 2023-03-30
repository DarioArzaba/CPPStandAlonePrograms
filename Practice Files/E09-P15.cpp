/*
Elabore un programa que despliegue el siguiente menú:

	1)	Suma
	2)	Resta
	3)	Multiplicación
	4)	División (validar división entre cero)
	5)	Potencia
	6)	Factorial
	7)	Leer un valor e indicar si es primo
	8)	Terminar

Después de desplegar el menú su programa deberá solicitar la opción deseada VALIDAR QUE LA OPCION ESTE DENTRO DEL RANGO DE OPCIONES.
Y de acuerdo a la operación seleccionada deberá solicitar los datos necesarios y mostrar el resultado. 
Después de mostrar el resultado debe hacer una pausa y regresar nuevamente a desplegar el menú.
Las acciones de desplegar el menú, solicitar la opción, solicitar los datos necesarios, mostrar el resultado y hacer la pausa
Se deberán repetir hasta que el usuario seleccione la opción “8” que indica “terminar”, en este momento su programa deberá finalizar.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

int main() {

	bool terminar = false;
	int seleccion;

	printf("\nCalculadora General\n");

	while (terminar == false) {

		printf("\n--------------------------------------------------------\n");
		printf("\n1) Suma");
		printf("\n2) Resta");
		printf("\n3) Multiplicaci%cn", 162);
		printf("\n4) Divisi%cn", 162);
		printf("\n5) Potencia");
		printf("\n6) Factorial");
		printf("\n7) Leer un valor e indicar si es primo");
		printf("\n8) Terminar");

		printf("\n\nElije una opci%cn de la calculadora :  ", 162); scanf("%d", &seleccion);

		if (seleccion >= 1 && seleccion <= 8) {
			if (seleccion == 1) {
				
				double numUno, numDos, suma;
				printf("\nIntroduzca el Primer Numero de la Suma : "); scanf("%lf", &numUno);
				printf("Introduzca el Segundo Numero de la Suma : "); scanf("%lf", &numDos);
				suma = numUno + numDos;
				printf("\nEl resultado de sumar %.2f con %.2f es: %.2f\n", numUno, numDos, suma);

			} else if (seleccion == 2) {

				double numUno, numDos, resta;
				printf("\nIntroduzca el Primer Numero de la Resta (Minuendo) : "); scanf("%lf", &numUno);
				printf("Introduzca el Segundo Numero de la Resta (Sustraendo) : "); scanf("%lf", &numDos);
				resta = numUno - numDos;
				printf("\nEl resultado de restar %.2f de %.2f es: %.2f\n", numDos, numUno, resta);

			} else if (seleccion == 3) {

				double numUno, numDos, multiplicacion;
				printf("\nIntroduzca el Primer Numero de la Multiplicacion : "); scanf("%lf", &numUno);
				printf("Introduzca el Segundo Numero de la Multiplicacion : "); scanf("%lf", &numDos);
				multiplicacion = numUno * numDos;
				printf("\nEl resultado de multiplicar %.2f por %.2f es: %.2f\n", numUno, numDos, multiplicacion);

			} else if (seleccion == 4) {
				
				double numUno, numDos, division;
				printf("\nIntroduzca el Primer Numero (Dividendo) : "); scanf("%lf", &numUno);
				printf("Introduzca el Segundo Numero (Divisor) : "); scanf("%lf", &numDos);
				if (numDos != 0) {
					division = numUno / numDos;
					printf("\nEl resultado de dividir %.2f entre %.2f es: %.2f\n", numUno, numDos, division);
				} else {
					printf("\nError. No se puede realizar la division si el divisor es cero!\n");
				}

			} else if (seleccion == 5) {
				
				int numUno, numDos, resultado, numDosTexto;
				printf("\nIntroduzca el Primer Numero (Base) : "); scanf("%d", &numUno);
				printf("Introduzca el Segundo Numero (Exponente) : "); scanf("%d", &numDos);
				numDosTexto = numDos;
				resultado = numUno;
				while (numDos > 1) {
					resultado *= numUno;
					numDos -= 1;
				}
				printf("\nResultado de elevar %d a la %d  es : %d \n", numUno, numDosTexto, resultado);

			} else if (seleccion == 6) {

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
				printf("\nFactorial : %d\n", factorial);

			} else if (seleccion == 7) {

				int numero;
				printf("\nIntroduzca un numero entero : " ); scanf("%d", &numero);
				bool esPrimo = true;
				if (numero <= 1) {
					esPrimo = false;
				} else {
					int contador = 2;
					while ((contador*contador) <= numero) {
						if (numero%contador == 0) esPrimo = false;
						contador++;
					}
				}
				if (esPrimo == false) { printf("\nEl numero %d NO es un numero primo.\n", numero);
				} else { printf("\nEl numero %d SI es un numero primo.\n", numero); }

			} else if (seleccion == 8) {
				terminar = true;
				printf("\n\nPrograma Terminado. Hasta luego!\n\n");
			}
		} else {
			printf("\nError. Esa no es una opcion valida.");
		}

		this_thread::sleep_for(chrono::milliseconds(2500));
	}

	return 0;
}
