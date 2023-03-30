/*
Un vendedor de autos gana un sueldo mensual base de $ 10,000 pesos y además gana $ 1,000 pesos adicionales por auto vendido. 
Si el vendedor vende más de 10 autos (de 11 en adelante) pero menos de 20 recibe un bono adicional de $ 5,000 pesos
Si vende 20 o más autos en el mismo mes recibe otro bono adicional de otros $ 5,000 pesos. 
Bajo las condiciones establecidas, escriba las preguntas que me permitan saber cuanto ganaría el vendedor en un mes. 
Recuerde que todo es adicional.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int numAutos;
	double sueldoFijo = 10000;
	double comisionAuto = 1000;
	double bonoA = 5000;
	double bonoB = 5000;
	double bonoTotal;
	double sueldoMensual;

	printf("Introduzca cantidad de autos vendidos: "); scanf("%d", &numAutos);

	if (numAutos > 10 && numAutos < 20) {
	
		bonoTotal = bonoA;
		sueldoMensual = sueldoFijo + (numAutos*comisionAuto) + bonoTotal;
		printf("\nTe has ganado un bono de $%.2f ", bonoTotal);
		printf("\nTu sueldo mensual es de: $%.2f", sueldoMensual);
		
	} else if (numAutos >= 20) {
	
		bonoTotal = bonoA + bonoB;
		sueldoMensual = sueldoFijo + (numAutos*comisionAuto) + bonoTotal;
		printf("\nTe has ganado un bono de $%.2f ", bonoTotal);
		printf("\nTu sueldo mensual es de: $%.2f", sueldoMensual);
		
	} else {
	
		sueldoMensual = sueldoFijo + (numAutos*comisionAuto);
		printf("\nTu sueldo mensual es de: $%.2f", sueldoMensual);
		
	}

	_getche();
	return 0;
}
