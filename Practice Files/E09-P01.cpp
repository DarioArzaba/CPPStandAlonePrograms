/*
Elabore un programa que despliegue los números del 1 al 10 en forma de lista usando el estatuto while.
*/
	
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numero = 1;
	while (numero <= 10) {
		printf("\n%d", numero);
		numero += 1;
	}

	_getche();
	return 0;
}

