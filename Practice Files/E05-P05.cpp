/*
Un restaurante de la ciudad ofrece descuentos a sus clientes frecuentes de la siguiente forma:
Si en el mismo mes visitas el restaurante por primera vez, no tienes descuento pero,
si en el mismo mes ya es tu segunda visita obtienes un 20% de descuento. 
si en el mismo mes es tu tercera visita obtienes un 30% de descuento. 
si en el mismo mes es tu cuarta visita obtienes un 40% de descuento.
si es el mismo mes y ya es tu quinta visita o superior entonces tienes el 50% de descuento.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numVisitas;
	double compra, descuento;
	printf("Introduzca su monto de compra : "); scanf("%lf", &compra);
	printf("Incluyendo esta visita, cuantas veces nos ha visitado en este mes?  "); scanf("%d", &numVisitas);

	if (numVisitas == 1) {

		printf("\nVisitanos mas veces en el mismo mes para obtener importantes descuentos.");
		printf("\nMonto de Compra : $%.2f", compra);

	} else if (numVisitas == 2) {

		printf("\nFelicidades, ha obtenido un descuento del %c20.", 37);
		descuento = compra - (compra*(double(20) / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else if (numVisitas == 3) {

		printf("\nFelicidades, ha obtenido un descuento del %c30.", 37);
		descuento = compra - (compra*(double(30) / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else if (numVisitas == 4) {

		printf("\nFelicidades, ha obtenido un descuento del %c40.", 37);
		descuento = compra - (compra*(double(40) / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else if (numVisitas >= 5) {

		printf("\nFelicidades, ha obtenido un descuento del %c50.", 37);
		descuento = compra - (compra*(double(50) / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else {

		printf("\nError. Numero de visitas incorrecto.");

	}
	
	_getche();
	return 0;
}
