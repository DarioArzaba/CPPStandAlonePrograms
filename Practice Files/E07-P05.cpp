/*
Elabore un programa que solicite dos valores flotantes, valide que dichos valores estén entre 1 y 1000.
Una vez solicitados dichos valores su programa debe mostrar el siguiente menú de opciones.
	Suma
	Resta
	Multiplicación
	División (valide división entre cero)
Mediante una variable de tipo entero lea la opción seleccionada por el usuario y valide que dicha opción esté entre 1 y 4.
Una vez que sepa cual fue la opción seleccionada muestre el resultado de la operación correspondiente.
Use los valores que se leyeron al inicio o bien despliegue los mensajes de error correspondientes.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {


	double primerNumero, segundoNumero, resultado;
	int limMin = 1;
	int limMax = 1000;
	int seleccion;

	printf("Introduzca un numero que este entre %d y %d : ", limMin, limMax); scanf("%lf", &primerNumero);

	if (primerNumero >= limMin && primerNumero <= limMax) {
	
		printf("Introduzca un numero que este entre %d y %d : ", limMin, limMax); scanf("%lf", &segundoNumero);
		
		if (segundoNumero >= limMin && segundoNumero <= limMax) {

			printf("\n1) Suma");
			printf("\n2) Resta");
			printf("\n3) Multiplicaci%cn", 162);
			printf("\n4) Divisi%cn", 162);

			printf("\n\nOperacion a realizar (1 a 4) : "); scanf("%d", &seleccion);

			if (seleccion >= 1 && seleccion <= 4) {

				if (seleccion == 1) {
					resultado = primerNumero + segundoNumero;
					printf("\nSuma de %.1f mas %.1f es : %.1f", primerNumero, segundoNumero, resultado);
				} else if (seleccion == 2) {
					resultado = primerNumero - segundoNumero;
					printf("\nResta de %.1f menos %.1f es : %.1f", primerNumero, segundoNumero, resultado);
				} else if (seleccion == 3) {
					resultado = primerNumero * segundoNumero;
					printf("\nMultiplicaci%cn de %.1f por %.1f es : %.1f", 162, primerNumero, segundoNumero, resultado);
				} else if (seleccion == 4) {
					//Esta validacion es inecesaria porque el segundo numero ya se valido entre 1 y 1000
					if (segundoNumero != 0) {
						resultado = (primerNumero / segundoNumero);
						printf("\nDivisi%cn de %.1f entre %.1f es : %.1f", 162, primerNumero, segundoNumero, resultado);
					} else {
						printf("\nError. El denominador de una divisi%cn no puede ser cero.", 162);
					}
				}

			} else {

				printf("\nError. Ninguna operacion esta relacionada con ese numero.");
			
			}

		} else {
			
			printf("\nError. El numero no esta dentro del rango indicado.");
		
		}
	} else {
		
		printf("\nError. El numero no esta dentro del rango indicado.");
	
	}

	_getche();
	return 0;
}
