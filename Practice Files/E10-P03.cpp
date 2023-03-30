/*
Elabore un programa que solicite un valor “Entero Largo” y valide que dicho valor esté entre 1 y 20. 
Una vez que el valor es dado correctamente calcule y despliegue el factorial de dicho valor.
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
	int limMin = 1;
	int limMax = 20;
	int pausa = 2500;
	printf("\nIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%llu", &numUno);
	}
	unsigned long long int factorial = 1;
	for (int i = 1; i <= numUno; i++) {
		factorial *= i;
	}
	printf("\nFactorial : %llu", factorial);
	
	_getche();
	return 0;
}
