/*
Leer y desplegar una variable entera
Elabore un programa que defina una variable entera x, posteriormente lea un valor que le proporcione el usuario y guárdelo en x.
Al final despliegue el valor leído.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x;
	printf("Introdusca un Valor Entero:  "); scanf("%d", &x);
	printf("Valor Introducido: %d", x);
	
	_getche();
	return 0;
}
