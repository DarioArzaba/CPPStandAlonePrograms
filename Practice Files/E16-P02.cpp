/*
Elabore un programa que lea una palabra la cual será su cuenta de acceso, dicha cuenta deberá tener entre 5 y 15 caracteres (valide). 
Una vez que la palabra es dada su programa debe solicitar una contraseña, dicha contraseña NO debe verse en pantalla, 
para ello su programa deberá leer la palabra carácter por carácter e ir colocando un asterisco, 
al final debe colocar el byte de fin de cadena “\0”. La contraseña también deberá tener entre 5 y 15 caracteres (valide). 
Cuando ambos valores han sido dados su programa deberá validar que la cuenta sea igual a su matrícula (A0…) 
y la contraseña deberá ser igual a su fecha de nacimiento (DDMMAA). 
En caso de que los valores cumplan con estas condiciones su programa deberá desplegar un letrero que diga “ACCESO PERMITIDO”, 
en caso contrario deberá desplegar un mensaje de error y regresar a solicitar la cuenta y la contraseña nuevamente
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <algorithm>
using namespace std;

string pedirusuario(int minChar, int maxChar) {
	string usuario;
	printf("\nIntroduce el usuario:  \n"); getline(cin, usuario);
	while ((usuario.length()) > maxChar || (usuario.length()) < minChar) {
		printf("\nError. Debe introducir entre %d y %d caracteres.\n", minChar, maxChar);
		printf("\nIntroduce el usuario:  \n"); getline(cin, usuario);
	}
	return usuario;
}
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
bool validarUsuario(string user) {
	char first = user.front();
	bool error = false; bool num;
	if (user.length() == 9) {
		if (first == 'A') {
			if (user.at(1) == '0') {
				for (int i = 2; i < user.length(); i++) {
					num = isdigit(user.at(i));
					if (num == false) {
						printf("\nError. La matricula se compone de una letra (A) seguida unicamente por numeros.\n");
						error = true;
						break;
					}
				}
			} else {
				printf("\nError. Despues de la letra (A) necesita haber un cero.\n");
				error = true;
			}
		} else {
			printf("\nError. La matricula debe iniciar con una letra (A) mayuscula.\n");
			error = true;
		}
	} else {
		printf("\nError. La matricula debe tener exactamente nueve caracteres.\n");
		error = true;
	}
	return error;
}
bool validarPassword(string pass) {
	bool error = false; 
	if (pass.length() == 6) {
		bool areDigits = true;
		bool number, negative;
		for (int i = 0; i < pass.length(); i++) {
			number = isdigit(pass.at(i));
			negative = (pass.at(i) < 0);
			if ((number==false)|| negative == true) {
				areDigits = false;
			}
		}
		if (areDigits == true) {

			//Ver si el anno es bisiesto
			bool leapYear = false;
			int dUno = (pass.at(0)-'0'), dDos = (pass.at(1) - '0'), mUno = (pass.at(2) - '0');
			int mDos = (pass.at(3) - '0'), yUno = (pass.at(4) - '0'), yDos = (pass.at(5) - '0');
			int yearValue = (yUno*10)+yDos;
			if (yearValue > 50) { yearValue = 1900 + yearValue; } else { yearValue = 2000 + yearValue; }
			if (((yearValue % 4 == 0) && (yearValue % 100 != 0)) || (yearValue % 400 == 0)) {
				leapYear = true;
			}

			//El mes solo puede estar entre 01 y 12
			if ((mUno == 0) || (mUno == 1)) {
				if (mUno == 0) {
					if (mDos > 9 || mDos < 1) { 
						printf("\n\nError. El mes no puede ser mayor a 12.\n"); error = true; 
					}
				}
				if (mUno == 1) {
					if ((mDos != 0) && (mDos != 1) && (mDos != 2)) { 
						printf("\n\nError. El mes no puede ser mayor a 12.\n"); error = true; 
					}
				}
			} else {
				printf("\n\nError. El mes no puede ser mayor a 12.\n"); error = true;
			}

			//Los meses 01, 03, 05, 07, 08, 10, 12 tienen 31 dias.
			if (((mUno == 0) && ((mDos == 1)|| (mDos == 3) || (mDos == 5) || (mDos == 7) || (mDos == 8))) || ((mUno == 1) && ((mDos == 0) || (mDos == 2)))) {
				if ((dUno == 0) || (dUno == 1) || (dUno == 2) || (dUno == 3)) {
					if (dUno == 0) {
						if (dDos > 9 || dDos < 1) {
							printf("\n\nError. Un mes no puede tener cero dias.\n"); error = true;
						}
					}
					if ((dUno == 1) || (dUno == 2)) {
						if (dDos > 9 || dDos < 0) {
							printf("\n\nError. El mes detectado tiene un maximo de 31 dias.\n"); error = true;
						}
					}
					if (dUno == 3) {
						if ((dDos != 0) && (dDos != 1)) {
							printf("\n\nError. El mes detectado tiene un maximo de 31 dias.\n"); error = true;
						}
					}
				} else {
					printf("\n\nError. El mes detectado tiene un maximo de 31 dias.\n"); error = true;
				}
			}

			//Los meses 04, 06, 09, 11, tienen 30 dias.
			if (((mUno == 0) && ((mDos == 4) || (mDos == 6) || (mDos == 9))) || ((mUno == 1) && ((mDos == 1)))) {
				if ((dUno == 0) || (dUno == 1) || (dUno == 2) || (dUno == 3)) {
					if (dUno == 0) {
						if (dDos > 9 || dDos < 1) {
							printf("\n\nError. Un mes no puede tener cero dias.\n"); error = true;
						}
					}
					if ((dUno == 1) || (dUno == 2)) {
						if (dDos > 9 || dDos < 0) {
							printf("\n\nError. El mes detectado tiene un maximo de 30 dias.\n"); error = true;
						}
					}
					if (dUno == 3) {
						if ((dDos != 0)) {
							printf("\n\nError. El mes detectado tiene un maximo de 30 dias.\n"); error = true;
						}
					}
				} else {
					printf("\n\nError. El mes detectado tiene un maximo de 30 dias.\n"); error = true;
				}
			}

			//Si el anno es bisiesto, febrero puede tener hasta 29 dias.
			if (((mUno == 0) && (mDos == 2)) && (leapYear == true)) {
				if ((dUno == 0) || (dUno == 1) || (dUno == 2)) {
					if (dUno == 0) {
						if (dDos > 9 || dDos < 1) {
							printf("\n\nError. Un mes no puede tener cero dias.\n"); error = true;
						}
					}
					if ((dUno == 1) || (dUno == 2)) {
						if (dDos > 9 || dDos < 0) {
							printf("\n\nError. El mes detectado tiene un maximo de 29 dias.\n"); error = true;
						}
					}
				} else {
					printf("\n\nError. Febrero no puede tener mas de 29 dias.\n"); error = true;
				}
			}

			//Si el anno no es bisiesto, puede tener hasta 28 dias.
			if (((mUno == 0) && (mDos == 2)) && (leapYear == false)) {
				if ((dUno == 0) || (dUno == 1) || (dUno == 2)) {
					if (dUno == 0) {
						if (dDos > 9 || dDos < 1) {
							printf("\n\nError. Un mes no puede tener cero dias.\n"); error = true;
						}
					}
					if (dUno == 1) {
						if (dDos > 9 || dDos < 0) {
							printf("\n\nError. El mes detectado tiene un maximo de 28 dias.\n"); error = true;
						}
					}
					if (dUno == 2) {
						if (dDos > 8 || dDos < 0) {
							printf("\n\nError. El mes detectado tiene un maximo de 28 dias.\n"); error = true;
						}
					}
				} else {
					printf("\n\nError. Febrero no puede tener mas de 28 dias.\n"); error = true;
				}
			}
		} else {
			printf("\n\nError. El password debe contener unicamente numeros (DD-MM-YY).\n"); error = true;
		}
	} else {
		printf("\n\nError. El password debe tener exactamente seis caracteres (DD-MM-YY).\n"); error = true;
	}
	return error;
}

int main() {

	int minChar = 5;
	int maxChar = 15;
	bool repetirLogin = true;
	bool repetirUsuario, repetirPassword;
	while (repetirLogin == true) {
		repetirUsuario = true;
		repetirPassword = true;
		string usuario = pedirusuario(minChar, maxChar);
		repetirUsuario = validarUsuario(usuario);
		if (repetirUsuario == false) {
			string password = pedirpassword(minChar, maxChar);
			password.pop_back();
			repetirPassword = validarPassword(password);
		}
		if (repetirUsuario == false && repetirPassword == false) {
			repetirLogin = false;
		}
	}
	printf("\n\nACCESO PERMITIDO\n");
	
	_getche();
	return 0;
}
