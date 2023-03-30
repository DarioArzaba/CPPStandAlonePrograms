/*
Una microempresa dedicada a la fabricación de pasteles ha detectado demasiados errores en la estimación de sus utilidades por día.
La causa aparente de dichos errores se debe a que sus empleados cometen errores en los cálculos de los costos de fabricación. 
Elaborar un programa que le permita realizar el cálculo de dichas utilidades con base en la siguiente información:
- La empresa fabrica tres tamaños de pasteles: 1 kilo, 2 kilos y 3 kilos
- Cada kilo de pastel requiere:
	500 g harina $25 pesos
	250 g huevo $8 pesos
	100 g azucar $5 pesos
	100 g saborizante $10 pesos
	0.5 litro leche $5 pesos
	Mano Obra $20 pesos
	Horneado $5 pesos
Cada Kilo de Pastel se vende en $100 pesos.
El usuário ingresará la cantiadad de pasteles de cada tamaño vendidos por día para mostrar:
- Cantidad de harina, huevos, azucar y saborizante en kilos junto con su costo total.
- Cantidad de leche en litros junto con su costo total.
- Costo total de la mano de obra y del horneado.
- Costo Total de Insumos del Dia.
- Venta Total del Dia.
- Utilidad Final del Dia.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {
	
	int numPastelesA, numPastelesB, numPastelesC;
	
	printf("Introduce Cantidad de Pasteles tipo A : "); scanf("%d", &numPastelesA);
	printf("Introduce Cantidad de Pasteles tipo B : "); scanf("%d", &numPastelesB);
	printf("Introduce Cantidad de Pasteles tipo C : "); scanf("%d", &numPastelesC);
	
	//Ingredientes y su Costo por Kilo de Pastel

	double cantidadHarina = 0.5; double costoHarina = 25;
	double cantidadHuevo = 0.25; double costoHuevo = 8;
	double cantidadAzucar = 0.1; double costoAzucar = 5;
	double cantidadSaborizante = 0.1; double costoSaborizante = 10;
	double cantidadLeche = 0.5; double costoLeche = 5;
	double costoManoObra = 20; double costoHorneado = 5;
	double ventaPorKilo = 100;
	
	//Peso en Kilos por Tipo de Pastel

	double pesoPastelesA = 1; double pesoPastelesB = 2; double pesoPastelesC = 3;
	double pesoTotalA = pesoPastelesA * numPastelesA;
	double pesoTotalB = pesoPastelesB * numPastelesB;
	double pesoTotalC = pesoPastelesC * numPastelesC;
	double pesoTotal = pesoTotalA + pesoTotalB + pesoTotalC;
	
	//Cantidad y Costo de Cada Ingrediente
	
	double cantidadTotalHarina = cantidadHarina * pesoTotal; 
	double costoTotalHarina = costoHarina * cantidadTotalHarina;
	double cantidadTotalHuevo = cantidadHuevo * pesoTotal; 
	double costoTotalHuevo = costoHuevo * cantidadTotalHuevo;
	double cantidadTotalAzucar = cantidadAzucar * pesoTotal; 
	double costoTotalAzucar = costoAzucar * cantidadTotalAzucar;
	double cantidadTotalSaborizante = cantidadSaborizante * pesoTotal; 
	double costoTotalSaborizante = costoSaborizante * cantidadTotalSaborizante;
	double cantidadTotalLeche = cantidadLeche * pesoTotal; 
	double costoTotalLeche = costoLeche * cantidadTotalLeche;
	
	//Costos Adicionales
	
	double costoTotalManoObra = costoManoObra * pesoTotal;
	double costoTotalHorneado = costoHorneado * pesoTotal;
	
	//Costo, Venta y Utilidad Final
	
	double costoTotal = costoTotalManoObra + costoTotalHorneado + costoTotalHarina + costoTotalHuevo + costoTotalAzucar + costoTotalSaborizante + costoTotalLeche;
	double ventaTotal = ventaPorKilo * pesoTotal;
	double utilidadTotal = ventaTotal - costoTotal;

	printf("\nCantidad y Costo Total de Harina       : %.1f kg , $%.2f", cantidadTotalHarina, costoTotalHarina);
	printf("\nCantidad y Costo Total de Huevo        : %.1f kg , $%.2f", cantidadTotalHuevo, costoTotalHuevo);
	printf("\nCantidad y Costo Total de Azucar       : %.1f kg , $%.2f", cantidadTotalAzucar, costoTotalAzucar);
	printf("\nCantidad y Costo Total de Saborizante  : %.1f kg , $%.2f", cantidadTotalSaborizante, costoTotalSaborizante);
	printf("\nCantidad y Costo Total de Leche        : %.1f L  , $%.2f", cantidadTotalLeche, costoTotalLeche);
	printf("\nCosto Total Mano de Obra               : $%.2f", costoTotalManoObra);
	printf("\nCosto Total Horneado                   : $%.2f", costoTotalHorneado);
	printf("\nCosto Total Insumos del Dia            : $%.2f", costoTotal);
	printf("\nVenta Total del Dia                    : $%.2f", ventaTotal);
	printf("\nUtilidad Final del Dia                 : $%.2f", utilidadTotal);

	_getche();
	return 0;
}
