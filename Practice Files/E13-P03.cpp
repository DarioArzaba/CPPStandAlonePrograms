/*
Usando C++ elabore un programa que lea una lista de diez números enteros entre 1 y 1000 (valide)  y
los almacene en un arreglo de diez posiciones. Una vez almacenados los valores su programa debe:
  a.	Mostrar el arreglo en el orden en que fue capturado
  b.	Ordenar el arreglo de menor a mayor y mostrarlo en forma de lista. 
  c.	Ordenar el arreglo de mayor a menor y mostrarlo en forma de lista
Todo el conjunto debe verse como una tabla:
Captura			Menor a Mayor		Mayor a Menor
12				1			12
3				3			5
5				4			4
1				5			3
4				12			1
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void captura(int arreglo[], int limMin, int limMax) {
	int num;
	for (int i = 0; i < 10; i++) {
		printf("Introduzca un numero entero (%d) (entre %d y %d): ", (i + 1), limMin, limMax);
		scanf("%d", &num);
		while (num > limMax || num < limMin) {
			printf("Error. Numero fuera de rango.");
			Sleep(2000);
			printf("\rIntroduzca un numero entero (%d) (entre %d y %d): ", (i + 1), limMin, limMax);
			scanf("%d", &num);
		}
		arreglo[i] = num;
	}
}
void menor(int arreglo[], int menor[]) {
	int num;
	for (int i = 0; i < 10; i++) {
		menor[i] = arreglo[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; ++j) {
			if (menor[i] > menor[j]) {
				num = menor[i];
				menor[i] = menor[j];
				menor[j] = num;
			}
		}
	}
}
void mayor(int arreglo[], int mayor[]) {
	int num;
	for (int i = 0; i < 10; i++) {
		mayor[i] = arreglo[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; ++j) {
			if (mayor[i] < mayor[j]) {
				num = mayor[i];
				mayor[i] = mayor[j];
				mayor[j] = num;
			}
		}
	}
}
void tabla(int arreglo[], int menor[], int mayor[]) {
	printf("\n Captura       Menor a Mayor      Mayor a Menor\n");
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] < 10) {
			if (menor[i] < 10) {
				printf("   %d                 %d               %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 10 && menor[i] <= 99) {
				printf("   %d                 %d              %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 100 && menor[i] <= 999) {
				printf("   %d                 %d             %d\n", arreglo[i], menor[i], mayor[i]);
			} else {
				printf("   %d                 %d            %d\n", arreglo[i], menor[i], mayor[i]);
			}
		} else if (arreglo[i] >= 10 && arreglo[i] <= 99) {
			if (menor[i] < 10) {
				printf("   %d                %d               %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 10 && menor[i] <= 99) {
				printf("   %d                %d              %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 100 && menor[i] <= 999) {
				printf("   %d                %d             %d\n", arreglo[i], menor[i], mayor[i]);
			} else {
				printf("   %d                %d            %d\n", arreglo[i], menor[i], mayor[i]);
			}
		} else if (arreglo[i] >= 100 && arreglo[i] <= 999) {
			if (menor[i] < 10) {
				printf("   %d               %d               %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 10 && menor[i] <= 99) {
				printf("   %d               %d              %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 100 && menor[i] <= 999) {
				printf("   %d               %d             %d\n", arreglo[i], menor[i], mayor[i]);
			} else {
				printf("   %d               %d            %d\n", arreglo[i], menor[i], mayor[i]);
			}
		} else {
			if (menor[i] < 10) {
				printf("   %d              %d               %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 10 && menor[i] <= 99) {
				printf("   %d              %d              %d\n", arreglo[i], menor[i], mayor[i]);
			} else if (menor[i] >= 100 && menor[i] <= 999) {
				printf("   %d              %d             %d\n", arreglo[i], menor[i], mayor[i]);
			} else {
				printf("   %d              %d            %d\n", arreglo[i], menor[i], mayor[i]);
			}
		}
	}
}

int main() {
	int arreglo[10], arregloMenor[10], arregloMayor[10];
	printf("\n");
	captura(arreglo, 1, 1000);
	menor(arreglo, arregloMenor);
	mayor(arreglo, arregloMayor);
	tabla(arreglo, arregloMenor, arregloMayor);
	_getche();
	return 0;
}
