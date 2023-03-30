/*
Usando C++ elabore un programa que tenga la función “cara”, dicha función deberá ser llamada desde la función main().
Deberá pintar una cara como la que se muestra en la figura:
 *******
*  *  *  *
*   *    *
*  ***   *
 *******
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

void cara();

int main() {
  
	cara();
	_getche();
	return 0;

}

void cara() {
	printf("**************\n");
	printf("*            *\n");
	printf("*   *    *   *\n");
	printf("*            *\n");
	printf("*      *     *\n");
	printf("*  *       * *\n");
	printf("*   *******  *\n");
	printf("*            *\n");
	printf("**************\n");
}
