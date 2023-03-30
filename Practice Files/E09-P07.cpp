/*
Elabore un algoritmo que pida tres valores flotantes y que valide que dichos valores estén entre 1 y 100. 
Si el valor es correcto deberá pedir el siguiente valor de lo contrario deberá mostrar un mensaje de error y regresar 
a pedir el mismo valor. Una vez leídos todos los valores deberá mostrar la media de dichos números.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	double numUno, numDos, numTres, promedio;
	int limMin = 1;
	int limMax = 100;
	bool valorCorrecto = false;
	printf("\nIntroduzca numeros flotantes entre %d y %d \n", limMin, limMax); 

	printf("\nIntroduzca el primer numero flotante : "); scanf("%lf", &numUno);
	while (valorCorrecto == false) {
		
		if ((numUno > limMin) && (numUno < limMax)) {

			//Si el primer numero es correcto pedir el segundo 

			printf("\nIntroduzca el segundo numero flotante : "); scanf("%lf", &numDos);
			while (valorCorrecto == false) {
				
				if (numDos > limMin && numDos < limMax) {

					//Si el segundo numero es correcto pedir el tercero

					printf("\nIntroduzca el tercer numero flotante : "); scanf("%lf", &numTres);
					while (valorCorrecto == false) {

						if (numDos > limMin && numDos < limMax) {
							
							//Si el tercer numero es correcto calcular el promedio y salir.
							promedio = (numUno + numDos + numTres) / 3;
							printf("\nPromedio : %.2f", promedio);
							valorCorrecto = true;

						} else {
							printf("\nError. El numero no esta dentro del rango, intentelo de nuevo. ");
							printf("\nIntroduzca el tercer numero flotante : "); scanf("%lf", &numTres);
						}

					}
				} else {
					printf("\nError. El numero no esta dentro del rango, intentelo de nuevo. ");
					printf("\nIntroduzca el segundo numero flotante : "); scanf("%lf", &numDos);
				}
			}

		} else {
			printf("\nError. El numero no esta dentro del rango, intentelo de nuevo. ");
			printf("\nIntroduzca el primer numero flotante : "); scanf("%lf", &numUno);
		}

	}

	_getche();
	return 0;
}
