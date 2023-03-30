/*
Una tienda que maneja cinco artículos diferentes le ha pedido elaborar un algoritmo para estimar el cálculo de sus ventas.
Los artículos que maneja son:
	Bicicletas		$ 1,200 pesos
	Llantas para bicicleta	$ 250 pesos
	Frenos			$ 150 pesos
	Marco para bicicleta	$ 600 pesos
	Asientos para bicicleta	$ 200 pesos
Su algoritmo deberá solicitar la cantidad de cada uno de los artículos a vender.
Estimar el precio total de la venta bajo las siguientes observaciones:
	Si la venta es menor de $ 1000 pesos se cobrará el total de la venta 
	Si la venta está entre $ 1,000 pesos y menos de $ 3000 pesos se hará un 10% de descuento
	Si la venta está entre $ 3000 pesos y menos de $ 6000 pesos se hará el 15% de descuento
	Si la venta es de $ 6000 pesos o más se hará un 20% de descuento
El programa deberá dar como salida, la venta total, el descuento a aplicar en porcentaje, el descuento a aplicar en pesos.
Y la venta menos el descuento, que será el importe total a cobrar al cliente.
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

	double descuento, descuentoPesos, importeCobrar;

	if (ventaTotal < 1000) {
		printf("\nVenta Total : $%.2f", ventaTotal);
	} else if (ventaTotal < 3000) {
		descuento = 10;
		descuentoPesos = (descuento / 100)*ventaTotal;
		importeCobrar = (ventaTotal - descuentoPesos);
		printf("\nVenta Total : $%.2f", ventaTotal);
		printf("\nDescuento : %c%.2f", 37, descuento);
		printf("\nDescuento en Pesos : $%.2f ", descuentoPesos);
		printf("\nImporte a Cobrar : $%.2f", importeCobrar);
	} else if (ventaTotal < 6000) {
		descuento = 15;
		descuentoPesos = (descuento / 100)*ventaTotal;
		importeCobrar = ventaTotal - descuentoPesos;
		printf("\nVenta Total : $%.2f", ventaTotal);
		printf("\nDescuento : %c%.2f", 37, descuento);
		printf("\nDescuento en Pesos : $%.2f ", descuentoPesos);
		printf("\nImporte a Cobrar : $%.2f", importeCobrar);
	} else {
		descuento = 20;
		descuentoPesos = (descuento / 100)*ventaTotal;
		importeCobrar = ventaTotal - descuentoPesos;
		printf("\nVenta Total : $%.2f", ventaTotal);
		printf("\nDescuento : %c%.2f", 37, descuento);
		printf("\nDescuento en Pesos $%.2f: ", descuentoPesos);
		printf("\nImporte a Cobrar : $%.2f", importeCobrar);
	}
	
	_getche();
	return 0;
}
