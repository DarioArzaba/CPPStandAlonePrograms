/*
Escribir un programa que llene un arreglo de 10 números enteros aleatorios comprendidos entre 50 y 100.
Copie en otro arreglo esos números multiplicados por 0,5 muestre ambos arreglos. 
Investigue como funciona la instrucción “rand()” y que librería requiere.
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <random>
using namespace std;

int main(){
	int min = 50;
	int max = 100;
	random_device   rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int>  distr(min, max);
	int arreglo[10];
	double arregloMultiplicado[10];
	for (int i = 0; i < 10; ++i) {
		arreglo[i] = distr(generator);
	}
	printf("\nVector Random: "); 
	for (int i = 0; i < 10; ++i) {
		printf("%d , ", arreglo[i]);
		arregloMultiplicado[i] = ((double)(arreglo[i]) * 0.5);
	}
	printf("\b\b ");
	printf("\n\nVector Random Multiplicado: ");
	for (int i = 0; i < 10; ++i) {
		printf("%.1f , ", arregloMultiplicado[i]);
	}
	printf("\b\b ");
	_getche();
	return 0;
}
