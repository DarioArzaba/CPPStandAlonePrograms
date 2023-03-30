/*
Escriba un programa que despliegue el siguiente menú:
  a.	Capital Inicial
  b.	Abonar a Capital
  c.	Retirar Capital
  d.	Invertir a un plazo
  e.	Terminar
El menú debe estar ciclado hasta que el usuario seleccione la opción de terminar.
Y debe estar en  una función que devuelve la opción elegida.
Para el funcionamiento de este programa sólo puede usar dos variable globales, las demás variable deben ser locales.
1)	La opción  capital Inicial debe solicitar al usuario un monto de dinero en pesos 
el cual servirá de base para todos los movimientos futuros.
2)	La opción de abonar a capital debe pedir al usuario una cantidad de dinero la cual deberá ser agregada al capital inicial,
cada que esta opción sea seleccionada, el monto en dinero que se solicite deberá sumarse al capital ya existente.
3)	La opción de retirar de capital debe pedir al usuario una cantidad de dinero la cual deberá ser restada al capital inicial, 
cada que esta opción sea seleccionada, el monto en dinero que se solicite deberá restarse al capital ya existente.
4)	Invertir implica pedir al usuario el número de meses a invertir, la tasa de interés anual y la cantidad de dinero que se invertirá.
El cálculo del nuevo capital se hará en una función. Dicho cálculo se hace con la siguiente fórmula:
Nuevo Capital=((Interés/12)*(monto a invertir))*número de meses
El resultado de esta fórmula debe acumularse al capital ya existente puesto que se trata de una ganancia.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

int menu() {
	int opcion = 0;
	printf("\nElige una de las siguientes opciones: ");
	printf("\n1) Capital Inicial ");
	printf("\n2) Abonar a Capital Inicial");
	printf("\n3) Retirar Capital");
	printf("\n4) Invertir a un Plazo");
	printf("\n5) Terminar");
	printf("\nOpcion: "); scanf("%d", &opcion);
	return opcion;
}
void capital(double *capitalI) {
	double capitalIntroducido;
	printf("\nIntroduce el Capital Inicial: "); scanf("%lf", &capitalIntroducido);
	*capitalI = capitalIntroducido;
	printf("\nCapital Inicial: $%.2f \n", *capitalI);
}
void abonar(double *capitalI) {
	double capitalIntroducido;
	printf("\nIntroduce el Capital a Abonar: "); scanf("%lf", &capitalIntroducido);
	printf("\nCapital Anterior: $%.2f", *capitalI);
	*capitalI += capitalIntroducido;
	printf("\nCapital Actual: $%.2f \n", *capitalI);
}
void retirar(double *capitalI) {
	double capitalIntroducido;
	printf("\nIntroduce el Capital a Retirar: "); scanf("%lf", &capitalIntroducido);
	printf("\nCapital Anterior: $%.2f", *capitalI);
	*capitalI -= capitalIntroducido;
	printf("\nCapital Actual: $%.2f \n", *capitalI);
}
void invertir(double *capitalI) {
	int meses;
	double tasa, capitalIntroducido, ganancia;
	printf("\nIntroduce los meses de inversion: "); scanf("%d", &meses);
	printf("Introduce la tasa de interes anual: "); scanf("%lf", &tasa);
	printf("Introduce el capital a invertir: "); scanf("%lf", &capitalIntroducido);
	ganancia = (((tasa/100)/12)*(capitalIntroducido))*meses;
	printf("\nGanancia por Inversion: $%.2f", ganancia);
	printf("\nCapital Anterior: $%.2f", *capitalI);
	*capitalI += ganancia;
	printf("\nCapital Actual: $%.2f \n", *capitalI);
}

int main() {
	bool capitalInicialCorrecto = false;
	double capitalTotal;
	int seleccion = 0;
	while (seleccion != 5) {
		seleccion = menu();
		if (seleccion == 1) {
			capital(&capitalTotal);
			capitalInicialCorrecto = true;
		} else if (seleccion == 2) {
			if (capitalInicialCorrecto == true) {
				abonar(&capitalTotal);
			} else {
				printf("\nError. Necesita introducir el Capital Inicial.\n");
			}
		} else if (seleccion == 3) {
			if (capitalInicialCorrecto == true) {
				retirar(&capitalTotal);
			} else {
				printf("\nError. Necesita introducir el Capital Inicial.\n");
			}
		} else if (seleccion == 4) {
			if (capitalInicialCorrecto == true) {
				invertir(&capitalTotal);
			} else {
				printf("\nError. Necesita introducir el Capital Inicial.\n");
			}
		} else if (seleccion > 5 || seleccion < 5) {
			printf("\nError. Opcion no valida.\n");
		}
	}
	return 0;
}
