/*
Elabore un programa que lea un valor entero que sea par y que esté entre 1 y 1000.
Si dicho valor NO cumple con las condiciones solicitadas, deberá mostrar un mensaje de error y detener el programa. 
En caso de que dicho valor SI cumpla con las condiciones deseadas, deberá solicitar un segundo valor que sea impar.
Que esté entre 1 y 1000 y deberá ser mayor que el numero anterior. 
En caso de que el segundo valor NO cumpla las condiciones indicadas su programa deberá mostrar un mensaje de error y detenerse. 
En caso de que ambos números cumplan todas las condiciones indicadas su programa deberá mostrar el mensaje VALOR CORRECTOS. 
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double primerNumero, segundoNumero;
	int limMin = 1;
	int limMax = 1000;

	printf("Introduzca un numero par que este entre %d y %d : ", limMin, limMax);
	scanf("%lf", &primerNumero);

	if ((primerNumero >= limMin && primerNumero <= limMax) && (int(primerNumero) % 2 == 0)) {

		printf("Introduzca un numero impar que este entre %d y %d : ", limMin, limMax); scanf("%lf", &segundoNumero);

		if ((segundoNumero >= limMin && segundoNumero <= limMax) && (int(segundoNumero) % 2 != 0)) {
			printf("\nVALORES CORRECTOS");
		} else {
			printf("\n Error. El valor no esta dentro del rango indicado o no es impar.");
		}

	} else {
		printf("\n Error. El valor no esta dentro del rango indicado o no es par.");
	}

	_getche();
	return 0;
}
