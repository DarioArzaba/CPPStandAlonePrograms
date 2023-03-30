/*
X= sumatoria(n=1 hasta que n=límite uno) + sumatoria(n=1 hasta que n=límite dos) + factorial de límite uno + factorial de límite dos.
Su programa debe solicitar el valor del “límite uno” y el valor del “límite dos” validando que estén entre 1 y 10.
Se lo contrario deberá marcar un mensaje de error y regresar a solicitar el valor correspondiente. 
Una vez que los valores han sido proporcionados correctamente su programa deberá calcular y desplegar el valor de X.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {

	unsigned long long int X;
	unsigned long long int sumatoriaUno = 0;
	unsigned long long int sumatoriaDos = 0;
	unsigned long long int factorialUno = 1;
	unsigned long long int factorialDos = 1;
	int limUno, limDos;
	int rangoMin = 1;
	int rangoMax = 10;
	int pausa = 2500;

	printf("\nIntroduzca el primer limite (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &limUno);
	while (limUno >= rangoMax || limUno <= rangoMin) {
		printf("\nError. El limite no esta entre %d y %d", rangoMin, rangoMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el primer limite (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &limUno);
	}
	printf("\nIntroduzca el segundo limite (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &limDos);
	while (limDos >= rangoMax || limDos <= rangoMin) {
		printf("\nError. El limite no esta entre %d y %d", rangoMin, rangoMax);
		this_thread::sleep_for(chrono::milliseconds(pausa));
		printf("\rIntroduzca el segundo limite(Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &limDos);
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			for (int i = 1; i <= limUno; i++) {
				sumatoriaUno += i;
			}
		} else if (i == 2) {
			for (int i = 1; i <= limDos; i++) {
				sumatoriaDos += i;
			}
		} else if (i == 3) {
			for (int i = 1; i <= limUno; i++) {
				factorialUno *= i;
			}
		} else {
			for (int i = 1; i <= limDos; i++) {
				factorialDos *= i;
			}
		}
	}
	
	X = sumatoriaUno + sumatoriaDos + factorialUno + factorialDos;

	printf("\nX = %llu", X);

	_getche();
	return 0;
}
