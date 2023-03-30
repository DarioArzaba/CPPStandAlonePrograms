/*
Para mayor seguridad en los accesos o en los contenidos de algunos archivos se usa la encripción 
para evitar que se vea la información real. 
Una encripción cambia el valor de una letra por otra de acuerdo a un código preestablecido, 
por ejemplo si nosotros usamos un código “Shift 1” sabemos que debemos recorrer las letras una posición en el abecedario 
para codificar o decodificar un valor. Suponga que el usuario introduce la palabra “gato”. Observe el código “Shift 1”
  Abecedarios normal	: a b c d e f g h i j k l m n o p q r s t u v w x y z
  Abecedario shift 1	: z a b c d e f g h i j k l m n o p q r s t u v w x y
Por lo tanto una “g” en al abecedario normal equivale a una “f” en shift 1, una “a” equivale a una “z”, 
una “t” equivale a una “s” y una “o” equivale a una “”n”, esto quiere decir que:
En abecedario normal: “gato” equivale a “fzsn” en shift 1.
En abecedario normal: “perro” equivale a “odqqn”” en shift 1.
Una vez entendido lo anterior elabore un programa que muestre el siguiente menú:
  a)	De normal a shift 1
  b)	De shift1 a normal
  c)	Terminar
Opción “a”: Deberá leer una palabra entre 5 y 25 caracteres en abecedario normal y desplegar el equivalente en shift .
Opción “b”: Deberá leer una palabra entre 5 y 25 caracteres en shift 1y desplegar el equivalente en abecedario normal.
Opción “c”: Deberá terminar el programa.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

char menu() {
	char opcion = 'g';
	printf("\nElige una de las siguientes opciones: ");
	printf("\na) De normal a shift 1 ");
	printf("\nb) De shift 1 a normal");
	printf("\nc) Terminar");
	printf("\nOpcion: ");
	opcion = getchar(); getchar();
	return opcion;
}

string pedirpalabra(int minChar, int maxChar) {
	string palabra;
	printf("\nIntroduce la palabra:  \n"); getline(cin, palabra);
	palabra.erase(remove_if(palabra.begin(), palabra.end(), [](char c) { return !isalpha(c); }), palabra.end());
	while ((palabra.length()) > maxChar || (palabra.length()) < minChar) {
		printf("\nError. Debe introducir entre %d y %d caracteres.\n", minChar, maxChar);
		printf("\nIntroduce el usuario:  \n"); getline(cin, palabra);
		palabra.erase(remove_if(palabra.begin(), palabra.end(), [](char c) { return !isalpha(c); }), palabra.end());
	}
	return palabra;
}

char normal(char ch) {
	if (ch == 'z') {
		return 'a';
	} else if (ch == 'Z') {
		return 'A';
	} else {
		return ch + 1;
	}
}

char shift(char ch) {
	if (ch == 'a') {
		return 'z';
	} else if (ch == 'A') {
		return 'Z';
	} else {
		return ch - 1;
	}
}

void pasarShift(string palabra) {
	string resultado;
	for (int i = 0; i < palabra.length(); i++) {
		resultado += shift(palabra[i]);
	}
	printf("\nPalabra a Shift: %s\n", resultado.c_str());
}

void pasarNormal(string palabra) {
	string resultado;
	for (int i = 0; i < palabra.length(); i++) {
		resultado += normal(palabra[i]);
	}
	printf("\nPalabra a Shift: %s\n", resultado.c_str());
}

int main() {

	printf("\nBienvenido.\n");
	int minChar = 5; int maxChar = 25;
	bool terminarPreguntar = false;
	char seleccion;
	while (terminarPreguntar == false) {
		seleccion = menu();
		if (seleccion == 'a') {
			string palabra = pedirpalabra(minChar, maxChar);
			pasarShift(palabra);
		} else if (seleccion == 'b') {
			string palabra = pedirpalabra(minChar, maxChar);
			pasarNormal(palabra);
		} else if (seleccion == 'c') {
			terminarPreguntar = true; break;
		} else {
			printf("\nError. Opcion no valida.\n");
		}
	}

	return 0;
}
