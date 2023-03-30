/*
Elabore un programa que despliegue el siguiente menú:

1)	Área del triángulo
2)	Área del Círculo
3)	Área del Cuadrado
4)	Área del Rectángulo
5)	Terminar

Después de desplegar el menú su programa deberá solicitar la opción deseada VALIDAR QUE LA OPCION ESTE DENTRO DEL RANGO DE OPCIONES
Y de acuerdo a la figura seleccionada deberá solicitar los datos necesarios y mostrar el área de la figura. 
Después de mostrar el resultado debe hacer una pausa y regresar nuevamente a desplegar el menú.
Las acciones de desplegar el menú, solicitar la opción, solicitar los datos necesarios, mostrar el área y hacer la pausa
Se deberán repetir hasta que el usuario seleccione la opción “5” que indica “terminar”, 
En este momento su programa deberá finalizar.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

int main() {

	bool terminar = false;
	int seleccion;
	double resultado, baseTriangulo, alturaTriangulo, radioCirculo, largoRectangulo, anchoRectangulo, ladoCuadrado;
	const double PI = 3.1415926535;

	printf("\nCalculadora de Areas\n");

	while (terminar == false) {

		printf("\n--------------------------------------------------------\n");
		printf("\n1) Area del Tri%cngulo", 160);
		printf("\n2) Area del C%crculo", 161);
		printf("\n3) Area del Rect%cngulo", 160);
		printf("\n4) Area del Cuadrado");
		printf("\n5) Terminar");

		printf("\n\nElije la figura de la que quieres obtener el area :  "); scanf("%d", &seleccion);
		if (seleccion >= 1 && seleccion <= 5) {
			if (seleccion == 1) {
				printf("\nIntroduzca la Base del Triangulo :  "); scanf("%lf", &baseTriangulo);
				printf("Introduzca la Altura del Triangulo :  "); scanf("%lf", &alturaTriangulo);
				resultado = ((baseTriangulo*alturaTriangulo) / 2);
				printf("\nArea del Triangulo :  %.2f\n", resultado);
			} else if (seleccion == 2) {
				printf("\nIntroduzca el Radio del Circulo :  "); scanf("%lf", &radioCirculo);
				resultado = (PI* (radioCirculo * radioCirculo));
				printf("\nArea del Circulo :  %.2f\n", resultado);
			} else if (seleccion == 3) {
				printf("\nIntroduzca el Largo del Rectangulo :  "); scanf("%lf", &largoRectangulo);
				printf("Introduzca el Ancho del Rectangulo :  "); scanf("%lf", &anchoRectangulo);
				resultado = (largoRectangulo*anchoRectangulo);
				printf("\nArea del Rectangulo :  %.2f\n", resultado);
			} else if (seleccion == 4) {
				printf("\nIntroduzca un Lado del Cuadrado :  "); scanf("%lf", &ladoCuadrado);
				resultado = (ladoCuadrado*ladoCuadrado);
				printf("\nArea del Cuadrado :  %.2f\n", resultado);
			} else if (seleccion == 5) {
				terminar = true;
				printf("\n\nPrograma Terminado. Hasta luego!\n\n");
			}
		} else {
			printf("\nError. Esa no es una opcion valida.");
		}

		//Note el uso de las librerias Chrono y Thread para hacer portable la pausa!
		//Si se trabaja en Windows se puede utilizar en su lugar : Sleep(2500);
		this_thread::sleep_for(chrono::milliseconds(2500));
	}
	
	return 0;
}
