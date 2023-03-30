/*
Un arquitecto dedicado a impermeabilizar lozas desea desarrollar un sistema computacional que le ayude a elaborar sus cotizaciones. 
Para lograr lo anterior su algoritmo debe solicitar las medidas de largo y ancho de la loza, determinando metros cuadrados.
Sabiendo que una cubeta de 19 litros de impermeabilizante cuesta $ 920 pesos y rinde 19 m2.
El costo de mano de obra por metro cuadrado es de $ 20 pesos. Su sistema debe mostrar la siguiente información de salida:
-	Metros cuadrados totales de la loza
-	Cantidad de cubetas de impermeabilizante a requerir
-	Costo del impermeabilizante
-	Costo de la mano de obra
-	Total
-	20% de utilidad para el arquitecto
-	Costo total para el cliente (Total + 20% de utilidad)
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double largoLoza, anchoLoza;
	printf("Introduce Metros de Largo: "); scanf("%lf", &largoLoza);
	printf("Introduce Metros de Ancho : "); scanf("%lf", &anchoLoza);
	
	double volumenCubetaLitros = 19;
	double rendimientoCubeta = 19;
	double costoCubeta = 920;
	double costoManoObra = 20;
	double porcentajeUtilidad = 20;

	double areaLoza = largoLoza * anchoLoza;
	double rendimientoPorLitro = (rendimientoCubeta / volumenCubetaLitros);
	double litrosNecesarios = (areaLoza / rendimientoPorLitro);
	double numCubetas = ceil(litrosNecesarios / volumenCubetaLitros);
	double numCubetasUsadas = litrosNecesarios / volumenCubetaLitros;
	double costoTotalCubetas = costoCubeta * numCubetas;
	double costoTotalManoObra = costoManoObra * areaLoza;
	double costoTotal = costoTotalCubetas + costoTotalManoObra;
	double utilidadTotal = (porcentajeUtilidad / 100)*costoTotal;
	double costoTotalCliente = costoTotal + utilidadTotal;

	printf("\nMetros Cuadrados Totales de Loza     : %.3f m2", areaLoza);
	printf("\nCantidad Cubetas Necesarias          : %.3f cubetas", numCubetas);
	printf("\nCantidad Utilizada de Cubetas        : %.3f cubetas", numCubetasUsadas);
	printf("\nCantidad Utilizada en Litros         : %.3f litros", litrosNecesarios);
	printf("\nCosto Total del Impermeabilizante    : $%.3f", costoTotalCubetas);
	printf("\nCosto Total de la Mano de Obra       : $%.3f", costoTotalManoObra);
	printf("\nCosto Total                          : $%.3f", costoTotal);
	printf("\nUtilidad Arquitecto                  : $%.3f", utilidadTotal);
	printf("\nCosto Total para el Cliente          : $%.3f", costoTotalCliente);

	_getche();
	return 0;
}
