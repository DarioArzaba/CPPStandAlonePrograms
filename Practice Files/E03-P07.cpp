/*
Una persona tiene un terreno rectangular que mide X mts de frente y Y mts de fondo.
Desea cercar dicho terreno colocando polines a cada 3 mts con 3 líneas de alambre de púas.
Cada polín tiene un costo de $ 55 pesos y el metro de alambre de púas cuesta $ 3 pesos. 
El usuario introducirá las medidas del terreno (frente y fondo) y su programa le deberá indicar:
-	Cuantos polines se requieren
-	Cuantos metros de alambre de púas se requieren
-	Costo de los polines
-	Costo del alambre de púas
-	Costo total
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double mtsFrente, mtsFondo;
	printf("Introduce Metros de Frente: "); scanf("%lf", &mtsFrente);
	printf("Introduce Metros de Fondo : "); scanf("%lf", &mtsFondo);
	int lineasAlambre = 3;
	double distanciaPolines = 3;
	double costoPolin = 55;
	double costoAlambre = 3;
	double perimetroTerreno = (2 * mtsFrente) + (2 * mtsFondo);
	double numPolines = perimetroTerreno / distanciaPolines;
	double costoTotalPolines = numPolines * costoPolin;
	double mtsAlambre = perimetroTerreno * lineasAlambre;
	double costoTotalAlambre = mtsAlambre * costoAlambre;
	double costoCercar = costoTotalPolines + costoTotalAlambre;
	printf("\nCantidad de Polines Requerida        : %.3f polines", numPolines);
	printf("\nCantidad de Metros Alambre Requerida : %.3f m", mtsAlambre);
	printf("\nCosto Total de Polines               : $%.3f", costoTotalPolines);
	printf("\nCosto Total de Alambre               : $%.3f", costoTotalAlambre);
	printf("\nCosto Total de Cercar el Terreno     : $%.3f", costoCercar);

	_getche();
	return 0;
}
