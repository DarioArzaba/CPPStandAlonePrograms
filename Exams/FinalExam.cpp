#pragma comment (lib, "User32.lib")

#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;

//Crear matriz de 4 renglones y 18 columnas
int matriz[4][18];
char numero[2];

void cambiarTamanoVentana (int largo, int alto) {
	HWND console = GetConsoleWindow(); RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, largo, alto, TRUE);
}

int main() {
	//Cambiar tamano de la ventana
	cambiarTamanoVentana(1250, 600);
	
	int fil = 0;
	int col = 0;
	int numeroTemp = 0;
	
	//Abrir el archivo
	ifstream archivoNumeros;
	archivoNumeros.open("texto_examen_final.txt", ios::in);
	//Error si el archivo no abre
	if (archivoNumeros.fail()) {
		printf("\n\n Error. El archivo texto_examen_final.txt no existe !");
		getche();
	} else {
		while (!archivoNumeros.eof()) {
			//Obtener numero
			archivoNumeros >> numero;
			numeroTemp = atoi(numero);
			//Copiar a matriz y cambiar de fila al llegar a 18
			if (fil == 0 && !archivoNumeros.eof()){
				matriz[fil][col] = numeroTemp;
				col++;
				if (col == 18){ fil = 1; col = 0; }
			} else if (fil == 1 && !archivoNumeros.eof()){
				matriz[fil][col] = numeroTemp;
				col++;
				if (col == 18){ fil = 2; col = 0; }	
			} else if (fil == 2 && !archivoNumeros.eof()){
				matriz[fil][col] = numeroTemp;
				col++;
				if (col == 18){ fil = 3; col = 0; }	
			} else if (fil == 3 && !archivoNumeros.eof()){
				matriz[fil][col] = numeroTemp;
				col++;
				if (col == 18){ fil = 4; col = 0; }	
			}	
		}
	}
	//Cerrar el archivo
	archivoNumeros.close();
	
	//Imprimir solo numeros
	printf("\n\n Matriz: \n\n");
	for (int i = 0; i < 4 ; i++){
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("| ");
		for (int j = 0; j < 18 ; j++){
			printf("%d", matriz[i][j] );
			printf(" | ");
		}
	}  
	printf("\n------------------------------------------------------------------------------------------\n");
	
	//Pausa
	Sleep(2000);
	system("cls");
	
	//Imprimir con mensaje
	printf("\n\n Mensaje: \n\n");
	for (int i = 0; i < 4 ; i++){
		printf("\n---------------------------------------------------------------------------\n");
		printf("| ");
		for (int j = 0; j < 18 ; j++){
			printf("%c", matriz[i][j] );
			printf(" | ");
		}
	}  
	printf("\n---------------------------------------------------------------------------\n");

	//Salir
	getche();
}






