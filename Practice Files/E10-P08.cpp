/*
Elabore un programa que muestre un carácter cualquiera en la posición (1,1) de la pantalla, una vez que despliegue el carácter.
Su programa deberá solicitar un valor entero “n” entre 1 y 20 (valide). 
Cuando el valor es proporcionado correctamente su programa deberá mostrar el siguiente menú:
	1.-Derecha
	2.-Izquierda
	3.-Arriba
	4.-Abajo
	5.-Terminar
Solicitar la opcion, valide que este entre 1 y 5. Si el valor es de 10 y selecciona la opcion 1 el caracter se mueve 10 a la derecha.
Para dar efecto de animacion debe pintar el caracter, generar un retardo y borrarlo.
Al terminar debe quedarse en la posicion final, repetir la accion de solicitar un valor y desplegar el menu.
El siguiente movimiento del caracter debe de iniciar a partir de la ultima posicion segun el movimiento previo.
Esto debe repetirse hasta seleccionar la opcion de Terminar.
Suponga que el carácter se encuentra en la coordenada (3,10) y el usuario indica n=7 y la opción 2.-Izquierda.
Entonces su programa deberá recorrer el carácter en el siguiente orden:
(3,10) - (2,10) - (1,10) - (79,10) - (78,10) - (77,10) - (76,10) - (75,10)
Observe como cuando se termina la pantalla el carácter empieza en el otro extremo de la misma y continua el movimiento.
*/

#pragma comment (lib, "User32.lib")

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

int main() {

	//Note el uso de la libreria Windows y fuente de texto Consolas 20 (Ancho 9 px, Alto 20 px)
	//Con esta fuente una ventana de 1100 por 600 px tiene 116 columnas con 27 filas.

	int numUno;
	int rangoMin = 1;
	int rangoMax = 20;
	char caracter = '@';

	HWND console = GetConsoleWindow(); RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1100, 600, TRUE);

	int columna = 0;
	int fila = 0;
	COORD coord; coord.X = columna; coord.Y = fila;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("%c",caracter);
	this_thread::sleep_for(chrono::milliseconds(2000));
	system("CLS");

	bool terminar = false;
	int seleccion;

	while (terminar == false) {

		printf("\nIntroduzca un valor (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &numUno);
		while (numUno >= rangoMax || numUno <= rangoMin) {
			printf("\nError. El limite no esta entre %d y %d", rangoMin, rangoMax);
			this_thread::sleep_for(chrono::milliseconds(2500));
			printf("\rIntroduzca el valor (Entre %d y %d) : ", rangoMin, rangoMax); scanf("%d", &numUno);
		}

		printf("\n--------------------------------------------------------\n");
		printf("\n1) Derecha");
		printf("\n2) Izquierda");
		printf("\n3) Arriba");
		printf("\n4) Abajo");
		printf("\n5) Terminar");

		printf("\n\nElije una opci%cn : ", 162); scanf("%d", &seleccion);

		if (seleccion >= 1 && seleccion <= 5) {
			if (seleccion == 1) {

				system("CLS");
				coord.X = columna; coord.Y = fila;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("%c", caracter);

				for (int i = 0; i < numUno; i++) {

					if (columna > 116) {
						printf("\b ");
						columna = 0;
					}
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf(" ");
					columna += 1;
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("%c", caracter);
					this_thread::sleep_for(chrono::milliseconds(50));

				}

				this_thread::sleep_for(chrono::milliseconds(2000));
				system("CLS");

			} else if (seleccion == 2) {

				system("CLS");
				coord.X = columna; coord.Y = fila;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("%c", caracter);

				for (int i = 0; i < numUno; i++) {

					if (columna == 0) {
						system("CLS");
						columna = 116;
					}
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf(" ");
					columna -= 1;
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("%c", caracter);
					this_thread::sleep_for(chrono::milliseconds(50));

				}

				this_thread::sleep_for(chrono::milliseconds(2000));
				system("CLS");

			} else if (seleccion == 3) {

				system("CLS");
				coord.X = columna; coord.Y = fila;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("%c", caracter);

				for (int i = 0; i < numUno; i++) {

					if (fila <= 0) {
						system("CLS");
						fila = 27;
					}
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf(" ");
					fila -= 1;
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("%c", caracter);
					this_thread::sleep_for(chrono::milliseconds(75));

				}

				this_thread::sleep_for(chrono::milliseconds(2000));
				system("CLS");

			} else if (seleccion == 4) {

				system("CLS");
				coord.X = columna; coord.Y = fila;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("%c", caracter);

				for (int i = 0; i < numUno; i++) {

					if (fila > 27) {
						system("CLS");
						fila = 0;
					}
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf(" ");
					fila += 1;
					coord.X = columna; coord.Y = fila;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("%c", caracter);
					this_thread::sleep_for(chrono::milliseconds(75));

				}

				this_thread::sleep_for(chrono::milliseconds(2000));
				system("CLS");

			} else if (seleccion == 5) {
				terminar = true;
			} 
		} else {
			printf("\nError. Esa no es una opcion valida.");
		}
		
	}

	return 0;
}
