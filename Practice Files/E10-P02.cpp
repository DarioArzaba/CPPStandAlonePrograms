/*
Elabore un programa que solicite un valor entero N, debe validar que el valor esté entre 1 y 100,
Posteriormente debe mostrar la sumatoria de dicho valor desde 1 hasta N (incluido). 
Suponga que N=5, entonces su programa deberá sumar 1+2+3+4+5, por lo tanto la salida es: 15
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	int numUno;
	int sumatoria = 0;
	int limMin = 1;
	int limMax = 100;
	int pausa = 2500;
	printf("\nIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	while (numUno >= limMax || numUno <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &numUno);
	}
	for (int i = 1; i <= numUno; i++) {
		sumatoria += i;
	}
	printf("\n\nSumatoria : %d", sumatoria);
	
	_getche();
	return 0;
}
