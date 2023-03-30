/*
Elabore un programa que despliegue el siguiente menú
  a)	Capturar Números
  b)	Mostrar valores capturados
  c)	Media/promedio
  d)	Mayor
  e)	Menor
  f)	Mediana
  g)	Moda
  h)	Desviación Estándar
  i)	Menor a mayor
  j)	Mayor a menor
Este menú debe estar ciclado y sólo podrá terminar cuando el usuario presione la tecla de ESC (el código ASCII es 27)
Opción “a”: Debe permitir capturar un grupo NO definido de números flotantes hasta un máximo de 100 números, 
la captura deberá terminar cuando se completen 100 números o cuando el usuario capture un valor de CERO. 
Dichos valores deben ser almacenados en un arreglo.
Opción “b”: Debe mostrar la lista de los números que fueron capturados 
Opción “c”: Debe calcular y desplegar el promedio de los “n” números capturados. 
Opción “d”: Debe seleccionar y desplegar el  número mayor de los “n” números capturados. 
Opción “e”: Debe seleccionar y desplegar el  número menor de los “n” números capturados. 
Opción “f”: Debe calcular y desplegar la mediana de los “n” números capturados. OJO!! La mediana NO es el promedio.  
Opción “g”: Debe calcular y desplegar la moda de los “n” números capturados. 
Opción “h”: Debe calcular y desplegar la desviación estándar de los “n” números capturados. 
Debe usar la librería <Math.h> para obtener la raíz “sqrt()”.
Opción “i”: Debe mostrar la lista de los números ordenados de menor a mayor 
Opción “h”: Debe mostrar la lista de los números ordenados de mayor a menor
Las funciones que deben estar incluidas en su programa deben ser:
-	menu()		- media()		- mayor() -	menor()		- moda()			- mediana() -	desv_est()		- muestra_nums()	- error() 
-	lista_men_may()	- lista_may_men()
NO es forzoso usar estos nombre puede usar los que quiera pero CADA OPCION del menú debe ser una función DENTRO del mismo programa
*/

#pragma comment (lib, "User32.lib")

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <numeric> 
#include <algorithm>
#include <math.h>
#include <winuser.h>

using namespace std;

char menu() {
	char opcion = 'l';
	printf("\nElige una de las siguientes opciones: ");
	printf("\na) Capturar Numeros ");
	printf("\nb) Mostrar valores capturados");
	printf("\nc) Media o Promedio");
	printf("\nd) Mayor");
	printf("\ne) Menor");
	printf("\nf) Mediana");
	printf("\ng) Moda");
	printf("\nh) Desviacion Estandar");
	printf("\ni) Menor a mayor");
	printf("\nj) Mayor a menor");
	printf("\nOpcion: ");  opcion = getchar(); getchar();
	return opcion;
}

void error(int num) {
	if (num == 1) {
		printf("\nError. Necesita capturar el vector inicial.\n");
	} else if (num == 2) {
		printf("Error. Introduzca unicamente numeros.\n");
	}
}

void capturar(vector<double> &num) {
	double input;
	num.clear();
	for (int i = 0; i < 100; i++) {
		int correct = 0;
		printf("Introduzca el numero (%d): ", (i + 1));
		correct = scanf("%lf", &input);
		getchar();
		while (correct != 1) {
			error(2);
			printf("Introduzca el numero (%d): ", (i + 1));
			correct = scanf("%lf", &input);
			getchar();
		}
		if (input == 0) {
			break;
		}
		num.push_back(input);
	}
}

void muestra_nums(vector<double> &num) {
	printf("Valores: \n\n");
	for (int i = 0; i < num.size(); i++) {
		printf("%.1f, ", num[i]);
	}
	printf("\b\b \n");
}

void media(vector<double> &num) {
	double promedio = accumulate(num.begin(), num.end(), 0.0) / num.size();
	printf("Promedio: %.3f\n", promedio);
}

void mayor(vector<double> &num) {
	size_t may = 0;
	for (size_t pos = 1; pos < num.size(); ++pos) {
		if (num[may] < num[pos]) {
			may = pos;
		}
	}
	printf("Mayor Numero: %.2f\n", num[may]);
}

void menor(vector<double> &num) {
	size_t may = 0;
	for (size_t pos = 1; pos < num.size(); ++pos) {
		if (num[may] > num[pos]) {
			may = pos;
		}
	}
	printf("Menor Numero: %.2f\n", num[may]);
}

void mediana(vector<double> &num) {
	vector<double> test(num);
	double resultado;
	sort(test.begin(), test.end());
	
	/*Si la cantidad de datos es impar el resultado es el valor a la mitad del vector
	De lo contrario es la media de los dos numeros alrededor de la mitad del vector.*/
	
	if (test.size() % 2 == 0) {
		resultado = (test[test.size() / 2 - 1] + test[test.size() / 2]) / 2;
	} else {
		resultado = test[test.size() / 2];
	}
	printf("Mediana: %.2f\n", resultado);
}

void moda(vector<double> &num) {
	vector<double> test(num);
	sort(test.begin(), test.end());

	int counter = 1;
	int max = 0;
	double moda = test[0];

	/*Aprovechando que el vector esta ordenado:
	Si es igual al siguiente numero, agregar uno al contado de dicho numero.
	Si es el contador mas grande se actualiza el numero que se considera la moda
	Si el siguiente numero no es igual se resetea el contador.*/

	for (int i = 0; i < (test.size()-1); i++) {
		if (test[i] == test[i + 1]) {
			counter++;
			if (counter > max) {
				max = counter;
				moda = test[i];
			}
		} else {
			counter = 1;
		}
	}
	printf("Moda: %.2f\n", moda);
}

void desv_est(vector<double> &num) {
	vector<double> test(num);
	vector<double> diff(test);
	sort(test.begin(), test.end());
	double promedio = accumulate(test.begin(), test.end(), 0.0) / test.size();

	/*Transform es una funcion que aplica una operacion a todos los elementos del rango
	En este caso la resta del promedio y todos los numeros de test. Guardamos en diff.
	Luego Multiplicamos la suma de todos los numeros en diff al cuadrado.
	Finalmente obtenemos la raiz cuadrada de la suma anterior entre la cantidad de valores*/

	transform(test.begin(), test.end(), diff.begin(), [promedio](double x) {return x - promedio;});
	double sq_sum = inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	double stdev = sqrt(sq_sum / test.size());
	printf("Desviacion Estandar: %.2f\n", stdev);
}

void lista_men_may(vector<double> &num) {
	vector<double> test(num);
	sort(test.begin(), test.end());
	printf("Valores: \n\n");
	for (int i = 0; i < test.size(); i++) {
		printf("%.1f, ", test[i]);
	}
	printf("\b\b \n");
}

void lista_may_men(vector<double> &num) {
	vector<double> test(num);
	sort(test.rbegin(), test.rend());
	printf("Valores: \n\n");
	for (int i = 0; i < test.size(); i++) {
		printf("%.1f, ", test[i]);
	}
	printf("\b\b \n");
}

int main() {	

	printf("\nBienvenido. Presiona ESC para salir.");
	vector<double> numeros;
	char seleccion = 'k';
	bool vectorInicialCorrecto = false;
	bool salir = false;
	bool primera = false;
	while (salir == false) {
		if (primera == true) { _getche(); }
		primera = true;
		seleccion = menu();
		if (GetAsyncKeyState(VK_ESCAPE)) {
			system("cls");
			printf("\nPresionaste ESC. Saliendo...");
			Sleep(2000);
			salir = true;
		} else {
			printf("\n");
			if (seleccion == 'a') {
				capturar(numeros);
				vectorInicialCorrecto = true;
			} else if (seleccion == 'b') {
				if (vectorInicialCorrecto == true) { muestra_nums(numeros); } else { error(1); }
			} else if (seleccion == 'c') {
				if (vectorInicialCorrecto == true) { media(numeros); } else { error(1); }
			} else if (seleccion == 'd') {
				if (vectorInicialCorrecto == true) { mayor(numeros); } else { error(1); }
			} else if (seleccion == 'e') {
				if (vectorInicialCorrecto == true) { menor(numeros); } else { error(1); }
			} else if (seleccion == 'f') {
				if (vectorInicialCorrecto == true) { mediana(numeros); } else { error(1); }
			} else if (seleccion == 'g') {
				if (vectorInicialCorrecto == true) { moda(numeros); } else { error(1); }
			} else if (seleccion == 'h') {
				if (vectorInicialCorrecto == true) { desv_est(numeros); } else { error(1); }
			} else if (seleccion == 'i') {
				if (vectorInicialCorrecto == true) { lista_men_may(numeros); } else { error(1); }
			} else if (seleccion == 'j') {
				if (vectorInicialCorrecto == true) { lista_may_men(numeros); } else { error(1); }
			} else {
				printf("Error. Opcion no valida, debe estar entre (a) y (j).\n");
			}
		}
	}
	return 0;
}
