/*
Una tienda departamental ofrece a sus clientes descuentos de acuerdo a al volumen de compra.
Si la compra es menor que 1000 pesos no se le otorga descuento.
Si su compra es mayor o igual que 1000 pesos y menor que 5000 pesos se le otorga un 5% de descuento.
Si la compra es mayor o igual que 5000 pesos y menor que 10000 pesos se le otorga un 10% de descuento.
Si la compra es mayor o igual que 10000 pesos se le otorga un 15% de descuento.


*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double compra, descuentoA, descuentoB, descuentoC, descuento;
	descuentoA = 5; descuentoB = 10; descuentoC = 15;
	printf("Introduzca el monto de su compra : "); scanf("%lf", &compra);

	if (compra < 1000) {

		printf("\nNecesita comprar mas de $1000 para obtener un descuento.");

	} else if (compra >= 1000 && compra < 5000) {

		printf("\nFelicidades, ha obtenido un descuento del %c%.0f.", 37, descuentoA);
		descuento = compra - (compra*(descuentoA / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else if (compra >= 5000 && compra < 10000) {

		printf("\nFelicidades, ha obtenido un descuento del  %c%.0f.", 37, descuentoB);
		descuento = compra - (compra*(descuentoB / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	} else {

		printf("\nFelicidades, ha obtenido un descuento del  %c%.0f.", 37, descuentoC);
		descuento = compra - (compra*(descuentoC / 100));
		printf("\nNuevo Monto de Compra : $%.2f", descuento);

	}

	_getche();
	return 0;
}
