/*
Una empresa dedicada a la fabricación de Tinacos para agua le ha pedido elaborar un programa que le permita calcular:
Costos de fabricación por pedido, cantidad de material por pedido, venta total por pedido y utilidad por pedido.
Para lo anterior debe considerar que la empresa fabrica tres modelos de tinacos, el modelo “A”, modelo “B” y modelo “C”.
- A 10m2 de Plastico 1 Flotador 1 Tapa de 1m de diametro
- B 15m2 de Plastico 1 Flotador 1 Tapa de 1.5m de diametro
- C 20m2 de Plastico 1 Flotador 1 Tapa de 2m de diametro
Precios Materiales
- Tapa de 1m = $25, Tapa de 1.5m = $35, Tapa de 2m = $45
- Metro Cuadrado = $50, Flotador = $20
Precios de Venta
- A = 760 , B = 1130 , C = 1490
El programa debe solicitar:
-	Cantidad de tinacos a fabricar de cada modelo
El programa debe mostrar:
-	Cantidad de material necesario en M2 de plástico, flotadores y tapas de cada medida de acuerdo al modelo
-	Costo total del material
-	Precio total de la venta
-	Utilidad de la venta
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

  	//Metros cuadrados, cantidad flotadores, cantidad tapas cada modelo, costo Fabricacion, venta total utilidad

	int numTinacosA, numTinacosB, numTinacosC;
	printf("Cantidad de Tinacos A: "); scanf("%d", &numTinacosA);
	printf("Cantidad de Tinacos B: "); scanf("%d", &numTinacosB);
	printf("Cantidad de Tinacos C: "); scanf("%d", &numTinacosC);

	//Cantidad y Costo de Material por Modelo

	int numFlotadoresA = 1; int numFlotadoresB = 1; int numFlotadoresC = 1;
	double mtsPlasticoA = 10; double mtsPlasticoB = 15; double mtsPlasticoC = 20;
	double diametroTapaA = 1.0; double diametroTapaB = 1.5; double diametroTapaC = 2.0;
	double costoTapaA = 25; double costoTapaB = 35; double costoTapaC = 45;
	double costoMetroPlastico = 50; double costoFlotador = 20;
	double ventaTinacoA = 760; double ventaTinacoB = 1130; double ventaTinacoC = 1490;
	int numTapasA = numTinacosA; int numTapasB = numTinacosB; int numTapasC = numTinacosC;

	//Total de Cantidad y Costo de Material por Modelo

	double totalPlasticoA = mtsPlasticoA * numTinacosA;
	double totalPlasticoB = mtsPlasticoB * numTinacosB;
	double totalPlasticoC = mtsPlasticoC * numTinacosC;
	double totalPlastico = totalPlasticoA + totalPlasticoB + totalPlasticoC;
	double costoTotalPlastico = totalPlastico * costoMetroPlastico;

	int totalFlotadoresA = numFlotadoresA * numTinacosA;
    	int totalFlotadoresB = numFlotadoresB * numTinacosB;
	int totalFlotadoresC = numFlotadoresC * numTinacosC;
	int totalFlotadores = totalFlotadoresA + totalFlotadoresB + totalFlotadoresC;
	double costoTotalFlotadores = totalFlotadores * costoFlotador;
	
	double costoTotalTapas = (numTapasA * costoTapaA) + (numTapasB * costoTapaB) + (numTapasC * costoTapaC);

	double costoTotal = costoTotalPlastico + costoTotalFlotadores + costoTotalTapas;
	double ventaTotal = (numTinacosA*ventaTinacoA) + (numTinacosB*ventaTinacoB) + (numTinacosC*ventaTinacoC);
	double utilidadTotal = ventaTotal - costoTotal;

	printf("\n%d tinacos A: %.2f m2 , %d flotadores y %d tapas de %.2f m de diametro. ",numTinacosA, totalPlasticoA, totalFlotadoresA, numTapasA, diametroTapaA);
	printf("\n%d tinacos B: %.2f m2 , %d flotadores y %d tapas de %.2f m de diametro. ",numTinacosB, totalPlasticoB, totalFlotadoresB, numTapasB, diametroTapaB);
	printf("\n%d tinacos C: %.2f m2 , %d flotadores y %d tapas de %.2f m de diametro.\n ",numTinacosC, totalPlasticoC, totalFlotadoresC, numTapasC, diametroTapaC);
	printf("\nCantidad Metros Plastico  : %.2f m2", totalPlastico);
	printf("\nCantidad Flotadores       : %d flotadores", totalFlotadores);
	printf("\nCosto Total Plastico      : $%.2f", costoTotalPlastico);
	printf("\nCosto Total Flotadores    : $%.2f", costoTotalFlotadores);
	printf("\nCosto Total Tapas         : $%.2f", costoTotalTapas);
	printf("\n\nCosto Total de Material   : $%.2f", costoTotal);
	printf("\nVenta Total               : $%.2f", ventaTotal);
	printf("\nUtilidad de Venta         : $%.2f", utilidadTotal);

	_getche();
	return 0;
}

