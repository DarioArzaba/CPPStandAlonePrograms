/*
Escribir un programa que almacene en un arreglo los números primos comprendidos entre 1 y 100.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

int main() {
	
	vector<int> primos;
	int numUno = 0;
	int numDos = 100;
	int textoNumUno = numUno;
	bool esPrimo;

	for (int i = numUno; i <= numDos; i++) {
		esPrimo = true;
		if (i <= 1) {
			esPrimo = false;
		} else {
			for (int j = 2; (j*j) <= i; j++) {
				if (i % j == 0) esPrimo = false;
			}
		}
		if (esPrimo == true) {
			primos.push_back(i);
		}
	}
	
	printf("\nNumeros primos en el arreglo, de %d a %d: ", textoNumUno, numDos);
	for (int i = 0; i < primos.size(); ++i) {
		printf("%d , ", primos[i]);
	}
	printf("\b\b ");

	_getche();
	return 0;
}
