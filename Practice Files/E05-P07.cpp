/*
Un árbol que recibe el agua y nutrientes adecuados crece a razón de 2 centímetros por mes.
Si recibe el agua adecuada pero no los nutrientes sólo crece 1.5 centímetros por mes.
Si recibe los nutrientes pero no el agua sólo crece 1 centímetro por mes y
Si no recibe ni el agua ni los nutrientes sólo crece 0.5 centímetros por mes. 
Bajo las condiciones establecidas, escriba las preguntas que me permitan saber cuanto crecerá el árbol a lo largo de un año.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int agua, nutrientes;
	int meses = 12;
	double aguaYNutrientes = 2;
	double soloAgua = 1.5;
	double soloNutrientes = 1;
	double ningunAguaYNutrientes = 0.5;
	double crecimiento;

	printf("El arbol recibio el agua adecuada? (1 = Si , 2 = No)   "); scanf("%d", &agua);
	printf("El arbol recibio los nutrientes adecuados? (1 = Si , 2 = No)   "); scanf("%d", &nutrientes);

	if (agua == 1 && nutrientes == 1) {
		crecimiento = aguaYNutrientes * meses;
		printf("\nEl arbol crecio %.2f cm este a%co.", crecimiento, 164);
	} else if (agua == 1 && nutrientes != 1) {
		crecimiento = soloAgua * meses;
		printf("\nEl arbol crecio %.2f cm este a%co.", crecimiento, 164);
	} else if (agua != 1 && nutrientes == 1) {
		crecimiento = soloNutrientes * meses;
		printf("\nEl arbol crecio %.2f cm este a%co.", crecimiento, 164);
	} else {
		crecimiento = ningunAguaYNutrientes * meses;
		printf("\nEl arbol crecio %.2f cm este a%co.", crecimiento, 164);
	}

	_getche();
	return 0;
}
