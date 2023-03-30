/*
Una tienda departamental ofrece a sus clientes un descuento por volumen de compra.
Si la compra es menor que 10,000 pesos no ofrece ningún descuento. 
Si la compra es mayor o igual que 10,000 pesos ofrece un 5% de descuento.
Si la compra es mayor o igual que 20,000 pesos ofrece un 10% de descuento.
Elaboré el código que pida el monto de compra y muestre como salida la siguiente información:
	Compra: 		17,325.00
	Descuento:		5%
	Descuento en pesos:	866.25
	Total al cobrar:		16,458.75
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double compra, descuentoA, descuentoB, descuento;
	descuento = 0; descuentoA = 5; descuentoB = 10;
	printf("Introduzca el monto de su compra : "); scanf("%lf", &compra);

	if (compra < 10000) {

		printf("\nCompra             :  $%.2f", compra);
		printf("\nDescuento          :  %c%.2f", 37, descuento);
		printf("\nDescuento en Pesos :  $%.2f", descuento);
		printf("\nTotal al Cobrar    :  $%.2f", compra);

	} else if (compra >= 10000 && compra < 20000) {

		descuento = (compra*(descuentoA / 100));
		printf("\nCompra             :  $%.2f", compra);
		printf("\nDescuento          :  %c%.2f", 37, descuentoA);
		printf("\nDescuento en Pesos :  $%.2f", descuento);
		printf("\nTotal al Cobrar    :  $%.2f", (compra - descuento));

	} else {

		descuento = (compra*(descuentoB / 100));
		printf("\nCompra             :  $%.2f", compra);
		printf("\nDescuento          :  %c%.2f", 37, descuentoB);
		printf("\nDescuento en Pesos :  $%.2f", descuento);
		printf("\nTotal al Cobrar    :  $%.2f", (compra - descuento));
		
	}
	
	_getche();
	return 0;
}
