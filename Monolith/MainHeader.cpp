#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <Windows.h>
#include "MainHeader.h"
using namespace std;

void Windows::WindowSize(int width, int hight) {
		HWND console = GetConsoleWindow();
		RECT rect;
		GetWindowRect(console, &rect);
		MoveWindow(console, rect.left, rect.top, width, hight, TRUE);
}
void Windows::ClearScreen() {
	cout << string( 100, '\n' ) << flush;
}
int Windows::ValidateNumber(string mensaje) {
	int numero_validado;
	cout << endl << mensaje << "   ";
	while (true) {
		if (!(cin >> numero_validado))
		{
			cout << endl << " X-Valor Invalido-X." << endl << endl;
			cin.clear();
			cin.ignore(255, '\n');
		}
		else
		{
			break;
		}
	}
	return numero_validado;
}
double Windows::ValidateNumberDouble(string mensaje) {
	double numero_validado;
	cout << endl << mensaje << "   ";
	while (true) {
		if (!(cin >> numero_validado))
		{
			cout << endl << " X-Valor Invalido-X." << endl << endl;
			cin.clear();
			cin.ignore(255, '\n');
		}
		else
		{
			break;
		}
	}
	return numero_validado;
}

double Mathematics::Add(double x, double y) { return  x + y; };
double Mathematics::Substract(double x, double y) { return x - y; };
double Mathematics::Multiply(double x, double y) { return x * y; };
double Mathematics::Divide(double x, double y) { return x / y; };
double Mathematics::RecursiveAdd(double resultado) {
	int counter = 1;
	double validate_number;
	double x = 0.0;
	while (counter == 1) {
		cout << "Sumar:  ";
		while (true) {
			if (!(cin >> validate_number))
			{
				cout << endl << " X-Valor Invalido-X." << endl << endl;
				cin.clear();
				cin.ignore(255, '\n');
			}
			else
			{
				break;
			}
		}
		cout << endl <<  resultado << " + " << validate_number << " = " << (x+validate_number) << endl;
		x = (x + validate_number);
		resultado = x;
		if (validate_number == 0) {
			counter = 0;
		}
	}
	return resultado;
}
double Mathematics::RecursiveSubstract(double resultado) {
	int counter = 1;
	double validate_number;
	double x = 0.0;
	while (counter == 1) {
		cout << "Restar:  ";
		while (true) {
			if (!(cin >> validate_number))
			{
				cout << endl << " X-Valor Invalido-X." << endl << endl;
				cin.clear();
				cin.ignore(255, '\n');
			}
			else
			{
				break;
			}
		}
		cout << endl <<  resultado << " - " << validate_number << " = " << (x-validate_number) << endl;
		x = (x - validate_number);
		resultado = x;
		if (validate_number == 0) {
			counter = 0;
		}
	}
	return resultado;
}
double Mathematics::RecursiveMultiply(double resultado) {
	int counter = 1;
	double validate_number;
	double x = 0.0;
	while (counter == 1) {
		cout << "Multiplicar por:  ";
		while (true) {
			if (!(cin >> validate_number))
			{
				cout << endl << " X-Valor Invalido-X." << endl << endl;
				cin.clear();
				cin.ignore(255, '\n');
			}
			else
			{
				break;
			}
		}
		cout << endl <<  resultado << " * " << validate_number << " = " << (x*validate_number) << endl;
		x = (x * validate_number);
		resultado = x;
		if (validate_number == 1) {
			counter = 0;
		}
	}
	return resultado;
}
double Mathematics::RecursiveDivide(double resultado) {
	int counter = 1;
	double validate_number;
	double x = 0.0;
	while (counter == 1) {
		cout << "Dividir entre:  ";
		while (true) {
			if (!(cin >> validate_number))
			{
				cout << endl << " X-Valor Invalido-X." << endl << endl;
				cin.clear();
				cin.ignore(255, '\n');
			}
			else
			{
				break;
			}
		}
		if (validate_number == 0) {
			cout << "No puedes dividir entre cero!" << endl;
		}
		else {
			cout << endl <<  resultado << " / " << validate_number << " = " << (x/validate_number) << endl;
			x = (x + validate_number);
			resultado = x;
			if (validate_number == 1) {
				counter = 0;
			}
		}

	}
	return resultado;
}
double Mathematics::VectorTotal(int taman, vector<double> valores) {
	double numero;
	for (int i = 0; i < taman; i++) {
		cout << "Introduce valor " << (i+1) << ": ";
		cin >> numero;
		valores[i] = numero;
		cin.ignore();
	}
	double suma = 0.0;
	for (int i = 0; i < taman; i++) { 
		suma = suma + valores[i]; 
	}
	return suma;
}
double Mathematics::QuadraticFormulaX1(double a, double b, double c) {
	double resultadox1;
	if (((b*b) - (4 * a*c)) < 0) {
		cout << "Las raices son imaginarias";
		return 0;
	}
	else if (((b*b) - (4 * a*c)) == 0) {
		resultadox1 = -( b / ( 2*a));
		return (resultadox1);
	}
	else {
		resultadox1 = ((-b) + (sqrt((b*b) - (4*a*c)))) / (2*a);
		return (resultadox1);
	}
}
double Mathematics::QuadraticFormulaX2(double a, double b, double c) {
	double resultadox2;
	if (((b*b) - (4 * a*c)) < 0) {
		cout << "Las raices son imaginarias";
		return 0;
		
	}
	else if (((b*b) - (4 * a*c)) == 0) {
		resultadox2 = -( b / ( 2*a));
		return resultadox2;
	}

	else {
		resultadox2 = ((-b) - (sqrt((b*b) - (4*a*c)))) / (2*a);
		return resultadox2;
	}		
}

double VolumenFigura::PrismaTriangular(double base, double profundo, double altura) {
	//Volumen = (1/2)Base * Altura * Profundidad";
	double area = (base*altura)*(1/2);
	double volumen = area * profundo;
	return (volumen);
}
double VolumenFigura::PrismaRectangular(double base, double profundo, double altura) {
	//Volumen = Base * Altura * Profundidad";
	double area = (base*altura);
	double volumen = area * profundo;
	return (volumen);
}

string Tiempo::DiferenciaHora(double hora1, double hora2, double min1, double min2) {
	double horafinal = abs(hora1 - hora2);
	double minutosfinal = abs(min1 - min2);
	
	ostringstream tiempofinal;
	tiempofinal << horafinal << ":" << minutosfinal;
	string tiempofinalstr = tiempofinal.str();

	return (tiempofinalstr);
}

void Arrays::SumaDosArrays(int A[], int B[], int C[],int tamano) {
	
	for (int i = 0; i < tamano; ++i){
	C[i] = A[i] + B[i];
	}
	cout << "{";
	for (int i = 0; i < tamano; i++) {
		if (i!=0){ cout << ","; } cout << C[i];
	}
	cout << "}";
}
void Arrays::SumaTotalDescuento() {

	double descuento;
	const int tamano = 9;
	double A[tamano];
	string defecto = "Introdusca precio de ", cliente;

	for (int i = 0; i < tamano; i++) {
		switch (i) {
		case 0: cout << defecto << "Motherboard" << endl; break;
		case 1: cout << defecto << "RAM" << endl; break;
		case 2: cout << defecto << "HD" << endl; break;
		case 3: cout << defecto << "Gabinete" << endl; break;
		case 4: cout << defecto << "DVD" << endl; break;
		case 5: cout << defecto << "Lector" << endl; break;
		case 6: cout << defecto << "Monitor" << endl; break;
		case 7: cout << defecto << "Teclado" << endl; break;
		case 8: cout << defecto << "Mouse" << endl; break;
		default: break;
		}
		cin >> A[i];
		cin.ignore();

	}
	double suma = 0.0;
	for (int i = 0; i < tamano; i++) { 
		suma = suma + A[i]; 
	}
	cout << endl << "Es cliente distinguido ? " << endl;
	cin >> cliente;
	if (cliente == "Si") {
		descuento = (85 * suma) / 100;
		cout << "El precio de su computadora es de: " << suma << endl << endl;
		cout << "Sin embargo por ser cliente distinguido, total es de: " << descuento << endl << endl;
		cout << "Al aplicar un descuento del 15%. Vuelva Pronto " << endl << endl;
	}
	else {
		cout << "El precio de su computadora es de: " << suma << endl << endl;
		cout << " Vuelva Pronto " << endl << endl;
	}

}
