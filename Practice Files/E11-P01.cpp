/*
Elabore un programa que lea un valor entero “n”, dicho valor debe estar entre 1 y 21.
En caso de que el valor no cumpla con las condiciones deberá enviar un mensaje de error y regresar a solicitar el valor. 
Una vez que el valor es leído su programa deberá pintar un cuadro de nXn asteriscos iniciando por la línea superior 
La cual deberá pintarse lentamente de izquierda a derecha, posterior deberá pintar la línea derecha 
La cual deberá pintarse lentamente de arriba abajo, posterior deberá pintar la línea inferior en el sentido de derecha a izquierda 
Por último deberá pintar la línea izquierda en el sentido de abajo a arriba.
Es decir, cada línea del cuadro deberá pintarse lentamente en el sentido de las manecillas del reloj. 
Cuando el cuadro se ha terminado de pintar deberá hacer una pausa (getche()) y borrar el cuadro lentamente en el mismo orden 
y sentido que fue pintado.
Su programa debe tener las siguientes funciones:
-	Función que pide la “n”
-	Función que despliega el mensaje de error
-	Función que pinta el cuadro
-	Función que borra el cuadro
-	Función que hace el retardo
Por ningún motivo use variables GLOBALES.
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

int pedirEntero(int min, int Max);
void mensajeError(int error);
COORD dibujarCuadrado(int dimension);
void pausar();
void borrarCuadrado(int dimension, COORD cursor);

int main() {
	int ladoCuadrado = pedirEntero(1, 21);
	COORD cursor = dibujarCuadrado(ladoCuadrado);
	pausar();
	borrarCuadrado(ladoCuadrado, cursor);
	_getche();
	return 0;
}

int pedirEntero(int min, int max) {
	int enteroCorrecto;
	printf("\nIntroduzca un numero entero (entre %d y %d) : ", min, max); scanf("%d", &enteroCorrecto);
	while (enteroCorrecto >= max || enteroCorrecto <= min) {
		mensajeError(1);
		this_thread::sleep_for(chrono::milliseconds(2500));
		printf("\rIntroduzca un numero entero (entre %d y %d) : ", min, max); scanf("%d", &enteroCorrecto);
	}
	return enteroCorrecto;
}

void mensajeError(int error) {
	if (error == 1) {
		printf("\nError. El numero esta fuera del rango. ");
	}
}

void pausar() {
	_getche();
}

COORD dibujarCuadrado(int dimension) {

	printf("\n\n");
	int h = dimension;
	int m = (dimension)+(dimension - 1);
	bool terminado = false;
	int columna = 5;
	int fila = 5;
	COORD coord;
	coord.X = columna;
	coord.Y = fila;
	int velocidad = 40;

	HWND console = GetConsoleWindow(); RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1100, 600, TRUE);
	
	//Si el cuadrado tiene una dimension impar terminar de dibujar hacia la derecha.
	if ((h % 2) != 0) {
		
		//Mientras el cuadrado no este terminado continuar dibujando.
		while (terminado == false) {
			
			//Dibujar a la derecha (n) asteriscos.
			for (int i = 0; i < h; i++) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("*\b");
					this_thread::sleep_for(chrono::milliseconds(velocidad));
					coord.X += 1;
			}
			m--;
			
			//Acaba de dibujar a la derecha, por lo tanto checar si acabo de dibujar.
			if (m == 0) {
				terminado = true;
			} else {
				
				//Si no acabo de dibujar entonces dibujar hacia abajo, izquierda y arriba.
				h--;
				coord.X -= 1;
				for (int i = 0; i < h; i++) {
					coord.Y += 1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("*\b");
					this_thread::sleep_for(chrono::milliseconds(velocidad));
				}
				m--;
				for (int i = 0; i < h; i++) {
					coord.X -= 1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("*\b");
					this_thread::sleep_for(chrono::milliseconds(velocidad));
				}
				m--;
				h--;
				for (int i = 0; i < h; i++) {
					coord.Y -= 1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("*\b");
					this_thread::sleep_for(chrono::milliseconds(velocidad));
				}
				coord.X += 1;
				m--;
			}

		}
	} else {
		
		//Si la dimension es par entonces terminar de dibujar a la izquierda.
		while (terminado == false) {
			
			//Dibujar hacia derecha, abajo, e izquierda
			for (int i = 0; i < h; i++) {
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("*\b");
				this_thread::sleep_for(chrono::milliseconds(velocidad));
				coord.X += 1;
			}
			m--;
			h--;
			coord.X -= 1;
			for (int i = 0; i < h; i++) {
				coord.Y += 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("*\b");
				this_thread::sleep_for(chrono::milliseconds(velocidad));
			}
			m--;
			for (int i = 0; i < h; i++) {
				coord.X -= 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				printf("*\b");
				this_thread::sleep_for(chrono::milliseconds(velocidad));
			}
			m--;
			
			//Acaba de dibujar a la izquierda, por lo tanto checar si acabo de dibujar.
			if (m == 0) {
				terminado = true;
			} else {
				
				//Si no acabo de dibujar entonces dibujar hacia arriba
				h--;
				for (int i = 0; i < h; i++) {
					coord.Y -= 1;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
					printf("*\b");
					this_thread::sleep_for(chrono::milliseconds(velocidad));
				}
				coord.X += 1;
				m--;
			}
		}
	}	
	printf("\n\n");
	return coord;
	//La funcion genera las coordenadas en las que se quedo el cursor al final
	//para que la siguiente funcion de borrar pueda saber desde donde partir.
}

void borrarCuadrado(int dimension, COORD cursor) {
	COORD coord = cursor;
	int velocidad = 40;
	int h = 0;
	int m = (dimension)+(dimension - 1);
	int z = (dimension / 2);
	bool terminado = false;

	while (terminado == false) {
		if ((dimension % 2) != 0) {
			if (m == z) {
				terminado = true;
			} else {
				if (m == ((dimension)+(dimension - 1))) {
					h++;
					for (int i = 0; i < h + 1; i++) {
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf("\b ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
						coord.X -= 1;
					}
					m--;
				} else {
						for (int i = 0; i < h; i++) {
							coord.Y += 1;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf(" ");
							this_thread::sleep_for(chrono::milliseconds(velocidad));
						}
						h++;
						m--;
						for (int i = 0; i < h; i++) {
							coord.X += 1;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf(" ");
							this_thread::sleep_for(chrono::milliseconds(velocidad));
						}
						m--;
						for (int i = 0; i < h; i++) {
							coord.Y -= 1;
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf(" ");
							this_thread::sleep_for(chrono::milliseconds(velocidad));
						}
						h++;
						for (int i = 0; i < h; i++) {
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
							printf("\b ");
							this_thread::sleep_for(chrono::milliseconds(velocidad));
							coord.X -= 1;
						}
						m--;
				}
			}
		} else {
			if (m == z) {
				terminado = true;
			} else {
				if (m == ((dimension)+(dimension - 1))) {
					coord.X += 1;
					h++;
					for (int i = 0; i < h + 1; i++) {
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf("\b ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
						coord.X += 1;
					}
					m--;
					coord.X -= 2;
				} else {
					for (int i = 0; i < h; i++) {
						coord.Y -= 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf(" ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
					}
					h++;
					m--;
					for (int i = 0; i < h; i++) {
						coord.X -= 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf(" ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
					}
					if (m  == z) {
						terminado = true; break;
					}
					m--;
					for (int i = 0; i < h; i++) {
						coord.Y += 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf(" ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
					}
					h++;
					coord.X += 1;
					for (int i = 0; i < h; i++) {
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
						printf(" ");
						this_thread::sleep_for(chrono::milliseconds(velocidad));
						coord.X += 1;
					}
					coord.X -= 1;
					m--;
				}
			}
		}
	}
}
