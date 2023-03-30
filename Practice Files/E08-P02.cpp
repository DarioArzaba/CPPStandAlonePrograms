/*
Una tienda de computadoras le ha pedido elaborar un programa en el cual los usuarios puedan seleccionar 
la configuración  de su equipo de cómputo y una vez seleccionada dicha configuración el programa les indique
el precio total del equipo.
Para que la operación del sistema sea fácil para los usuarios la empresa le ha pedido que la configuración sea a través 
del manejo de menús de la siguiente forma:
	
Seleccione la cantidad de memoria RAM:
1)	1 GigaByte
2)	2 GigaBytes
3)	4 GigaBytes
Cada Giga de RAM tiene un costo de 1,000 pesos

Seleccione la cantidad de espacio en disco duro 
1)	300 GigaBytes
2)	600 GigaBytes
3)	900 GigaBytes
Cada 100 GigaBytes tiene un costo de 1,000 pesos

Seleccione la velocidad del procesador
1)	1.5 GigaHertz 
2)	2.0 GigaHertz
3)	2.5 GigaHertz
Cada 0.5 GigaHertz tienen un costo de 1,000 pesos

La computadora Base (antes de que usuario seleccione la configuración) tiene un costo de 4,000 pesos 
por lo tanto dicha cantidad debe ser sumada a la configuración seleccionada por el usuario y así estimar 
y desplegar el precio total del equipo.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int seleccionMemoria, seleccionDiscoDuro, seleccionProcesador;
	double precioBase = 4000;
	double memoria, discoDuro, procesador, ventaComputadora;
	double precioMemoria = 1000;
	double precioDiscoDuro = 10;
	double precioProcesador = 2000;

	printf("Calcular Precio de Computadora");

	printf("\n\nSeleccione la cantidad de memoria RAM.");
	printf("\n(Cada Giga de RAM tiene un costo de $1,000 pesos.)");

	printf("\n\n1) 1 GigaByte");
	printf("\n2) 2 GigaBytes");
	printf("\n3) 4 GigaBytes");

	printf("\n\nOpcion Numero : "); scanf("%d", &seleccionMemoria);

	if (seleccionMemoria >= 1 && seleccionMemoria <= 3) {
		if (seleccionMemoria == 1) {
			memoria = 1 * precioMemoria;
		} else if (seleccionMemoria == 2) {
			memoria = 2 * precioMemoria;
		} else if (seleccionMemoria == 3) {
			memoria = 4 * precioMemoria;
		}

		printf("\n\nSeleccione la cantidad de espacio en disco duro.");
		printf("\n(Cada 100 GigaBytes tiene un costo de $1,000 pesos.)");

		printf("\n\n1) 300 GigaBytes");
		printf("\n2) 600 GigaBytes");
		printf("\n3) 900 GigaBytes");

		printf("\n\nOpcion Numero : "); scanf("%d", &seleccionDiscoDuro);

		if (seleccionDiscoDuro >= 1 && seleccionDiscoDuro <= 3) {
			if (seleccionDiscoDuro == 1) {
				discoDuro = 300 * precioDiscoDuro;
			} else if (seleccionDiscoDuro == 2) {
				discoDuro = 600 * precioDiscoDuro;
			} else if (seleccionDiscoDuro == 3) {
				discoDuro = 900 * precioDiscoDuro;
			}

			printf("\n\nSeleccione la velocidad del procesador :  ");
			printf("\n(Cada 0.5 GigaHertz tienen un costo de $1,000 pesos.)");

			printf("\n\n1) 1.5 GigaHertz");
			printf("\n2) 2.0 GigaHertz");
			printf("\n3) 2.5 GigaHertz");

			printf("\n\nOpcion Numero : "); scanf("%d", &seleccionProcesador);

			if (seleccionProcesador >= 1 && seleccionProcesador <= 3) {
				if (seleccionProcesador == 1) {
					procesador = 1.5 * precioProcesador;
				} else if (seleccionProcesador == 2) {
					procesador = 2.0 * precioProcesador;
				} else if (seleccionProcesador == 3) {
					procesador = 2.5 * precioProcesador;
				}

				ventaComputadora = precioBase + memoria + discoDuro + procesador;
				printf("\nPrecio Total de la Computadora : $%.2f", ventaComputadora);
				printf("\n\n ");

			} else {
				printf("\nError. Esa no es una opcion valida.");
			}

		} else {
			printf("\nError. Esa no es una opcion valida.");
		}

	} else {
		printf("\nError. Esa no es una opcion valida.");
	}

	_getche();
	return 0;
}
