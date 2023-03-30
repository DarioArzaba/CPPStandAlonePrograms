/*
Un contador tiene dificultades para calcular la depreciación de los Activos de la empresa.
le ha pedido elaborar un programa que le ayude con este cálculo. Los datos que serán proporcionados por el contador son: 
valor del activo (en pesos), porcentaje de depreciación anual y años transcurridos desde la compra del activo. 
La fórmula para calcular la depreciación es:
	Depreciación = (valor del activo) * (porcentaje) * años transcurridos
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double valorActivo, porcentajeDepreciacion, tiempoTranscurrido, depreciacionTotal, valorActual;
	
	printf("Introduce el Valor Inicial del Activo : "); scanf("%lf", &valorActivo);
	printf("Introduce el Porcentaje de Depreciaci%cn Anual : ", 162); scanf("%lf", &porcentajeDepreciacion);
	printf("Introduce el Tiempo Transcurrido en A%cos : ", 164); scanf("%lf", &tiempoTranscurrido);
	
	printf("\nValor Inicial del Activo : $%.2f", valorActivo);
	printf("\nPorcentaje de Depreciaci%cn Anual : %c%.2f", 162, 37, porcentajeDepreciacion);
	printf("\nTiempo Transcurrido en A%cos : %.2f", 164, tiempoTranscurrido);
	depreciacionTotal = valorActivo * (porcentajeDepreciacion / 100) * tiempoTranscurrido;
	printf("\nDepreciaci%cn Total : $%.2f", 162, depreciacionTotal);
	valorActual = valorActivo - depreciacionTotal;
	printf("\nValor Actual del Activo : $%.2f", valorActual);

	_getche();
	return 0;
}
