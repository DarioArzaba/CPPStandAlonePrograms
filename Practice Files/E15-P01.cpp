/*
Escribir un programa que llene un arreglo con los números comprendidos entre 0 y 100 divisibles por 3.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

int main(){
	int min = 0;
	int max = 100;
	int divisor = 3;
	vector<int> divisibles;
	for (int i = 0; i < max; ++i) {
		if ((i % divisor) == 0 && i != 0) {
			divisibles.push_back(i);
		}
	}
	printf("\nNumeros divisibles entre %d de %d a %d: ", divisor, min, max);
	for (int i = 0; i < divisibles.size(); ++i) {
		printf("%d , ", divisibles[i]);
	}
	printf("\b\b ");

	_getche();
	return 0;
}
