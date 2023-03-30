/*
Programa que lea una palabra o frase, su programa debe validar que la palabra o frase tenga entre 5 y 20 caracteres (incluidos).
Una vez que el valor es dado correctamente este deberá desplegar la palabra al revés. 
Por ejemplo si la palabra dada es “perritos” su programa deberá desplegar “sotirrep”. 
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>

using namespace std;

int main() {

	string palabra;
	int minChar = 5;
	int maxChar = 20;
	printf("\nIntroduce la palabra o frase:  ");
	getline(cin, palabra);
	while ((palabra.length()) > maxChar || (palabra.length()) < minChar) {
		printf("Error. Debe introducir entre %d y %d caracteres.\n", minChar, maxChar);
		printf("Introduce la palabra o frase:  ");
		getline(cin, palabra);
	}

	printf("\nOriginal: %s\n", palabra.c_str());
	reverse(palabra.begin(), palabra.end());
	printf("Inversa: %s", palabra.c_str());
	
	_getche();
	return 0;
}
