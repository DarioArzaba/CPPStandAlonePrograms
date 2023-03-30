/*
Usando C++ elabore un programa que haga que el carrito del ejercicio “3” se mueva de la posición 1,3 a la posición 60,3 
Avanzando de uno en uno, recuerde que para hacer el efecto de animación debe pintar, retardar y borrar. 
Para estas tres acciones debe hacer tres funciones diferentes, es decir debe existir una función “carro” que pintará el carro.
Una función “retardo” que será el retardador y una función “borra” que será la función que borra el carrito. 
Las tres funciones deberán estar dentro de un ciclo que corra de 1 a 60 en la función main().
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void carro(int x) {
	COORD coord;
	coord.X = x;
	coord.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	int contador = 0;
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("            *********            \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("           ********  *           \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("          *********   *          \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("    **************************   \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("    **************************   \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("    **************************   \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("      *****           *****      \n");
	coord.Y = (1 + contador); SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  contador++;
	printf("      *****           *****      \n");
}
void retardo(int miliseg) {
	Sleep(miliseg);
}
void borra() {
	system("cls");
}

int main() {

	for (int i = 1; i <= 60; i++) {
		
		carro(i);
		retardo(75);
		borra();

	}

	_getche();
	return 0;
}
