/*
Elabore un programa que lea dos palabras, ambas palabras deben tener entre 5 y 20 caracteres (valide). 
Una vez leídas ambas palabras su programa deberá mostrar como salida:
  Longitud en caracteres de la primera palabra
  Longitud en caracteres de la segunda palabra
  Compara ambas palabras e indicar si son iguales
EN CASO DE QUE NO SEAN IGUALES deberá comparar carácter por carácter e indicar si son iguales en los primeros “n” caracteres, 
por ejemplo suponga que se capturo “perro” y “perrito”. 
En este caso ambas palabras son diferentes pero son iguales en los primeros 4 caracteres (perr).
  Convertir las palabras a mayúsculas y desplegarlas
  Unir ambas palabras con un espacio en blanco en el medio y decir la frase completa, 
por ejemplo, si se captura “gato” y “bonito” su frase completa deberá decir “gato bonito”.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

string capturarPalabra(int min, int max, int text) {
	string palabra;
	if (text == 1) {
		printf("\n\nIntroduce la primer palabra:  \n");
	} else if (text == 2) {
		printf("\n\nIntroduce la segunda palabra:  \n");
	}
	getline(cin, palabra);
	while ((palabra.length()) > max || (palabra.length()) < min) {
		printf("\nError. Debe introducir entre %d y %d caracteres.", min, max);
		printf("\n\nIntroduce la palabra:  \n"); getline(cin, palabra);
	}
	palabra.erase(remove_if(palabra.begin(), palabra.end(), isspace), palabra.end());
	return palabra;
}

string comparar(string first, string second) {
	string iguales = ""; char c;
	if (first.front() != second.front()){
		return iguales;
	} else {
		int mejor;
		if (first.length() > second.length()) {
			mejor = first.length();
		} else {
			mejor = second.length();
		}
		for (int i = 0; i < mejor; ++i) {
			if (first[i] == second[i]) {
				c = first[i];
				iguales += c;
			} else {
				return iguales;
			}
		}
	}
}

int main() {

	printf("\nBienvenido.\n");
	int min = 5; int max = 20;
	string primerPalabra = capturarPalabra(min, max, 1);
	string segundaPalabra = capturarPalabra(min, max, 2);
	printf("\nLongitud Primera:  %d", primerPalabra.length());
	printf("\nLongitud Segunda:  %d", segundaPalabra.length());
	if (primerPalabra.compare(segundaPalabra) == 0) {
		printf("\nComparacion:  Las palabras son iguales.");
	} else {
		printf("\nComparacion:  Las palabras son distintas.");
		string igualesEn = comparar(primerPalabra, segundaPalabra);
		printf("\nIguales en (%d) caracteres: (%s)", igualesEn.length(), igualesEn.c_str());
	}

	string primerMayuscula, segundaMayuscula;
	for (int i = 0; i < primerPalabra.length(); ++i) {
		primerMayuscula += toupper(primerPalabra[i]);
	}
	for (int i = 0; i < segundaPalabra.length(); ++i) {
		segundaMayuscula += toupper(segundaPalabra[i]);
	}
	printf("\nPrimer palabra en mayusculas:  %s", primerMayuscula.c_str());
	printf("\nSegunda palabra en mayusculas:  %s", segundaMayuscula.c_str());
	string unionPalabras = primerPalabra + " " + segundaPalabra;
	printf("\nUnion palabras:  %s", unionPalabras.c_str());
	_getche();
	return 0;
}
