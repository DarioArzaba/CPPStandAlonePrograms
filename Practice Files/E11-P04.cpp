/*
Usando C++ elabore un programa que tenga la función “carro”, dicha función deberá ser llamada desde la función main()
Deberá pintar un carrito como el que se muestra en la figura:
     ***
     ***
 ***********
 ***********
 ***********
  **     **
  **     **
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

void carro();

int main() {

	carro();
	_getche();
	return 0;

}

void carro() {
	printf("            *********            \n");
	printf("           ********  *           \n");
	printf("          *********   *          \n");
	printf("    **************************   \n");
	printf("    **************************   \n");
	printf("    **************************   \n");
	printf("      *****           *****      \n");
	printf("      *****           *****      \n");
}
