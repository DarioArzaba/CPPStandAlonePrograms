/*
Elabore un programa que realice las siguientes actividades:
  a)	En un función que se llame inicial() debe colocar espacios en blanco en cada una de las posiciones de dos arreglos, 
  de tal forma que sus arreglos quedarían con todos sus casilleros en blanco.
  b)	Posteriormente deberá colocar una palabra que tanga entre 1 y 10 letras en uno de los dos arreglos, 
  por lo tanto tendrá un arreglo con espacios en blanco y otro con una palabra entre 1 y 10 letras, por ejemplo:
  arr1 -> todos sus espacios en blanco.
  arr2-> {p,a,n,t,e,r,a, , , } los espacios restantes quedan con espacios en blanco.
  c)	Posteriormente elabore un ciclo que capture de 1 a 10 letras, las letras se deben almacenar en el primer arreglo 
  (el que tenía los espacios en blanco). Puede ser cualquier cantidad de letras en este rango. 
  El ciclo deberá terminar cuando se hayan capturado las diez letras o bien cuando el usuario oprima ENTER. 
  Esta acción debe estar en una función que se llame “captura_letras()”. 
  En cada caso deberá validar que las letras capturadas sean letras minúsculas de la “a” a la “z”. 
  El mensaje de error debe ser desplegado por una función que se llame “error()”.
  d)	Cuando haya terminado de capturar las letras su programa deberá comparar la primera letra del arreglo 1 con 
  la primera letra del segundo arreglo, la segunda con la segunda y así hasta terminar de comparar todo el arreglo, 
  si todas las posiciones de ambos arreglos son iguales su programa deberá indicar “Password Correcto” 
  de lo contrario deberá indicar “Password Incorrecto …”
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <regex>

using namespace std;


void error(int num) {
	if (num == 1) {
		printf("Error. Se introdujeron caracteres no validos.\n");
	} else if (num == 2) {
		printf("Error. La contrase%ca debe tener menos de 10 caracteres.\n", 164);
	}
}

void iniciar(char in[], char pass[]) {
	for (int i = 0; i < 10; i++) {
		in[i] = { ' ' };
		pass[i] = { ' ' };
	}
}

void captura_letras(char in[]) {
	char temp[10];
	char test[10];
	printf("Captura Password: "); scanf("%s", test);
	bool letras = regex_match(test, regex("^[a-z]+$"));
	bool tamano = (strlen(test) < 10);
	bool correcto = false;
	while (correcto == false) {
		if (letras == true && tamano == true) {
			for (int i = 0; i < 10; i++) {
				temp[i] = test[i];
			}
			strcpy(in, temp);
			correcto = true;
		} else if (letras == false) {
			error(1);
			printf("Captura Password: "); scanf("%s", test);
			letras = regex_match(test, regex("^[a-z]+$"));
			tamano = (strlen(test) < 10);
		} else {
			error(2);
			printf("Captura Password: "); scanf("%s", test);
			letras = regex_match(test, regex("^[a-z]+$"));
			tamano = (strlen(test) < 10);
		}
	}
	
}

void comparar(char in[], char pass[]) {
	bool caracteresIguales = true;
	for (int i = 0; i < 10; i++) {
		if (in[i] != pass[i]) {
			caracteresIguales = false;
		} 
	}
	if (caracteresIguales == true) {
		printf("\nPassword Correcto");
	} else {
		printf("\nPassword Incorrecto");
	}
}

int main() {
	
	char input[10], password[10];
	iniciar(input, password);
	strcpy(password,"arzaba\0  ");
	printf("Contrase%ca:  %s\n\n",164, password);
	captura_letras(input);
	comparar(input, password);

	_getche();
	return 0;
}
