/*
Una tienda que maneja cinco artículos diferentes le ha pedido elaborar un algoritmo para estimar el cálculo de sus ventas.
Los artículos que maneja son:
  Bicicletas			$ 1,200 pesos
  Llantas para bicicleta		$ 250 pesos
  Frenos				$ 150 pesos
  Marco para bicicleta		$ 600 pesos
  Asientos para bicicleta		$ 200 pesos
Su algoritmo deberá solicitar la cantidad de cada uno de los artículos a vender y estimar el precio total de la venta.
El programa deberá dar como salida, la venta total.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numBicicletas, numLlantas, numFrenos, numMarcos, numAsientos;
	printf("Cantidad de Bicicletas: "); scanf("%d", &numBicicletas);
	printf("Cantidad de Llantas: "); scanf("%d", &numLlantas);
	printf("Cantidad de Frenos: "); scanf("%d", &numFrenos);
	printf("Cantidad de Marcos: "); scanf("%d", &numMarcos);
	printf("Cantidad de Asientos: "); scanf("%d", &numAsientos);

	//Venta por Articulo

	double ventaBicicleta = 1200;
	double ventaLlanta = 250;
	double ventaFreno = 150;
	double ventaMarco = 600;
	double ventaAsiento = 200;

	//Venta Total

	double ventaTotalBicicletas = numBicicletas * ventaBicicleta;
	double ventaTotalLlantas = numLlantas * ventaLlanta;
	double ventaTotalFrenos = numFrenos * ventaFreno;
	double ventaTotalMarcos = numBicicletas * ventaMarco;
	double ventaTotalAsientos = numAsientos * ventaAsiento;
	double ventaTotal = ventaTotalBicicletas + ventaTotalLlantas + ventaTotalFrenos + ventaTotalMarcos + ventaTotalAsientos;

	printf("\nVenta Total : $%.2f", ventaTotal);

	_getche();
	return 0;
}
