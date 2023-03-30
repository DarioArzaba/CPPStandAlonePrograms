/*
Se requiere registrar la información de las calificaciones (0 a 100) obtenidas en el examen de programación de un grupo de estudiantes:
  a.	Se deben capturar las calificaciones de 10 alumnos validando que se encuentren entre cero y 100.
  b.	Después de capturar las calificaciones se debe indicar la siguiente información de salida
  -	Promedio del grupo
  -	Promedio de aprobados
  -	Promedio de reprobados
  -	Cantidad y porcentaje de aprobados
  -	Cantidad y porcentaje de reprobados
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

int main() {

	vector<double> calificaciones;
	int minCal = 0;
	int maxCal = 100;
	int minCalAprobatoria = 70;
	int numAlumnos = 10;
	double input;
	for (int i = 0; i < numAlumnos; i++) {
		printf("Introduzca la calificacion (entre %d y %d) del alumno (%d) : ", minCal, maxCal, (i + 1));
		scanf("%lf", &input);
		while (input < minCal || input > maxCal) {
			printf("Error. La calificacion debe estar entre %d y %d.\n", minCal, maxCal);
			printf("Introduzca la calificacion (entre %d y %d) del alumno (%d) : ", minCal, maxCal, (i + 1));
			scanf("%lf", &input);
		}
		calificaciones.push_back(input);
	}
	double sumaTotal=0, promedioTotal, sumaA=0, sumaR=0, promedioA, promedioR;
	int cantidadA = 0, cantidadR = 0;
	for (int i = 0; i < calificaciones.size(); i++){ sumaTotal += calificaciones[i]; }
	promedioTotal = (sumaTotal) / (double)(calificaciones.size());
	for (int i = 0; i < calificaciones.size(); i++) { 
		if (calificaciones[i] < 70) {
			cantidadA++;
			sumaA += calificaciones[i];
		} else {
			cantidadR++;
			sumaR += calificaciones[i];
		}
	}
	promedioA = (sumaA) / (double)(cantidadA);
	promedioR = (sumaR) / (double)(cantidadR);
	double porcentajeA = ((cantidadA) / (double)(numAlumnos))*(100);
	double porcentajeR = ((cantidadR) / (double)(numAlumnos))*(100);
	printf("\n\n - Promedio del grupo: %.0f", round(promedioTotal));
	printf("\n - Promedio de aprobados: %.0f", round(promedioA));
	printf("\n - Promedio de reprobados: %.0f", round(promedioR));
	printf("\n - Hay %d alumnos aprobados que representan %c%.1f de la clase.", cantidadA, 37, porcentajeA);
	printf("\n - Hay %d alumnos reprobados que representan %c%.1f de la clase.", cantidadR, 37, porcentajeR);
	
	_getche();
	return 0;
}
