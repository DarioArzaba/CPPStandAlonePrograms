/*
Desplegar el valor de una variable. Elabore un programa que defina una variable entera x y que le asigne un valor de 10.
Posteriormente despliegue el letrero.

	El valor de X es: 10

Donde el valor de 10 cambiará en el letrero conforme cambie el valor de la variable dentro de su programa.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x = 10;
	printf("El valor de X es: %d", x);
	
	_getche();
	return 0;
}
