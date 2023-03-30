/*
Elabore un programa que solicite dos valores enteros a y b, debe validar que los valores estén entre 1 y 100.
Posteriormente debe mostrar los múltiplos de 7 entre a y b (incluidos).
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	bool existenMultiplos = false;
	int a, b, numMenor, numMayor;
	int limMin = 1;
	int limMax = 100;
	int multiplo = 7;
	int pausa = 2500;
	printf("\nIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &a);
	while (a >= limMax || a <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el primer numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &a);
	}
	printf("\nIntroduzca el segundo numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &b);
	while (b >= limMax || b <= limMin) {
		printf("\nError. El numero no esta entre %d y %d", limMin, limMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el segundo numero entero (Entre %d y %d) : ", limMin, limMax); scanf("%d", &b);
	}
	if (a >= b) { numMayor = a; numMenor = b; } else { numMayor = b; numMenor = a; }
	printf("\nMultiplos de %d entre %d y %d (Incluidos) : ", multiplo, a, b);
	for (int i = 0; i <= numMayor; i += multiplo) {
		if (i >= numMenor || i == numMayor) {
			printf(" %d ,", i);
			existenMultiplos = true;
		}
	}
	if (existenMultiplos = false) { 
		printf(" No existen multiplos entre %d y %d ", a, b); 
	} else { 
		printf("\b  "); 
	}
	
	_getche();
	return 0;
}
