/*
Elabore un programa que solicite un valor “Entero Largo” “x” y valide que dicho valor esté entre 1 y 1000.  
Una vez que el valor es dado correctamente, solicite un nuevo valor “Entero Largo” “y” que esté entre 1 y 1000. 
Por último debe revisar que “x” sea menor que “y” por lo menos por 10 unidades.
De lo contrario deberá desplegar un mensaje de error y regresar a solicitar AMBOS valores (validación correlacionada). 
Cuando AMBOS valores han sido proporcionados correctamente su programa deberá mostrar 
la suma de los números primos entre “x” y “Y.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	unsigned long long int numUno;
	unsigned long long int numDos;
	unsigned long long int sumatoria = 0;
	int limMin = 1;
	int limMax = 1000;
	int pausa = 2500;
	int cantidadMayor = 10;
	bool pedirDeNuevo = true;
	bool esPrimo;
	
	while (pedirDeNuevo == true) {

		printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
		while (numUno >= limMax || numUno <= limMin) {
			printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
			this_thread::sleep_for(chrono::milliseconds(pausa));
			printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
		}
		printf("\nEl segundo numero debe ser %d unidades mayor que el primero.", cantidadMayor);
		printf("\nIntroduzca el segundo numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numDos);
		while (numDos >= limMax || numDos <= limMin) {
			printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
			this_thread::sleep_for(chrono::milliseconds(pausa));
			printf("\rIntroduzca el segundo numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numDos);
		}

		if ((numUno + cantidadMayor) > numDos) {
			printf("\nError. Entre el %llu y %llu hay menos de 10 unidades.", numUno, numDos);
			printf("\nEl segundo numero debe ser %d unidades mayor que el primero.\n", numUno, numDos);
			pedirDeNuevo = true;
		} else {
			pedirDeNuevo = false;
		}
	
	}

	for (int i = numUno; i <= numDos; i++) {
		esPrimo = true;
		if (i <= 1) {
			esPrimo = false;
		} else {
			for (int j = 2; (j*j) <= i; j++) {
				if (i % j == 0) esPrimo = false;
			}
		}
		if (esPrimo == true) {
			sumatoria += i;
		} 
	}

	printf("\nSumatoria de numeros primos entre %llu y %llu : %llu", numUno, numDos, sumatoria);

	_getche();
	return 0;
}
