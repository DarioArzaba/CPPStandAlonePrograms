/*
Una empresa desea asignar cuentas de correo a todos sus empleados, para ello ha decidido seguir la siguiente filosofía:
  a)	El correo siempre será dado en minúsculas
  b)	La primera letra del correo será la primera letra del nombre del empleado reemplazando las “ñ” por “n” 
  y las vocales acentuadas por vocales sin acento.
  c)	Posteriormente se agregará el apellido paterno del empleado reemplazando las “ñ” por “n” 
  y las vocales acentuadas por vocales sin acento.
  d)	El correo NO puede tener espacios en blanco.
Por ejemplo si la persona se llama “Víctor Juárez” su cuenta de correo deberá ser “vjuarez”, 
otro ejemplo si su nombre es “Salomón Montes de Oca” su cuenta de correo deberá ser “smontesdeoca”.
Elabore un programa que lea el nombre del empleado y su apellido paterno y regrese como resultado la cuenta de correo 
correspondiente a dicho empleado.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

bool invalidChar(char c) {
	bool valid = (c >= 97 && c < 123) || (c>= 65 && c < 91) || (c>=160 && c<166) || (c==130);
	return !valid;
}

string pedirpalabra(int num) {
	string palabra;
	if (num == 1) {
		printf("\nIntroduce tu Nombre:  \n"); 
		getline(cin, palabra);  //If i input áriel, the accented (a) won't be saved into the string.
	} else if (num == 2) {
		printf("\nIntroduce tu Apellido:  \n"); getline(cin, palabra);
	} else {
		printf("\nIntroduce la palabra:  \n"); getline(cin, palabra);
	}
	palabra.erase(remove_if(palabra.begin(), palabra.end(), invalidChar), palabra.end());
	
	return palabra;
}

string validarNombre(string nom) {
	string nombre;
	unsigned char c = tolower(nom.front());
	if (c == 160) { nombre += 'a'; }
	else if (c == 130) { nombre += 'e'; }
	else if (c == 161) { nombre += 'i'; }
	else if (c == 162) { nombre += 'o'; }
	else if (c == 163) { nombre += 'u'; }
	else if ((c == 164) || (c == 165)) { nombre += 'n'; }
	else { nombre += c; }
	return nombre;
}

string validarApellido(string apellido) {
	string ape, low;
	char c, m;
	for (int i = 0; i < apellido.length(); i++) {
		m = tolower(apellido[i]);
		low += m;
	}
	for (int i = 0; i < low.length(); i++) {
		c = low[i];
		if (c == 160) { ape += 'a'; }
		else if (c == 130) { ape += 'e'; }
		else if (c == 161) { ape += 'i'; }
		else if (c == 162) { ape += 'o'; }
		else if (c == 163) { ape += 'u'; }
		else if (c == 164) { ape += 'n'; }
		else { ape += c; }
	}
	return ape;
}

int main() {

	printf("\nBienvenido.\n");
	string nombre = pedirpalabra(1);
	string apellido = pedirpalabra(2);
	string nombreCorrecto = validarNombre(nombre);
	string apellidoCorrecto = validarApellido(apellido);
	string correo = nombreCorrecto + apellidoCorrecto + "@correo.mx";
	printf("\n\nNuevo Correo:  %s\n", correo.c_str());
	_getche();
	return 0;
}
