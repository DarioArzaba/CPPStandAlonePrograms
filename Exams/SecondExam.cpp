#pragma comment (lib, "User32.lib")

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;

const int MAX = 500;
char nombre[MAX], apellido[MAX], imprimirCorreo[27];
int x, y, ultima;


void captura() {
	x = 0;
	
	while ((x<1) || (x>25)) {
		
		printf("Introduzca su nombre:   "); 
		
		gets_s(nombre);
		
		x = strlen(nombre);
		
		if ((x<1) || (x>25)) {
			printf("ERROR, el nombre debe de tener entre 1 y 25 caracteres\n");
		}
	}

	x = 0;
	while ((x<1) || (x>25)) {

		printf("Introduzca su apellido:   "); 
		
		gets_s(apellido);
		
		x = strlen(apellido);
		
		if ((x<1) || (x>25)) {
			printf("ERROR, el apellido debe de tener entre 1 y 25 caracteres\n");
		}

	}

}

void transf() {
	
	strlwr(nombre); 
	strlwr(apellido);

	for (int i = 0; i < 26; i++) {
		if ((nombre[i] == char(160)) || (nombre[i] == char(181))) nombre[i] = 'a';
		if ((nombre[i] == char(130)) || (nombre[i] == char(144))) nombre[i] = 'e';
		if ((nombre[i] == char(161)) || (nombre[i] == char(214))) nombre[i] = 'i';
		if ((nombre[i] == char(162)) || (nombre[i] == char(224))) nombre[i] = 'o';
		if ((nombre[i] == char(163)) || (nombre[i] == char(233))) nombre[i] = 'u';
		if ((nombre[i] == char(164)) || (nombre[i] == char(165))) nombre[i] = 'n';
		if ((nombre[i] == char(32))) nombre[i] = '_';
	}

	for (int i = 0; i < 26; i++) {
		if ((apellido[i] == char(160)) || (apellido[i] == char(181))) apellido[i] = 'a';
		if ((apellido[i] == char(130)) || (apellido[i] == char(144))) apellido[i] = 'e';
		if ((apellido[i] == char(161)) || (apellido[i] == char(214))) apellido[i] = 'i';
		if ((apellido[i] == char(162)) || (apellido[i] == char(224))) apellido[i] = 'o';
		if ((apellido[i] == char(163)) || (apellido[i] == char(233))) apellido[i] = 'u';
		if ((apellido[i] == char(164)) || (apellido[i] == char(165))) apellido[i] = 'n';
	}

	ultima = apellido[strlen(apellido) - 1];
}

int main() {

	printf("Segundo Parcial\n\n");

	captura();

	transf();
	
	printf("\nSu correo es: ");

	printf("%c%s@correo.com", apellido[0], nombre);
	
	getche();

}
