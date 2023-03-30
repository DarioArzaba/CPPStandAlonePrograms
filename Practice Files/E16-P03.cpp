/*
Elabore un programa que despliegue el siguiente menú:
  a)	Indicar la palabra
  b)	Mostrar la palabra
  c)	Mostrar la palabra al revés
  d)	Mostrar vocales
  e)	Mostrar consonantes
  f)	Mostrar letra de una posición
Observe que las opciones del menú están dadas con letra y el usuario podrá usar mayúsculas y minúsculas de forma indistinta 
para seleccionar la opción deseada.
El menú deberá estar ciclado y sólo podrá terminar cuando el usuario oprima la tecla de “ESC”
Opción “A”: Esta opción deberá solicitar una palabra entre 5 y 20 caracteres, valide estas condiciones.
Opción “B”: Al seleccionar esta opción se deberá  desplegar la palabra que haya sido introducida en la opción “A”.
Opción “C”: Al seleccionar esta opción deberá desplegar la palabra de la opción “A” al revés, por ejemplo, 
si la palabra es “teclado” su programa deberá desplegar “odalcet”.
Opción “D”: Al seleccionar esta opción deberá desplegar las vocales contenidas en la palabra, por ejemplo, 
si la palabra es “teclado” su programa deberá desplegar “eao”.
Opción “E”: Al seleccionar esta opción deberá desplegar las consonantes contenidas en la palabra, por ejemplo, 
si la palabra es “teclado” su programa deberá desplegar “tcld”.
Opción “F”: Al seleccionar esta opción deberá solicitar un valor entero entre 0 y la longitud de la palabra (valide). 
Cuando el valor entero es dado correctamente su programa deberá desplegar la letra correspondiente a la posición indicada. 
Por ejemplo, si la palabra es “teclado” y el valor entero es 2, su programa deberá desplegar “c”.
*/

#pragma comment (lib, "User32.lib")

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

char menu() {
	char opcion = 'g';
	printf("\nElige una de las siguientes opciones: ");
	printf("\na) Indicar la palabra ");
	printf("\nb) Mostrar la palabra");
	printf("\nc) Mostrar la palabra al reves");
	printf("\nd) Mostrar vocales");
	printf("\ne) Mostrar consonantes");
	printf("\nf) Mostrar letra de una posicion");
	printf("\nOpcion: ");
	opcion = _getch();
	return opcion;
}

void error(int num) {
	if (num == 1) {
		printf("\n\nError. Necesita primero indicar la palabra.\n");
	}
}

string capturar(int min, int max) {
	string palabra;
	printf("\n\nIntroduce la palabra:  \n"); getline(cin, palabra);
	while ((palabra.length()) > max || (palabra.length()) < min) {
		printf("\nError. Debe introducir entre %d y %d caracteres.", min, max);
		printf("\n\nIntroduce la palabra:  \n"); getline(cin, palabra);
	}
	palabra.erase(remove_if(palabra.begin(), palabra.end(), isspace), palabra.end());
	return palabra;
}

void mostrar(string str) {
	printf("\n\nPalabra: %s\n", str.c_str());
}

void mostrarInversa(string str) {
	string inversa = str;
	reverse(inversa.begin(), inversa.end());
	printf("\n\nInversa: %s\n", inversa.c_str());
}

void mostrarVocales(string str) {
	string edit = str;
	vector<char> caracteres{'b', 'c', 'd', 'f', 'g','h', 'j', 'k', 'l','m', 'n', 'p', 'q', 'r','s', 't', 'v', 'w', 'x','y', 'z'};
	for (int i = 0; i < edit.size(); i++) {
		for (char c : caracteres) {
			if (edit.at(i) == c) {
				edit.erase(i--, 1);
				break;
			}
		}
	}
	printf("\n\nVocales: %s\n", edit.c_str());
}

void mostrarConsonantes(string str) {
	string edit = str;
	vector<char> vocales{ 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < edit.size(); i++) {
		for (char c : vocales) {
			if (edit.at(i) == c) {
				edit.erase(i--, 1);
				break;
			}
		}
	}
	printf("\n\nConsonantes: %s\n", edit.c_str());
}

void mostrarPosicion(string str) {
	int posicion;
	int min = 0;
	int max = (str.length()-1);
	printf("\n\nIntroduce una posicion entre %d y %d:  ", min, max);
	scanf("%d", &posicion);
	while (posicion > max || posicion < min) {
		printf("\nError. La posicion esta fuera del rango de la palabra.\n");
		printf("\n\nIntroduce una posicion entre %d y %d:  ", min, max);
		scanf("%d", &posicion);
	}
	char c = str.at(posicion);
	printf("\nCaracter en posicion: %c\n", c);
}

int main() {

	printf("\nBienvenido. Presiona ESC para salir.\n");

	bool terminarPreguntar = false;
	bool palabraIndicada = false;
	char seleccion; string palabra;
	int minCar = 5; int maxCar = 20;
	while (terminarPreguntar == false) {
		seleccion = menu();
		if (seleccion == 27) { 
			terminarPreguntar = true; break; 
		} else if (seleccion == 'a' || seleccion == 'A') { 
			palabra = capturar(minCar, maxCar); palabraIndicada = true; 
		} else if (seleccion == 'b' || seleccion == 'B') { 
			if (palabraIndicada == true) { mostrar(palabra); _getche(); } else { error(1); }
		} else if (seleccion == 'c' || seleccion == 'C') { 
			if (palabraIndicada == true) { mostrarInversa(palabra); _getche(); } else { error(1); } 
		} else if (seleccion == 'd' || seleccion == 'D') { 
			if (palabraIndicada == true) { mostrarVocales(palabra); _getche(); } else { error(1); } 
		} else if (seleccion == 'e' || seleccion == 'E') { 
			if (palabraIndicada == true) { mostrarConsonantes(palabra); _getche(); } else { error(1); } 
		} else if (seleccion == 'f' || seleccion == 'F') { 
			if (palabraIndicada == true) { mostrarPosicion(palabra); _getche(); } else { error(1); } 
		} else {
			printf("\n\nError. Opcion no valida.\n");
		}
	}

	return 0;
}
