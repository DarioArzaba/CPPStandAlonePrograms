/*
La seguridad informática es un tema de suma importancia por lo que la construcción de una contraseña debe ser evaluada 
para verificar su nivel de seguridad. Así si una contraseña sólo tiene:
  a.	Sólo letras minúsculas su nivel de seguridad es “1”. 
  b.	Si una contraseña tiene letras minúsculas y mayúsculas su nivel de seguridad es “2”. 
  c.	Si una contraseña tiene letras minúsculas y números su nivel de seguridad es “3”. 
  d.	Si una contraseña tiene, letras minúsculas, mayúsculas y numero su nivel de seguridad es “4”.
  e.	Si una contraseña tiene letras minúsculas, mayúsculas, números y otros caracteres su nivel de seguridad es “5”.
Elabore un programa que lea una contraseña carácter por carácter sin que se vean en pantalla (coloque asteriscos). 
Debe tener entre 5 y 15 caracteres. Regrese como resultado el nivel de seguridad de dicha contraseña.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

string pedirpassword(int minChar, int maxChar) {
	string password;
	char c, last; bool terminarCaptura = false;
	printf("\nIntroduce la contrase%ca:  \n", 164);
	while (terminarCaptura == false) {
		c = _getch(); password += c;
		last = password.back();
		if (last != '\b') _putch('*');
		if (last == 13) { printf("\b "); terminarCaptura = true; }
		if ((last == '\b') && (password.length() != 1)) {
			password.pop_back();
			password.pop_back();
			printf("\b ");
			printf("\b");
		}
	}
	while ((password.length()) > (maxChar + 1) || (password.length()) < (minChar + 1)) {
		password.clear(); terminarCaptura = false;
		printf("\nError. Debe introducir entre %d y %d caracteres.\n", minChar, maxChar);
		printf("\nIntroduce la contrase%ca:  \n", 164);
		while (terminarCaptura == false) {
			c = _getch(); password += c;
			last = password.back();
			if (last != '\b') _putch('*');
			if (last == 13) { printf("\b "); terminarCaptura = true; }
			if ((last == '\b') && (password.length() != 1)) {
				password.pop_back();
				password.pop_back();
				printf("\b ");
				printf("\b");
			}
		}
	}
	return password;
}

int validarPassword(string pass) {
	bool number = false;
	bool minuscula = false;
	bool mayuscula = false;
	bool other = false;
	bool hasNumbers = false;
	bool onlyLetrasMinusculas = true;
	bool hasMinusculas = false;
	bool hasMayusculas = false;
	bool hasNumeros = false;
	bool hasOther = false;

	//Solo minusculas
	for (int i = 0; i < pass.length(); i++) {
		minuscula = islower(pass.at(i));
		if (minuscula == false) {
			onlyLetrasMinusculas = false;
			break;
		}
	}

	//Tiene minusculas
	for (int i = 0; i < pass.length(); i++) {
		minuscula = islower(pass.at(i));
		if (minuscula == true) {
			hasMinusculas = true;
			break;
		}
	}

	//Tiene mayusculas
	for (int i = 0; i < pass.length(); i++) {
		mayuscula = isupper(pass.at(i));
		if (mayuscula == true) {
			hasMayusculas = true;
			break;
		}
	}

	//Tiene numeros
	for (int i = 0; i < pass.length(); i++) {
		number = isdigit(pass.at(i));
		if (number == true) {
			hasNumbers = true;
			break;
		}
	}

	//Tiene otros
	for (int i = 0; i < pass.length(); i++) {
		other = isalnum(pass.at(i));
		if (other == false) {
			hasOther = true;
			break;
		}
	}

	if (onlyLetrasMinusculas == true) {
		return 1;
	} else if (hasMinusculas ==  true && hasMayusculas == true && hasNumbers == false && hasOther == false) {
		return 2;
	} else if (hasMinusculas == true && hasMayusculas == false && hasNumbers == true && hasOther == false) {
		return 3;
	} else if (hasMinusculas == true && hasMayusculas == true && hasNumbers == true && hasOther == false) {
		return 4;
	} else if (hasMinusculas == true && hasMayusculas == true && hasNumbers == true && hasOther == true) {
		return 5;
	} else if (hasMinusculas == false && hasMayusculas == false && hasNumbers == false && hasOther == true) {
		printf("\nError. Falto introducir una letra mayuscula, una minuscula y un numero.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == false && hasNumbers == true && hasOther == false) {
		printf("\nError. Falto introducir alguna letra minuscula.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == true && hasNumbers == false && hasOther == false) {
		printf("\nError. Falto introducir alguna letra minuscula.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == false && hasNumbers == true && hasOther == true) {
		printf("\nError. Falto introducir alguna letra mayuscula y minuscula.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == true && hasNumbers == false && hasOther == false) {
		printf("\nError. Falto introducir alguna letra minuscula.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == true && hasNumbers == false && hasOther == true) {
		printf("\nError. Falto introducir alguna letra minuscula y un numero.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == true && hasNumbers == true && hasOther == false) {
		printf("\nError. Falto introducir alguna letra minuscula.");
		return 0;
	} else if (hasMinusculas == false && hasMayusculas == true && hasNumbers == true && hasOther == true) {
		printf("\nError. Falto introducir alguna letra minuscula.");
		return 0;
	} else if (hasMinusculas == true && hasMayusculas == false && hasNumbers == false && hasOther == true) {
		printf("\nError. Falto introducir alguna letra mayuscula y un numero.");
		return 0;
	} else if (hasMinusculas == true && hasMayusculas == false && hasNumbers == true && hasOther == true) {
		printf("\nError. Falto introducir alguna letra mayuscula.");
		return 0;
	} else if (hasMinusculas == true && hasMayusculas == true && hasNumbers == false && hasOther == true) {
		printf("\nError. Falto introducir algun numero.");
		return 0;
	}
}

int main() {

	printf("\nBienvenido. Presiona ESC para salir.\n");
	int minChar = 5;
	int maxChar = 15;	
	string password = pedirpassword(minChar, maxChar);
	password.pop_back();
	printf("\n\nNivel de seguridad:  %d\n", validarPassword(password));

	_getche();
	return 0;
}
