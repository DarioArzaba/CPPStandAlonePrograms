/*
Usando C++ y empleando SOLO variables locales construya un programa que despliegue el siguiente menú:
  a.	Factorial
  b.	Elevar a una potencia
  c.	Terminar
Su programa debe cumplir con las siguientes condiciones:
  1)	SOLO puede usar variables locales
  2)	El menú debe ser desplegado por una función llamada “menu()” y debe regresar la opción seleccionada.
  3)	Debe existir la función “factorial()” la cual debe regresar el valor del factorial.
  4)	Debe existir la función “potencia()” la cual debe regresar el valor de la potencia
  5)	TODAS las funciones deben ser llamadas desde la función “main()”
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;


int menu() {
	int opcion = 0;
	printf("\nElige una de las siguientes opciones: ");
	printf("\n1) Calcular Factorial ");
	printf("\n2) Calcular Potencia");
	printf("\n3) Terminar el Programa");
	printf("\nOpcion: "); scanf("%d", &opcion);
	return opcion;
}
unsigned long long int factorial() {
	unsigned long long int numUno;
	int limMin = 1;
	int limMax = 20;
	int pausa = 2500;
	printf("\nIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("Error. El numero no esta entre %d y %d", limMin, limMax);
		Sleep(pausa);
		printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	}
	unsigned long long int factorial = 1;
	for (int i = 1; i <= numUno; i++) {
		factorial *= i;
	}
	return factorial;
}
unsigned long long int potencia() {
	unsigned long long int numUno;
	unsigned long long int numDos;
	int limMin = 1;
	int limMax = 10;
	int limMinDos = 1;
	int limMaxDos = 20;
	int pausa = 2500;

	printf("\nIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("Error. El numero no esta entre %d y %d", limMin, limMax);
		Sleep(pausa);
		printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	}
	printf("Introduzca el segundo entero (Entre %d y %d) : ", limMinDos, limMaxDos); scanf("%llu", &numDos);
	while (numDos >= limMaxDos || numDos <= limMinDos) {
		printf("Error. El numero no esta entre %d y %d", limMinDos, limMaxDos);
		Sleep(pausa);
		printf("\rIntroduzca el segundo entero (Entre %d y %d) : ", limMinDos, limMaxDos); scanf("%llu", &numDos);
	}

	unsigned long long int exponente = numUno;
	for (int i = numDos; i > 1; i--) {
		exponente *= numUno;
	}
	return exponente;
}

int main() {
	
	int seleccion = 0;
	while (seleccion != 3) {
		seleccion = menu();
		if (seleccion == 1) {
			unsigned long long int resultadoFactorial = factorial();
			printf("\nFactorial: %llu", resultadoFactorial); printf("\n");
		} else if (seleccion == 2) {
			unsigned long long int resultadoPotencia = potencia();
			printf("\nPotencia: %llu", resultadoPotencia); printf("\n");
		} else if (seleccion > 3 || seleccion < 1) {
			printf("\nError. Opcion no valida.\n");
		}
	}

	return 0;
}
