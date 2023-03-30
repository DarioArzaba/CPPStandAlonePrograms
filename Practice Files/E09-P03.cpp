/*
Una máquina que costo $ 28,000 pesos se deprecia a razón de $ 4,000 pesos anuales durante 7 años. 
Elabore un programa en “C” que calcule y despliegue una tabla con la depreciación de los 7 años.
Elabore una tabla que muestre el año, depreciacion, valor en dicho año y depreciacion acomulada.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int tiempo = 1;
	double depreciacion = 4000;
	double valor = 28000;
	double valorActual, depreciacionAcumulada;
	
	printf("\n    A%co       Depreciaci%cn     Valor a fin de A%co      Depreciac%cn Acumulada", 164,162,164,162);
	printf("\n   ------     -------------    ------------------     ------------------------");
	while (tiempo <= 7) {
		depreciacionAcumulada = tiempo*depreciacion;
		valorActual = valor - depreciacionAcumulada;
		if (tiempo == 5 || tiempo == 6) {
			printf("\n     %d         $ %.2f          $ %.2f              $ %.2f", tiempo, depreciacion, valorActual, depreciacionAcumulada);
		} else if (tiempo == 7) {
			printf("\n     %d         $ %.2f          $ %.2f                 $ %.2f", tiempo, depreciacion, valorActual, depreciacionAcumulada);
		} else {
			printf("\n     %d         $ %.2f          $ %.2f             $ %.2f", tiempo, depreciacion, valorActual, depreciacionAcumulada);
		}
		tiempo += 1;
	}

	_getche();
	return 0;
}
