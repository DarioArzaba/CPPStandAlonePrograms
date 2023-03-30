/*
Elabore un programa que solicite un valor “Entero Largo” “x” y valide que dicho valor esté entre 1 y 20.  
Una vez que el valor es dado correctamente, solicite un nuevo valor “Entero Largo” “y” que esté entre 1 y 20. 
Cuando Ambos valores han sido proporcionados correctamente su programa deberá tomar el primer valor
Y elevarlo a la potencia del segundo valor, es decir “x” elevado a la “y”.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	//Incluso el Entero Largo no puede calcular mas alla de 19^15 o 10^19. Es decir alrededor de 19 digitos.

	unsigned long long int numUno;
	unsigned long long int numDos;
	int limMin = 1;
	int limMax = 20;
	int pausa = 2500;

	printf("\nIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	}
	printf("\nIntroduzca el segundo entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numDos);
	while (numDos >= limMax || numDos <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el segundo entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numDos);
	}

	unsigned long long int exponente = numUno;

	for (int i = numDos; i > 1; i--) {
		exponente *= numUno;
	}

	printf("\nResultado de elevar %llu a la %llu : %llu", numUno, numDos, exponente);

	_getche();
	return 0;
}
