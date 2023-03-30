/*
Calcular promedio. Elabore un programa que lea tres valores enteros proporcionados por el usuario.
Posteriormente calcule el promedio de  dichos valores y despliegue el resultado MOSTRANDO los tres valores capturados.
Mostrar la suma y el promedio de los mismos.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x, y, z, suma;
	double promedio;
	printf("Indica el Primer Valor Entero  : "); scanf("%d", &x);
	printf("Indica el Segundo Valor Entero : "); scanf("%d", &y);
	printf("Indica el Tercer Valor Entero  : "); scanf("%d", &z);
	suma = x + y + z;
	promedio = double(suma) / 3;
	printf("\nValores Capturados             : %d, %d, %d", x, y, z);
	printf("\nSuma de Valores Capturados     : %d", suma);
	printf("\nPromedio de Valores Capturados : %.2f", promedio);

	_getche();
	return 0;
}
