/*
Solicite un valor que esté entre 1 y 100, si el valor NO cumple con esta condición muestre un mensaje de error y termine el programa. 
Si el valor CUMPLE la condición, solicite un segundo valor que esté entre 1 y 100.
De igual forma si el segundo valor NO cumple con esta condición muestre un mensaje de error y termine el programa. 
En caso de que ambos valores cumplan las condiciones especificadas, muestre un letrero que diga VALORES CORRECTOS.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double primerNumero, segundoNumero;
	int limMin = 1;
	int limMax = 100;

	printf("Introduzca un numero que este entre %d y %d : ", limMin, limMax); scanf("%lf", &primerNumero);
	
	if (primerNumero >= limMin && primerNumero <= limMax) {
	
		printf("Introduzca un numero que este entre %d y %d : ", limMin, limMax); scanf("%lf", &segundoNumero);
		
		if (segundoNumero >= limMin && segundoNumero <= limMax) {
			printf("\nVALORES CORRECTOS");
		} else { 
			printf("\n Error. El valor no esta dentro del rango indicado."); 
		}

	} else { 
		printf("\n Error. El valor no esta dentro del rango indicado."); 
	}

	_getche();
	return 0;
}
