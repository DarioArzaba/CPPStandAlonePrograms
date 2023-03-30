/*
Cuadrados y cubos. Elabore una aplicación que calcule y muestre los cuadrados y cubos de los números del 1 al 10:

Número  Cuadrado    Cubo
1       1           1
2       4           8
3       9           27
4       16          64

*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x = 1;
	int cuadrado = x*x;
	int cubo = x*x*x;
	printf("N%cmero       Cuadrado    Cubo", 163);
	printf("\n1            %d           %d", cuadrado, cubo); x = 2; cuadrado = x*x; cubo = x*x*x;
	printf("\n2            %d           %d", cuadrado, cubo); x = 3; cuadrado = x*x; cubo = x*x*x;
	printf("\n3            %d           %d", cuadrado, cubo); x = 4; cuadrado = x*x; cubo = x*x*x;
	printf("\n4            %d          %d", cuadrado, cubo); x = 5; cuadrado = x*x; cubo = x*x*x;
	printf("\n5            %d          %d", cuadrado, cubo); x = 6; cuadrado = x*x; cubo = x*x*x;
	printf("\n6            %d          %d", cuadrado, cubo); x = 7; cuadrado = x*x; cubo = x*x*x;
	printf("\n7            %d          %d", cuadrado, cubo); x = 8; cuadrado = x*x; cubo = x*x*x;
	printf("\n8            %d          %d", cuadrado, cubo); x = 9; cuadrado = x*x; cubo = x*x*x;
	printf("\n9            %d          %d", cuadrado, cubo); x = 10;  cuadrado = x*x; cubo = x*x*x;
	printf("\n10           %d         %d", cuadrado, cubo);
	
	_getche();
	return 0;
}
