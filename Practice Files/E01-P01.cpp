/*
Elabore un programa que muestre su matrícula y en el siguiente renglón su nombre, su salida debe verse como sigue:
Matrícula: 1367756
Nombre:	   Jose Pérez
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {

	int x = 1367756;
	printf("Matricula : %d\n", x);
	printf("Nombre:     Juan P%crez", 130);
	
	_getche();
	return 0;
}
