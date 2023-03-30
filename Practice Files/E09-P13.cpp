/*
El número aproximado del número de Euler “e” se puede obtener con la siguiente fórmula:
e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + 1/5! +…..+1/n!
Utilizando esta fórmula elabore un algoritmo que solicite un valor entero “n” validando que esté entre 1 y 10.
Posteriormente calcule el valor aproximado de e mediante un ciclo que empiece en 1 y termine en “n”.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numero;
	double euler = 1;
	int limMin = 1;
	int limMax = 10;
	printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numero);
	while (numero >= limMax || numero <= limMin) {
		printf("\nError. El numero no esta dentro del rango indicado.");
		printf("\nIntroduzca un numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numero);
	}

	/*
	euler = 1 + (1/1!) + (1/2!) + ... + (1/n!)
	Obtenemos el numero (n).
	Creamos un ciclo que va de (contador = 1) a (numero) veces, es decir tantas veces como fracciones necesitemos sumar.
	En cada repeticion reiniciaremos el ciclo que obtendra el factorial del (contador) en el que vamos, necesario para la fraccion a sumar.
	Note que se inicializo "euler" con un 1 para no tener que sumarlo.
	*/

	int contador = 1;
	while (contador <= numero) {

		int contadorFactorial = 1;
		int factorial = 1;

		while (contadorFactorial <= contador) {
			factorial *= contadorFactorial;
			contadorFactorial++;
		}

		euler += (double(1)/double(factorial));
		
		contador++;
	}
	
	printf("\nEuler : %.3f", euler);


	_getche();
	return 0;
}
