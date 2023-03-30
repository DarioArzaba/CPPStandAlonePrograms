/*
Elabore un programa que despliegue el siguiente menú:
	1.-Dar el valor de N
	2.-Vertical
	3. Horizontal
	4.-Diagonal 1 (\)
	5.-Diagonal 2 (/)
	6.-Cruz (+)
	7.-Tache (X)
	8.-Escalera 1
	9.-Escalrea 2
	10.-Animación
	11.-Terminar
Solicitar opcion deseada y validar entre 1 y 11. Todas las acciones deben hacerse lentamente y centradas.
1: Solicitar valor N y validar entre 3 y 21, debe ser impar. Una vez validado almacenar el valor y regresar al menu.
2: Pintar lenta y centradamente una linea vertical de N asteriscos usando el valor N de la opcion 1.
3: Pintar lenta y centradamente una linea horizontal de N asteriscos usando el valor N de la opcion 1.
4: Pintar lenta y centradamente una linea diagonal (\) de N asteriscos iniciando por esquina superior izquierda.
5: Pintar lenta y centradamente una linea diagonal (/) de N asteriscos iniciando por esquina superior derecha.
6: Pintar lenta y centradamente una cruz (+), es decir una linea vertical y una horizontal. 
Ambas lineas deben imprimirse al mismo tiempo.
7: Pintar lenta y centradamente un tache (x), es decir dos lineas diagonales inversas.
Ambas lineas deben imprimirse al mismo tiempo.
8: Pintar lentamente una escalera de N escalones que este alineada a la izquierda. Agregando un asterisco por cada escalon.
9: Pintar lentamente una escalera de N escalones que este alineada a la derecha. Agregando un asterisco por cada escalon.
10: Pintar lenta y centradamente una linea horizontal (/) de N asteriscos iniciando por esquina superior derecha.
11: Terminar el programa.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

int main() {

	int rangoMin = 1;
	int rangoMax = 11;
	int valor;
	int rangoMinN = 3;
	int rangoMaxN = 21;
	bool terminar = false;
	bool valorCorrecto = false;
	int rapidezAnimacion = 125;
	int seleccion;

	while (terminar == false) {

		printf("\n--------------------------------------------------------\n");
		printf("\n1) Dar el valor de N");
		printf("\n2) Vertical");
		printf("\n3) Horizontal");
		printf("\n4) Diagonal 1 (\\)");
		printf("\n5) Diagonal 2 (/)");
		printf("\n6) Cruz (+)");
		printf("\n7) Tache (X)");
		printf("\n8) Escalera 1");
		printf("\n9) Escalera 2");
		printf("\n10) Animaci%cn", 162);
		printf("\n11) Terminar", 162);

		printf("\n\nElije una opci%cn (entre %d y %d) : ", 162, rangoMin, rangoMax); scanf("%d", &seleccion);
		
		while (seleccion > rangoMax || seleccion < rangoMin) {
			printf("\nError. Opcion no valida.");
			this_thread::sleep_for(chrono::milliseconds(2500));
			printf("\rElije otra opci%cn valida (entre %d y %d) : ", 162, rangoMin, rangoMax); scanf("%d", &seleccion);
		}

		if (seleccion >= 1 && seleccion <= 11) {

			if (seleccion == 11) {
				terminar = true;
			}

			if (seleccion == 1) {

				bool esImpar = false;
				printf("\nElije un valor numerico entero e impar (Entre %d y %d) : ", rangoMinN, rangoMaxN); scanf("%d", &valor);
				while (valor >= rangoMaxN || valor <= rangoMinN || (valor % 2 == 0)) {
					printf("\nError. No es impar o no se encuentra entre %d y %d.", rangoMinN, rangoMaxN);
					this_thread::sleep_for(chrono::milliseconds(2500));
					printf("\rElije un valor numerico entero e impar (Entre %d y %d) : ", rangoMinN, rangoMaxN); scanf("%d", &valor);
				}
				if ((valor < rangoMaxN) && (valor > rangoMinN) && (valor % 2 != 0)) { valorCorrecto = true; }

			}
		
			if ((valorCorrecto == false) && (seleccion != 1) && (seleccion != 11)) {
				printf("\nError. Primero tiene que dar un Valor de N.\n");
				this_thread::sleep_for(chrono::milliseconds(1500));
			}

			if ((seleccion == 2) && (valorCorrecto == true)) {
				
				printf("\n\n");
				for (int i = 0; i < valor; i++) {
					printf("                    *\n");
					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				_getche();

			} else if ((seleccion == 3) && (valorCorrecto == true)) {

				printf("\n\n");

				for (int i = 0; i < (20-(valor/2)); i++) {
					printf(" ");
				}
				for (int i = 0; i < valor; i++) {
					printf("*");
					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				printf("\n\n");
				_getche();

			} else if ((seleccion == 4) && (valorCorrecto == true)) {

				printf("\n\n");
				int h = 0;
				for (int i = 0; i < valor; i++) {
					for (int j = 0; j < (20 - (valor / 2)); j++) {
						printf(" ");
					}
					for (int k = 0; k < h; k++) {
						printf(" ");
					}
					h++;
					printf("*\n");
					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				_getche();

			} else if ((seleccion == 5) && (valorCorrecto == true)) {

				printf("\n\n");
				int h = valor;
				for (int i = 0; i < valor; i++) {
					for (int j = 0; j < (20 - (valor / 2)); j++) {
						printf(" ");
					}
					for (int k = 0; k < h; k++) {
						printf(" ");
					}
					h--;
					printf("*\n");
					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				_getche();

			} else if ((seleccion == 6) && (valorCorrecto == true)) {

				printf("\n\n");
				for (int i = 0; i < valor; i++) {
					if (i == ((valor / 2))) {
						for (int i = 0; i < (21 - valor); i++) {
							printf(" ");
						}
						for (int i = 0; i < valor; i++) {
							printf("* ");
							this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
						}
						printf("\n");
					} else {
						printf("                    *\n");
						this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
					}
				}
				_getche();

			} else if ((seleccion == 7) && (valorCorrecto == true)) {

				printf("\n\n");
				int h = 0;
				int m = valor;
				for (int i = 0; i < valor; i++) {
					if (i < (valor / 2)) {
						for (int j = 0; j < (20 - (valor / 2)); j++) {
							printf(" ");
						}
						for (int k = 0; k < h; k++) {
							printf(" ");
						}
						h++;
						printf("*");
						for (int k = 0; k < (m - 2); k++) {
							printf(" ");
						}
						m = m-2;
						printf("*\n");
						this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
					} else if (i == (valor / 2)) {
						for (int j = 0; j < (20 - (valor / 2)); j++) {
							printf(" ");
						}
						for (int k = 0; k < h; k++) {
							printf(" ");
						}
						printf("*\n");
					} else if (i > (valor / 2)) {
						for (int j = 0; j < (20 - (valor / 2)); j++) {
							printf(" ");
						}
						for (int k = 0; k < h-1; k++) {
							printf(" ");
						}
						h--;
						printf("*");
						for (int k = 0; k < (m); k++) {
							printf(" ");
						}
						m = m + 2;
						printf("*\n");
						this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
					}

				} 
				_getche();

			} else if ((seleccion == 8) && (valorCorrecto == true)) {

				printf("\n\n");
				int h = 0;
				for (int i = 0; i < valor; i++) {
					for (int j = 0; j < (20 - (valor / 2)); j++) {
						printf(" ");
					}
					for (int k = 0; k < h; k++) {
						printf("*");
					}
					h++;
					printf("*\n");
					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				_getche();

			} else if ((seleccion == 9) && (valorCorrecto == true)) {

				printf("\n\n");
				int h = valor;
				int m = 0;
				for (int i = 0; i < valor; i++) {
					for (int j = 0; j < (20 - (valor / 2)); j++) {
						printf(" ");
					}
					for (int k = 0; k < h; k++) {
						printf(" ");
					}
					h--;
					printf("*");
					for (int k = 0; k < m; k++) {
						printf("*");
					}
					m++;
					printf("\n");

					this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
				}
				_getche();

			} else if ((seleccion == 10) && (valorCorrecto == true)) {

				printf("\n\n");
				for (int j = 0; j < (20 - (valor / 2)); j++) {
					printf(" ");
				}
				for (int i = 0; i < valor; i++) {
					if (i == 0) {
						printf("*");
						this_thread::sleep_for(chrono::milliseconds(1000));
						printf("\b ");
						printf(" ");
					} else if (i == valor-1) {
						printf("*");
						this_thread::sleep_for(chrono::milliseconds(1000));
						printf("\b ");
						printf(" ");
					} else {
						printf("*");
						this_thread::sleep_for(chrono::milliseconds(rapidezAnimacion));
						printf("\b ");
						printf(" ");
					}
				}
				_getche();
			}
		}
	}

	return 0;

}
