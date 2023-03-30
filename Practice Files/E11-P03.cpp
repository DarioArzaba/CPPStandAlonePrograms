/*
Usando C++ elabore un programa que lea dos valores enteros entre 1 y 10 (valide estos valores).
En caso de que los valores NO cumplan con el rango establecido su programa deberá mostrar un mensaje de error.
Dicho mensaje de error deberá ser llamado mediante una función llamada ERROR.
Los valores deben ser pedidos a través de una función que se llame “pide_datos”. 
Una vez que ambos valores han cumplido con el rango establecido pinte nuevamente la carita del ejercicio “2” 
Pero esta vez el asterisco de la esquina superior izquierda deberá estar en la posición (X,Y). 
La carita deberá ser pintada mediante la función “cara”.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void error(int error) {
	if (error == 1) {
		printf("\nError. El numero esta fuera del rango. ");
	}
}
int pide_datos(int min, int max) {
	int enteroCorrecto;
	printf("\nIntroduzca un numero entero (entre %d y %d) : ", min, max); scanf("%d", &enteroCorrecto);
	while (enteroCorrecto >= max || enteroCorrecto <= min) {
		error(1);
		Sleep(2000);
		printf("\rIntroduzca un numero entero (entre %d y %d) : ", min, max); scanf("%d", &enteroCorrecto);
	}
	return enteroCorrecto;
}
void moverCursor(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cara(int x, int y) {
	int contador = 0;
	moverCursor(x, (y+contador)); contador++;
	printf("**************\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*            *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*   *    *   *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*            *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*      *     *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*  *       * *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*   *******  *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("*            *\n");
	moverCursor(x, (y + contador)); contador++;
	printf("**************\n");
}

int limMin = 1;
int limMax = 10;

int main() {
	int numUno = pide_datos(limMin, limMax);
	int numDos = pide_datos(limMin, limMax);
	system("cls");
	cara(numUno, numDos);
	_getche();
	return 0;
}
