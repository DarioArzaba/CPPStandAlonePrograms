#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <sstream>
#include <windows.h>
#include "MainHeader.h"
using namespace std;

Windows WindowsObj;
Mathematics MathematicsObj;
Arrays ArraysObj;

/*Basic Functions*/
void showMenu() {
	cout<<endl << endl;
	cout<<"  #########################################################################################################################"<<endl;
    cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #   88                                                                               .ad8888ba.                         #"<<endl;
	cout<<"  #   88                .d                                     .d                     d8        8b    aa          aa      #"<<endl;
	cout<<"  #   88                88                                    88                     d8'              88          88      #"<<endl;
	cout<<"  #   88  8b,dPPYba,  MM88MMM  8b,dPPYba,   ,adPPYba,       MM88MMM  ,adPPYba,       88           aaaa88aaaa  aaaa88aaaa  #"<<endl;
	cout<<"  #   88  88P      8a   88     88P     Y8  a8       8a        88    a8       8a      88               88          88      #"<<endl;
	cout<<"  #   88  88       88   88     88          8b       d8        88    8b       d8      Y8.              88          88      #"<<endl;
	cout<<"  #   88  88       88   88,    88           8a     a8         88,    8a,   ,a8        Y8a.    .a8P    88          88      #"<<endl;
	cout<<"  #   88  88       88    Y888  88             YbbdP           Y888     YbbdP             Y8888Y                           #"<<endl;
    cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #   ------------------------------------------------------------------------------------------------------------------  #"<<endl;  
	cout<<"  #                                                                                                                       #"<<endl;
	cout<<"  #   0.-  EXIT                                                                                                           #"<<endl;
	cout<<"  #   1.-  HELLO WORLD                                                                                                    #"<<endl;  
	cout<<"  #   2.-  12 DAYS OF CHRISTMAS                                                                                           #"<<endl;  
	cout<<"  #   3.-  99 BOTTLES OF BEER                                                                                             #"<<endl;
	cout<<"  #   4.-  CALCULADORA                                                                                                    #"<<endl;
	cout<<"  #   5.-  CONCATENAR STRINGS                                                                                             #"<<endl;
	cout<<"  #   6.-  TIPOS NUMERICOS                                                                                                #"<<endl;
	cout<<"  #   7.-  CLASES                                                                                                         #"<<endl;
	cout<<"  #   8.-  LOOPS                                                                                                          #"<<endl;
	cout<<"  #   9.-  CONTRASENA INTENTOS                                                                                            #"<<endl;
	cout<<"  #   10.- TABLA DE MULTIPLICAR                                                                                           #"<<endl;
	cout<<"  #   11.- ORDENAR ARRAY                                                                                                  #"<<endl;
	cout<<"  #   12.- MENU DE COCINA                                                                                                 #"<<endl;
	cout<<"  #                                                                                                                       #"<<endl;
	cout<<"  #                                                                                                                       #"<<endl;
	cout<<"  #                                                                                                                       #"<<endl;
	cout<<"  #                                                                                                                       #"<<endl;
	cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #                                     _  _                                                                              #"<<endl;  
	cout<<"  #                                    ( `   )_                                                                           #"<<endl;  
	cout<<"  #                                  (    )    `)                                                                         #"<<endl;  
	cout<<"  #                                 (_   (_ .  _) _)                                                                      #"<<endl;  
	cout<<"  #                                                                               _                                       #"<<endl;  
	cout<<"  #                                                                             (  )                                      #"<<endl;  
	cout<<"  #                                               _ .                         ( `  ) . )                                  #"<<endl;  
	cout<<"  #                                             (  _ )_                      (_, _(  ,_)_)                                #"<<endl;  
	cout<<"  #                                            (_  _(_ ,)                                                                 #"<<endl; 
	cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #                                                                                                                       #"<<endl;  
	cout<<"  #########################################################################################################################"<<endl;
}
void programHolder(void (*programa)()) {
int reinicio = 1;
do {
(*programa)();
reinicio = WindowsObj.ValidateNumber("Reiniciar el Programa? Si = 1 , No = 2");
} while (reinicio == 1);
WindowsObj.ClearScreen();
}

/*
Description:
1.- Hello World: From my very first cpp :'P.
2.- Twelve Day of Christmas: First I enumerate the days so that the switches look organized, then I use a (For) cicle to print each "static" phrase from the first switch and an "accumulative" phrase from the second switch. The second switch "cascades" the phrases and adds them up because it lacks the (break) statement.
3.- 99 Bottles: To print the 99 pharagraphs I use a (For) cicle an its increment expresion to change the strings from the song. I hard coded the last two becouse I wanted to keep loyal to the original lyrics. A lot of neat alternatives in: www.99-bottles-of-beer.net
4.- Calculator: This basic arithmetic calculator has 8 functions. First is a normal calculator, you select one of the four basic operators followed by a number in order to apply that operation to the result. Second one uses two numbers to calculate just one time the four operations. Third, Fourth, Fifth and Sixth just keep applying the same operation (Addition, Substraction, Multiplication, Divition) to the result. Seventh asks for the size of an vector, asks for the values of the vector and returns the total sum of those values. Eight asks for a cuadratic equation and returns the real roots using the general formula.
5.- Strings: Asks for user's name and surname in order to be greeted. Then asks if the user wants to create a new username and password. If the user says no, it prompts for the default username and password. If the user says yes he can overwrite the default values and then be asked for the new username and password. Either way the user only has 10 attempts before being denied access.
6.-

*/

/*Programs*/
void HelloWorld() { 
	cout << "Hello World! \n";
}             
void TwelveDaysOfChristmas() {
	enum dias { First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Ninth, Tenth, Eleventh, Twelfth };
	for (int i = 0; i < 12; i++) {
		switch (i) {
		case Twelfth: cout << "On the twelfth day of Christmas my true love sent to me " << endl; break;
		case Eleventh: cout << "On the eleventh day of Christmas my true love sent to me " << endl; break;
		case Tenth: cout << "On the tenth day of Christmas my true love sent to me " << endl; break;
		case Ninth: cout << "On the ninth day of Christmas my true love sent to me " << endl; break;
		case Eighth: cout << "On the eighth day of Christmas my true love sent to me " << endl; break;
		case Seventh: cout << "On the seventh day of Christmas my true love sent to me " << endl; break;
		case Sixth: cout << "On the sixth day of Christmas my true love sent to me " << endl; break;
		case Fifth: cout << "On the fifth day of Christmas my true love sent to me " << endl; break;
		case Fourth: cout << "On the fourth day of Christmas my true love sent to me " << endl; break;
		case Third: cout << "On the third day of Christmas my true love sent to me " << endl; break;
		case Second: cout << "On the second day of Christmas my true love sent to me " << endl; break;
		case First: cout << "On the first day of Christmas my true love sent to me " << endl; break;
		default: break;
		}
		switch (i) {
		case Twelfth: cout << "Drummers Drumming, ";
		case Eleventh: cout << "Pipers Piping, ";
		case Tenth: cout << "Lords a - Leaping, ";
		case Ninth: cout << "Ladies Dancing, ";
		case Eighth: cout << "Maids a - Milking, ";
		case Seventh: cout << "Swans a - Swimming, ";
		case Sixth: cout << "Geese a - Laying, ";
		case Fifth: cout << "Gold Rings, ";
		case Fourth: cout << "Calling Birds, ";
		case Third: cout << "Three French Hens, ";
		case Second: cout << "Two Turtle Doves, ";
		case First: cout << "A Partridge in a Pear Tree.\n";
		default: break;
		}
	}
	cout << endl << "The end" << endl;
}
void NNBottles() {
	int bottles = 99;
	while (bottles > 0) {
		if (bottles == 2) {
			cout << "2 bottles of beer on the wall, 2 bottles of beer." << endl;
			cout << "Take one down, pass it around, 1 bottle of beer on the wall.\n " << endl;
			cout << "1 bottle of beer on the wall, 1 bottle of beer." << endl;
			cout << "Take one down, pass it around, no more bottles of beer on the wall.\n " << endl;
			cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
			cout << "Go to the store and buy some more, 99 bottles of beer on the wall.";
			bottles = 0;
		} else {
			cout << bottles << " bottles of beer on the wall, ";
			cout << bottles << " bottles of beer." << endl;
			cout << "Take one down, pass it around, ";
			cout << --bottles << " bottles of beer on the wall.\n " << endl;
		}
	}
}
void Calculator() {
	int userSelection;
	cout << endl << "Bienvenido! Calculadora Todo en Uno" << endl << "----------------------------------" << endl;
	cout << "Que operacion deseas realizar?\n";
	userSelection = WindowsObj.ValidateNumber("1 = Calculadora Ans\n2 = Operaciones Aritmeticas (Dos Numeros)\n3.- Solo suma\n4 = Solo Resta\n5 = Solo Multiplicacion\n6 = Divicion\n7 = Suma de Elementos en Array\n8 = Formula General\n");
	if (userSelection == 1) {
		int userSelectOperation;
		double recursiveResult = 0;
		double userInput;
		bool RepeatOperation = true;
		cout << endl <<"Calculadora!" << endl;
		cout << "NOTA: Para ver el resultado final sume cero."<< endl;
		while(RepeatOperation) {
		userSelectOperation = WindowsObj.ValidateNumber("1 = Suma | 2 = Resta | 3 = Multiplicacion | 4 = Divicion\n");
		if (userSelectOperation == 1) {
			userInput = WindowsObj.ValidateNumberDouble("Sumar: ");
			if (userInput == 0) {
				RepeatOperation = false;
			}
			else {
				recursiveResult = MathematicsObj.Add(recursiveResult, userInput);
				cout << endl <<"R = " << recursiveResult  <<endl;
			}

		}
		else if (userSelectOperation == 2) {
			userInput = WindowsObj.ValidateNumberDouble("Restar: ");
			recursiveResult = MathematicsObj.Substract(recursiveResult, userInput);
			cout << endl <<"R = " << recursiveResult <<endl;
		}
		else if (userSelectOperation == 3) {
			userInput = WindowsObj.ValidateNumberDouble("Multiplicar por: ");
			recursiveResult = MathematicsObj.Multiply(recursiveResult, userInput);
			cout << endl <<"R = " << recursiveResult <<endl;
		}
		else if (userSelectOperation == 4) {
			userInput = WindowsObj.ValidateNumberDouble("Dividir entre: ");
			if (userInput == 0) {
				cout << "No puedes dividir entre cero!" << endl;
			}
			else {
				recursiveResult = MathematicsObj.Divide(recursiveResult, userInput);
				cout << endl <<"R = " << recursiveResult <<endl;
			}
		}
		else { cout << "\n" << "Error: " << userSelectOperation << " no es una operacion valida!" << endl; }
		}
	}
	else if (userSelection == 2) {
		cout << endl << "Calculadora Aritmetica de Dos Numeros!" << endl;
		double first_Number = WindowsObj.ValidateNumberDouble("Cual es el primer numero? ");
		double second_Number = WindowsObj.ValidateNumberDouble("Cual es el segundo numero? ");
		cout << endl << "Suma de:               " << first_Number << " + " << second_Number << " = " << MathematicsObj.Add(first_Number,second_Number) << endl;
		cout <<"Resta de:              " << first_Number << " - " << second_Number << " = " << MathematicsObj.Substract(first_Number,second_Number) << endl;
		cout <<"Multiplicacion de:     " << first_Number << " * " << second_Number << " = " << MathematicsObj.Multiply(first_Number,second_Number) << endl;
		cout <<"Divicion de:           " << first_Number << " / " << second_Number << " = " << MathematicsObj.Divide(first_Number,second_Number) << endl;
	}
	else if (userSelection == 3) {
		cout << endl <<"Suma!" << endl;
		double recursiveAddResult = 0;
		cout << "NOTA: Para ver el resultado final sume el numero cero." << endl;
		cout << endl <<"R = " << MathematicsObj.RecursiveAdd(recursiveAddResult) <<endl;
	}
	else if (userSelection == 4) {
		cout << endl <<"Resta!" << endl;
		double recursiveSubstractResult = 0;
		cout << "NOTA: Para ver el resultado final reste el numero cero." << endl;
		cout << endl <<"R = " << MathematicsObj.RecursiveSubstract(recursiveSubstractResult) <<endl;
	}
	else if (userSelection == 5) {
		cout << endl <<"Multiplicacion!" << endl;
		double recursiveMultiplyResult = 1;
		cout << "NOTA: Para ver el resultado final multiplique por uno" << endl;
		cout << endl <<"R = " << MathematicsObj.RecursiveMultiply(recursiveMultiplyResult) <<endl;
	}
	else if (userSelection == 6) {
		cout << endl <<"Divicion!" << endl;
		double recursiveDivideResult = 1;
		cout << "NOTA: Para ver el resultado final divida entre uno" << endl;
		cout << endl <<"R = " << MathematicsObj.RecursiveDivide(recursiveDivideResult) <<endl;
	}
	else if (userSelection == 7) {
		cout << endl <<"Suma Vector!" << endl;
		int taman;
		cout << " Cuantos numeros vas a sumar? ";
		cin >> taman;
		vector<double> valores(taman);
		cin.ignore();
		cout << endl << "Total = "<< MathematicsObj.VectorTotal(taman,valores)<<endl;
	}
	else if (userSelection == 8) {
		cout << endl <<"Formula Cuadratica!" << endl;
		double firstVariable, secondVariable, thirdVariable;
		firstVariable = WindowsObj.ValidateNumberDouble("Introduce el valor A de la ecuacion: ");
		secondVariable = WindowsObj.ValidateNumberDouble("Introduce el valor B de la ecuacion: ");
		thirdVariable = WindowsObj.ValidateNumberDouble("Introduce el valor C de la ecuacion: ");
		cout << endl << "R = " << MathematicsObj.QuadraticFormulaX1(firstVariable, secondVariable, thirdVariable) << endl;
		cout << endl << "R = " << MathematicsObj.QuadraticFormulaX2(firstVariable, secondVariable, thirdVariable) << endl;
	}
	else { cout << "\n" << "Error: " << userSelection << " no es una operacion valida!" << endl; }
}
void Strings() {
	string name, surname, userName = "admin", password = "password69", hint = "dummy password", userNameHold, passwordHold;
	double createNewPassword = 0;
	bool counter = true;
	int attemptCounter = 9;
	cout << "Cual es tu nombre? ";
	cin >> name; cin.ignore();
	cout << endl <<"Cual es tu apellido? ";
	cin >> surname; cin.ignore();
	string completeName = name + " " + surname;
	cout << endl << "Mucho Gusto! " << completeName << endl << endl;
	cout << completeName << " estamos iniciando el servidor..."<< endl;
	createNewPassword = WindowsObj.ValidateNumber(name + " deseas crear un nuevo Usuario y Contrasena? 1 = Si | 2 = No");
	while (counter) {
		if (createNewPassword == 1) {
			cout << endl << "Nuevo Nombre de Usuario: ";
			cin >> userName; cin.ignore();
			cout << "Nueva Contrasena para " << userName << " : ";
			cin >> password; cin.ignore();
			cout << "Frase de ayuda para contrasena de " << userName << " : ";
			cin >> hint; cin.ignore();
			cout << endl << "Usuario " << userName << " ha sido registrado!" << endl;
			cout << endl << "Inicio de Sesion (Hint: " << hint << " )";
			cout << endl << "Nota: Tienes " << (attemptCounter + 1) << " intentos antes de bloquear tu cuenta." << endl;
			for (attemptCounter; attemptCounter > (-1); attemptCounter--) {
				cout << endl << "Introduce tu nombre de usuario:  "; getline(cin, userNameHold, '\n');
				cout << "Introduce tu contrasena:  "; getline(cin, passwordHold, '\n');
				if (userNameHold != userName || passwordHold != password) {
					cout << "Usuario o Contrasena Incorrecto!" << "\n";
					if (attemptCounter > 0) {
						cout << endl << "Te quedan " << attemptCounter << " intentos." << endl;
					}
					else if (attemptCounter <= 0) {
						cout << "\nTu cuenta a sido bloqueada" << endl;
						cout << "Contacta a tu administrador. Buen dia!" << endl;
						counter = false;
					}
				}
				else
				{
					cout << endl << "Acceso Concedido! Bienvenido " << completeName << "\n";
					counter = false;
					attemptCounter = -2;
				}
			}
		}
		else {
			cin.ignore();
			cout << endl << "Inicio de Sesion (Hint: " << hint << " )\n";
			cout << endl << "Nota: Tienes " << (attemptCounter + 1) << " intentos antes de bloquear tu cuenta." << endl;
			for (attemptCounter; attemptCounter > (-1); attemptCounter--) {
					cout << endl << "Introduce tu nombre de usuario:  "; getline(cin, userNameHold, '\n');

					cout << "Introduce tu contrasena:  "; getline(cin, passwordHold, '\n');
					if (userNameHold != userName || passwordHold != password) {
						cout << "Usuario o Contrasena Incorrecto!" << "\n";
						if (attemptCounter > 0) {
							cout << endl << "Te quedan " << attemptCounter << " intentos." << endl;
						}
						else if (attemptCounter <= 0) {
							cout << "\nTu cuenta a sido bloqueada" << endl;
							cout << "Contacta a tu administrador. Buen dia!" << endl;
							counter = false;
						}
					}
					else
					{
						cout << endl << "Acceso Concedido! Bienvenido " << completeName << "\n";
						counter = false;
						attemptCounter = -2;
					}
				}
		}
	}
}
void TypeofNumbers() {
	ArraysObj.SumaTotalDescuento();
	bool boleano = true, boleano2 = false;
	cout << "Un booleano solo puede ser Verdadero o Falso: " << boleano << " " << boleano2 << "\n" << endl;
	char caracter = -12; unsigned char caracter2 = 12; signed char caracter3 = -13;
	cout << "Un caracter es de 1 byte y toma valores de (0 a 255) o (-128 a 127) que corresponden a los simbolos ANSII: " << caracter << "\nUn caracter unsigned solo puede usar el rango de 0 a 255: " << caracter2 << "\nUn caracter signed solo puede usar el rango de -128 a 127: " << caracter3 << "\n" << endl;
	int integral = 2147483647; unsigned int integral2 = 4294967295; signed int integral3 = -2147483647;
	cout << "Un integral es de 4 bytes y toma valores exactos de (-2,147,483,647 a 2,147,483,647) dos mil millones: " << integral << "\nUn integral unsigned solo es positivo y alcanza valores de (0 a 4,294,967,295) cuatro mil millones: " << integral2 << "\nUn integral signed es equivalente a un integral normal: " << integral3 << "\nUn integral al pasarse de su valor maximo pierde presicion porque se reinicia su ultimo binario. "  << "\n" << endl;
	short int corto = 32767; unsigned short int corto2 = 65535; signed short int corto3 = -32768;
	long int largo = sizeof(long);
	cout << "Existen a su vez integrales cortos y largos que modifican el tamano de la variable, los integrales cortos tienen un rango de +- \n (32767), siendo duplicado a (0 a 65535) en el caso de unsigned: " << corto << " unsigned: " << corto2 << " signed: " << corto3 << "\n" <<  endl;
	cout << "Los integrales largos dependiendo de la estructura del sistema operativo (32 - 64bits) puede tomar 4 u 8 bytes: " << largo << "\n" <<endl;
	float flotante = 3.4e+38F;
	cout << "Un flotante es un valor con +-7 digitos (3.4) de precicion pero utilizando notacion cientifica puede representar numeros de hasta la 37 potencia\n es decir de hasta 37 ceros: " << flotante << "\n" << endl;
	double decimal = 1.7e+308;
	cout << "Un valor decimal (double) de 8 bytes puede tomar +- 15 digitos (1.7) de precicion con hasta 308 ceros: " << decimal << "\nDependiendo del sistema operativo la estructura long double puede tomar 16 bytes."  <<  "\n" <<endl;

}
void ClasesyConstructores() {
	class ImprimirNombre {
	public:
		ImprimirNombre (string input) {asignarNombre(input);}
		void asignarNombre(string asignar) {nombreCompleto = asignar;}
		string obtenerNombre() {return nombreCompleto;}
	private:
		string nombreCompleto;
	};
	ImprimirNombre ObjetoAuto("Este mensaje fue creado con una clase!");
	cout << endl << ObjetoAuto.obtenerNombre() << endl;
}
void Loops() {
	int iteraciones = WindowsObj.ValidateNumber("Introduce el numero de Iteraciones: ");
	int i = (2*iteraciones), j = iteraciones, iteraciones_nested = iteraciones;
	int contador = 1, contador2 = 1, contador3 = 1, contador4 = 1;
	if (iteraciones == 0) { cout << "Usando IF se que tu numero es cero.\n"; }
	else if (iteraciones > 0) { cout << "Usando ELSE IF se que tu numero es positivo.\n"; }
	else { cout << "Usando ELSE se que tu numero es negativo.\n"; }
	bool esCero = (iteraciones == 0);
	if (esCero) { cout << "Usando BOOLS Escribiste cero iteraciones" << endl; }
	else { cout << "Usando BOOLS Escribiste menos o mas de cero iteraciones" << endl; }
	/*Contadores podrian ser Iteraciones - (Iteraciones - 1)*/
	for (iteraciones; iteraciones < i; iteraciones++) {
		cout << "Usando FOR llevamos \t" << contador << endl;
		contador++;
		iteraciones_nested = j;
		for (iteraciones_nested; iteraciones_nested < i; iteraciones_nested++) {
		cout << "Usando NESTED FOR llevamos \t" << contador2 << endl;
		contador2++;
		}
	}
	iteraciones = j;
	while (iteraciones < i) {
		iteraciones++;
		cout << "Usando While llevamos \t" << contador3 << endl;
		contador3++;
	}
	iteraciones = j;
	do {
		iteraciones++;
		cout << "Usando DO WHILE llevamos \t" << contador4<< endl;
		contador4++;
	} while (iteraciones < i);
	cout << endl << "Cuadrados con Iteraciones For Loop" << endl;
	iteraciones = j;
	for (iteraciones; iteraciones < i; iteraciones++) {
		cout << iteraciones << " al cuadrado es " << iteraciones * iteraciones << endl;
	}
}
void MultiplicationTable() {
	int array[10][10];
	for (int i = 0; i < 10; i++) { for (int j = 0; j < 10; j++) { array[i][j] = i * j; } }
	cout << endl << "Tabla de Multiplicar:" << endl;
	for (int i = 0; i < 10; i++) { for (int j = 0; j < 10; j++) { cout<<"|"<<i<<" x "<<j<<" = "; cout << array[i][j] << " | "; } cout << "\n"; }
	cin.get();
}
void OrdenarNumerosArray() {
	int index, temporal, NumeroMenor;
	double promedio= 0, dividirPromedio;
	const int tamano = 30; // Cambiame Para Cambiar el Tamaño del Array!
	int array[tamano];

	srand ((unsigned int)time(NULL));
	for (int i = 0; i < tamano; i++) { array[i] = rand() % 100; }
	cout << "Array Original "<< endl; 
	cout << "{";
		// Exeptuando el primer numero, poner una coma despues de cada elemento.
		for (int i=0; i<tamano; i++) { if (i!=0){ cout << ", "; } cout << array[i]; }
	cout << "}";
	cout << '\n';

	for (int i = 0; i < tamano; i++) {

		NumeroMenor = i;
		for (int j = (i + 1); j < tamano; j++) {
			if (array[j] < array[NumeroMenor]) {
				NumeroMenor = j;
			}
		}
		index = NumeroMenor;

		temporal = array[i];
		array[i] = array[NumeroMenor];
		array[NumeroMenor] = temporal;

	}

	cout << "Array Ordenada "<< endl;
	cout << "{";
		for (int i=0; i<tamano; i++) { if (i!=0){ cout << ", "; } cout << array[i]; }
	cout << "}";
	cout << '\n';

	cout << "\nPromedio: "<< endl;
	for (int i = 0; i < tamano; i++) {
		promedio += array[i];
	}
	dividirPromedio = (promedio / tamano);
	cout << dividirPromedio<< endl;

}
void MenuCocinaSwitch() {

enum opcionesMenu { Bebida = 1, Entrada = 2, Platillo = 3, Postre = 4 };
enum opcionesBebida { Agua = 1, Refresco = 2, Jugo = 3, Limonada = 4 };
enum opcionesEntrada { Tostada = 1, Papas = 2, Fruta = 3, Sopa = 4 };
enum opcionesPlatillo { Ensalada = 1, Verdura = 2, Carne = 3, Pizza = 4 };
enum opcionesPostre { Pastel = 1, Dulces = 2, Soufle = 3, Chocolate = 4 };
int seleccionMenu, seleccionBebida, seleccionEntrada, seleccionPlatillo, seleccionPostre;
string aceptadoBebida = "", aceptadoEntrada = "", aceptadoPlatillo = "", aceptadoPostre = "";

while (aceptadoBebida == "" || aceptadoEntrada == "" || aceptadoPlatillo == "" || aceptadoPostre == "") {
	seleccionMenu = WindowsObj.ValidateNumber("Que desea ordenar?   -   1 = Bebida   2 = Entrada   3 = Platillo  4 = Postre");
	cout << endl;
	switch (seleccionMenu) {
	case Bebida:
		seleccionBebida = WindowsObj.ValidateNumber("Que Bebida?   -   1 = Refresco   2 = Agua   3 = Leche  4 = Jugo");
		switch (seleccionBebida) {
		case Agua: cout << "Seleccionaste Agua de Bebida\n" << endl; aceptadoBebida = "Agua"; break;
		case Refresco: cout << "Seleccionaste Refresco de Bebida\n" << endl; aceptadoBebida = "Refresco"; break;
		case Jugo: cout << "Seleccionaste Jugo de Bebida\n" << endl; aceptadoBebida = "Jugo"; break;
		case Limonada: cout << "Seleccionaste Limonada de Bebida\n" << endl; aceptadoBebida = "Limonada"; break;
		default: cout << "Error: Bebida no encontrada.\n" << endl; break; }
		break;
	case Entrada:
		seleccionEntrada = WindowsObj.ValidateNumber("Que Entrada?   -   1 = Papas   2 = Tostadas   3 = Huaraches  4 = Donas");
		switch (seleccionEntrada) {
		case Tostada: cout << "Seleccionaste Tostada de Entrada\n" << endl; aceptadoEntrada = "Tostada"; break;
		case Papas: cout << "Seleccionaste Papas de Entrada\n" << endl; aceptadoEntrada = "Papas"; break;
		case Fruta: cout << "Seleccionaste Fruta de Entrada\n" << endl; aceptadoEntrada = "Fruta"; break;
		case Sopa: cout << "Seleccionaste Sopa de Entrada\n" << endl; aceptadoEntrada = "Sopa"; break;
		default: cout << "Error: Entrada no encontrada.\n" << endl; break; }
		break;
	case Platillo:
		seleccionPlatillo = WindowsObj.ValidateNumber("Que Platillo?  -   1 = Carne   2 = Verduras   3 = Pasta  4 = Agua");
		switch (seleccionPlatillo) {
		case Ensalada: cout << "Seleccionaste Ensalda de Platillo\n" << endl; aceptadoPlatillo = "Ensalada"; break;
		case Verdura: cout << "Seleccionaste Verdura de Platillo\n" << endl; aceptadoPlatillo = "Verdura"; break;
		case Carne: cout << "Seleccionaste Carne de Platillo\n" << endl; aceptadoPlatillo = "Carne"; break;
		case Pizza: cout << "Seleccionaste Pizza de Platillo\n" << endl; aceptadoPlatillo = "Pizza"; break;
		default: cout << "Error: Platillo no encontrado.\n" << endl; break; }
		break;
	case Postre:
		seleccionPostre = WindowsObj.ValidateNumber("Que Postre?  -   1 = Pastel   2 = Gelatina   3 = Dulces  4 = Chocolate");
		switch (seleccionPostre) {
		case Pastel: cout << "Seleccionaste Pastel de Postre\n" << endl; aceptadoPostre = "Pastel"; break;
		case Dulces: cout << "Seleccionaste Dulces de Postre\n" << endl; aceptadoPostre = "Dulces"; break;
		case Soufle: cout << "Seleccionaste Soufle de Postre\n" << endl; aceptadoPostre = "Soufle"; break;
		case Chocolate: cout << "Seleccionaste Chocolate de Postre\n" << endl; aceptadoPostre = "Chocolate"; break;
		default: cout << "Error: Postre no encontrada.\n" << endl; break; }
		break;
	default:
		cout << "Error: Esa no es una opcion del menu." << endl;
		break;
	}
}
cout << "De bebida: " << aceptadoBebida << endl;
cout << "De entrada: " << aceptadoEntrada << endl;
cout << "De platillo: " << aceptadoPlatillo << endl;
cout << "De postre: " << aceptadoPostre << "\n" << endl;
cout << "Gracias por su preferencia!" << endl;

}

int main() {
int programNumber;
WindowsObj.WindowSize(1200,600);
do {
	showMenu(); 
	programNumber = WindowsObj.ValidateNumber(" Selecciona un Programa:");
	WindowsObj.ClearScreen();
	switch (programNumber) {
	case 0: { cout << "Gracias por utilizar << Intro to C++ >>" << endl << endl; cin.get(); } break;
	case 1: programHolder(&HelloWorld); break;
	case 2: programHolder(&TwelveDaysOfChristmas); break;
	case 3: programHolder(&NNBottles); break;
	case 4: programHolder(&Calculator); break;
	case 5: programHolder(&Strings); break;
	case 6: programHolder(&TypeofNumbers); break;
	case 7: programHolder(&ClasesyConstructores); break;
	case 8: programHolder(&Loops); break;
	case 9: programHolder(&MultiplicationTable); break;
	case 10: programHolder(&OrdenarNumerosArray); break;
	case 11: programHolder(&MenuCocinaSwitch); break;
	default: cout << " X-Valor Invalido-X" <<endl; } 
} while (programNumber != 0);
cout <<"Presiona 'Enter' para salir!"<< endl; cin.get();
return (0);
}