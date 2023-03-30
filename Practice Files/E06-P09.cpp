/*
Una agencia de viajes elabora una tabla de posibles recorridos turísticos.
Requiere estimar el tiempo que tardarán sus clientes en trasladarse de un sitio a otro.
Conocemos la distancia de un punto a otro en kilómetros o millas, pero dependerá de la velocidad del turista el tiempo de traslado.
Recuerde que la fórmula para calcular la velocidad es velocidad = distancia / tiempo
Su programa deberá solicitar la distancia y la velocidad pero la distancia puede ser proporcionada en millas o kilómetros.
Por lo tanto su programa debe mostrar las opciones:
1)	Millas 
2)	Kilómetros
De acuerdo a la selección del usuario, hacer las transformaciones necesarias para mostrar como salida el tiempo estimado del traslado.
Recuerde que una milla es igual a 1.609 kilómetros y la velocidad siempre será dada en kilómetros por hora.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int seleccion;
	double distancia, velocidad, tiempo;
	
	printf("Introduzca las Unidades de la distancia : ");
	printf("\n1) Millas");
	printf("\n2) Kilometros");
	scanf("%d", &seleccion);
	
	if ( seleccion == 1 ) {
		printf("\nIntroduzca la distancia (mi) : "); 	scanf("%lf", &distancia);
		printf("\nIntroduzca la velocidad (km/h) : "); 	scanf("%lf", &velocidad);
		distancia *= 1.609;
		tiempo = (distancia/velocidad);
		printf("\nTiempo estimado : %.1f h", tiempo);
	} else {
		printf("\nIntroduzca la distancia (km) : "); 	scanf("%lf", &distancia);
		printf("\nIntroduzca la velocidad (km/h) : "); 	scanf("%lf", &velocidad);
		tiempo = (distancia/velocidad);
		printf("\nTiempo estimado : %.1f h", tiempo);
	}
	
	_getche();
	return 0;
}
