/*
La empresa de concretos premezclados "Angustia SA" maneja dos tipos de resistencia:
	1) Resistencia 200 a 1200 pesos.
	2) Resistencia 250 a 1450 pesos.
La empresa quiere un sistema que muestre sus ventas del dia.
	a) Solicitar candidad de metros cubicos a consumir.
	b) Solicitar el tipo de resistencia de la cantidad. (Validar)
	c) Con estos datos contabilizar clientes, consumo en metros cubicos y en pesos de cada tipo de resistencia.
	d) Preguntar si se desea capturar un nuevo consumo.
	e) Repetir los pasos anteriores hasta que el usuario responda que ya no desea capturar un nuevo consumo.
	f) Mostrar con los datos finales la tabla de consumo del tia.
La tabla debe mostrar el tipo de resistencia, así como los clientes y consumo.
El programa debe utilizar una funcion de captura, muestra y error.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;


void error(int error) {
	if (error == 1) {
		printf("Error. Tipo de Resistencia no valida. ");
	} else if (error == 2) {
		printf("Error. El numero es negativo o cero ");
	} else if (error == 3) {
		printf("Error. Tiene que escribir la letra y o n. ");
	}
}
void captura(int *clientesUno, int *clientesDos, int *consumoMetrosUno, int *consumoMetrosDos) {

	char terminar = 'a';
	int metros, consumo;
	int min = 1;
	int max = 2;
	bool terminarPreguntar = false;

	while (terminarPreguntar == false) {
		printf("\nIntroduzca la cantidad de metros cubicos de concreto a consumir: "); scanf("%d", &metros);
		while (metros < 1) {
			error(2);
			Sleep(2000);
			printf("\rIntroduzca la cantidad de metros cubicos de concreto a consumir: "); scanf("%d", &metros);
		}

		printf("Introduzca el tipo de resistencia %d o %d : ", min, max); scanf("%d", &consumo);
		while (consumo > max || consumo < min) {
			error(1);
			Sleep(2000);
			printf("\rIntroduzca el tipo de resistencia %d o %d : ", min, max); scanf("%d", &consumo);
		}

		printf("\nDesea capturar un nuevo consumo de concreto (y/n)? "); getchar();  terminar = getchar();
		while (terminar != 'y' && terminar != 'n') {
			error(3);
			Sleep(2000);
			printf("\rDesea capturar un nuevo consumo de concreto (y/n)? "); getchar(); terminar = getchar();
		}

		if (terminar == 'n') {
			terminarPreguntar = true;
		}

		if (consumo == 1) {
			*clientesUno += 1;
			*consumoMetrosUno += metros;

		} else if (consumo == 2) {
			*clientesDos += 1;
			*consumoMetrosDos += metros;
		}

	}
}
void muestra(int clientesUno, int clientesDos, int consumoMetrosUno, int consumoMetrosDos) {
	int precioTipoUno = 1200;
	int precioTipoDos = 1450;
	int consumoPesosUno = precioTipoUno * consumoMetrosUno;
	int consumoPesosDos = precioTipoDos * consumoMetrosDos;
	int totalVentas = consumoPesosUno + consumoPesosDos;
	printf("\n\nTIPO    RESISTENCIA    CLIENTES    CONSUMO EN M3    CONSUMO EN $$$\n");
	printf("--------------------------------------------------------------------\n");
	printf(" 1         200              %d            %d                %d\n", clientesUno, consumoMetrosUno, consumoPesosUno);
	printf(" 1         250              %d            %d                %d\n", clientesDos, consumoMetrosDos, consumoPesosDos);
	printf("--------------------------------------------------------------------\n");
	printf("TOTAL DE LAS VENTAS DEL DIA                               %d\n", totalVentas);
	printf("--------------------------------------------------------------------\n");
}

int main() {
	printf("Angustia SA\n");
	int clientesUno = 0, clientesDos = 0, consumoMetrosUno = 0, consumoMetrosDos = 0;
	captura(&clientesUno, &clientesDos, &consumoMetrosUno, &consumoMetrosDos);
	muestra(clientesUno, clientesDos, consumoMetrosUno, consumoMetrosDos);
	_getche();
	return 0;
}

