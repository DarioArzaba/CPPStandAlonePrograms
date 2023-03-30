/*
Elabore un programa que despliegue el siguiente menú:

1)	Area del Triángulo
2)	Area del Círculo
3)	Area del rectángulo
4)	Area del cuadrado

Una vez que el menú es desplegado solicite la opción deseada y con base en esta opción solicite los datos correspondientes
y despliegue el área de la figura seleccionada.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int seleccion;
	double resultado, baseTriangulo, alturaTriangulo, radioCirculo, largoRectangulo, anchoRectangulo, ladoCuadrado;
	const double PI = 3.1415926535;

	printf("Calculadora de Areas");

	printf("\n\n1) Area del Tri%cngulo", 160);
	printf("\n2) Area del C%crculo", 161);
	printf("\n3) Area del Rect%cngulo", 160);
	printf("\n4) Area del Cuadrado");

	printf("\n\nElije la figura de la que quieres obtener el area :  "); scanf("%d", &seleccion);
	if (seleccion >= 1 && seleccion <= 4) {
		if (seleccion == 1) {
			printf("\nIntroduzca la Base del Triangulo :  "); scanf("%lf", &baseTriangulo);
			printf("Introduzca la Altura del Triangulo :  "); scanf("%lf", &alturaTriangulo);
			resultado = ((baseTriangulo*alturaTriangulo) / 2);
			printf("\nArea del Triangulo :  %.2f", resultado);
		} else if (seleccion == 2) {
			printf("\nIntroduzca el Radio del Circulo :  "); scanf("%lf", &radioCirculo);
			resultado = (PI* (radioCirculo * radioCirculo));
			printf("\nArea del Circulo :  %.2f", resultado);
		} else if (seleccion == 3) {
			printf("\nIntroduzca el Largo del Rectangulo :  "); scanf("%lf", &largoRectangulo);
			printf("Introduzca el Ancho del Rectangulo :  "); scanf("%lf", &anchoRectangulo);
			resultado = (largoRectangulo*anchoRectangulo);
			printf("\nArea del Rectangulo :  %.2f", resultado);
		} else if (seleccion == 4) {
			printf("\nIntroduzca un Lado del Cuadrado :  "); scanf("%lf", &ladoCuadrado);
			resultado = (ladoCuadrado*ladoCuadrado);
			printf("\nArea del Cuadrado :  %.2f", resultado);
		}
	} else {
		printf("\nError. Esa no es una opcion valida.");
	}

	_getche();
	return 0;
}
