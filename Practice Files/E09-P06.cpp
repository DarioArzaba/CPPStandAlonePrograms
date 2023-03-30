/*
Elabore un programa que lea un valor entero X y que verifique si dicho valor está entre 1 y 100.
Si dicho valor NO cumple la condición, su programa deberá mostrar un mensaje de error, hacer una pausa y regresar a solicitar dicho valor.
Cuando el valor cumpla con la condición solicitada deberá mostrar un letrero que diga “VALOR CORRECTO”.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int primerNumero;
	int limMin = 1;
	int limMax = 100;
	bool valorCorrecto = false;
	printf("\nIntroduzca el numero entero : "); scanf("%d", &primerNumero);
	while (valorCorrecto == false) {
		if (primerNumero > limMin && primerNumero < limMax) {
			valorCorrecto = true;
			printf("\nVALOR CORRECTO");
		} else {
			printf("\nIntroduzca el numero entero : "); scanf("%d", &primerNumero);
		}
	}
	
	_getche();
	return 0;
}
