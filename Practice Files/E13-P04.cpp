/*
Lea una lista de cinco letras, para cada letra debe validar que se trate de una letra minúscula de la “a” a la “z”,
de lo contrario debe mandar un mensaje de error y regresar a leer la misma letra. 
La lectura de las letras se debe hacer en una función que se llame lee_letras() y 
el mensaje de error debe estar en una función que se llame error(). 
Una vez que se han leído las cinco letras correctamente muestre la lista en orden alfabético.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

void error(int num) {
	if (num == 1) {
		printf("Error. Caracter fuera de rango.");
	}
}

void lee_letras(char arreglo[], char limMin, char limMax) {
	char caracter;
	for (int i = 0; i < 5; i++) {
		//Entre 97 to 122 ASCII
		printf("Introduzca un caracter en minusculas (%d) (entre %c y %c): ", (i + 1), limMin, limMax);
		caracter = getchar(); getchar();
		while (caracter > limMax || caracter < limMin) {
			error(1);
			Sleep(2000);
			printf("\nIntroduzca un caracter en minusculas (%d) (entre %c y %c): ", (i + 1), limMin, limMax);
			caracter = getchar(); getchar();
		}
		arreglo[i] = caracter;
	}
}

void ordenar(char arreglo[]) {
	/*
	Cada iteracion debe al final recorrer la letra mas grande hasta el final
		Por lo que podemos realizar la siguiente pregunta un caracter menos (5-j) por cada iteracion.
			Pregunta: Si letra (k) es mayor que la siguiente(k+1), en dicho caso intercambiarlas.
				Guardar el caracter mayor (k) en TEMP.
				Hacer que el caracter menor tome el lugar del mayor.
				Hacer que el caracter mayor tome el lugar del menor.
	*/
	char temp;
	for (int j = 1; j < 5; j++) {
		for (int k = 0; k < 5 - j; k++) {
			if (arreglo[k] >= arreglo[k + 1]) {
				temp = arreglo[k];
				arreglo[k] = arreglo[k + 1];
				arreglo[k + 1] = temp;
			}
		}
	}
}

void imprimir(char ordenado[], int num) {
	if (num == 1) {
		printf("\nCaracteres Sin Ordenar:  ");
		for (int i = 0; i < 5; i++) {
			char letra = ordenado[i];
			printf("%c, ", letra);
		}
		printf("\b\b \n");
	} else if (num == 2) {
		printf("\nCaracteres Ordenados:  ");
		for (int i = 0; i < 5; i++) {
			char letra = ordenado[i];
			printf("%c, ", letra);
		}
		printf("\b\b \n");
	} else {
		error(1);
	}

}

int main() {
	
	char arreglo[5] = {0};
	lee_letras(arreglo, 'a', 'z');
	imprimir(arreglo, 1);
	ordenar(arreglo);
	imprimir(arreglo, 2);

	_getche();
	return 0;
}
