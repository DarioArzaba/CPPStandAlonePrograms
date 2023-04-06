#include <iostream>
#include <string>
using namespace std;

char lugar[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkwin();
void board();
string jugador1;
string jugador2;


int main()
{
	// Se declaran las variables (player) (i) (choice)
	// Se define (player) como (1).
	int ganador;
	int player = 1, i, choice;
	char mark;
	cout << "Jugador 1 Introdusca su Nombre: " << endl;
	cin >> jugador1;
	cin.ignore();
	cout << "Jugador 2 Introdusca  su Nombre: " << endl;
	cin >> jugador2;
	cin.ignore();

	do
	{
        //Se limipia la consola y se crea con los nuevos valores.
		board();
		//Redefinir Player si es par o impar.
		player = (player % 2) ? 1 : 2;
		// Primero comienza con player 1 y guarda su decision numerica
		if ((player % 2) == 0) {
			ganador = 1;
			cout << jugador2 << ", escoje un numero:  ";
		}
		else {
			cout << jugador1 << ", escoje un numero:  ";
			ganador = 0;
		}
		cin >> choice;
		// Define la marca: Si player es 1 (X) de lo contrario (O)
		mark = (player == 1) ? 'X' : 'O';
		// Cambia el valor por la marca
		if (choice == 1 && lugar[1] == '1')
			lugar[1] = mark;
		else if (choice == 2 && lugar[2] == '2')
			lugar[2] = mark;
		else if (choice == 3 && lugar[3] == '3')
			lugar[3] = mark;
		else if (choice == 4 && lugar[4] == '4')
			lugar[4] = mark;
		else if (choice == 5 && lugar[5] == '5')
			lugar[5] = mark;
		else if (choice == 6 && lugar[6] == '6')
			lugar[6] = mark;
		else if (choice == 7 && lugar[7] == '7')
			lugar[7] = mark;
		else if (choice == 8 && lugar[8] == '8')
			lugar[8] = mark;
		else if (choice == 9 && lugar[9] == '9')
			lugar[9] = mark;
		else
		{
			// Si no es un numero valido imprime numero invalido y 
			// redefine a player para que siga siendo el mismo.
			cout << "Movimiento Invalido ";
			player--;
			cin.ignore();
			cin.get();
		}
		// (i) va a ser el estado del juego (-1,0,1)
		i = checkwin();
		// Se suma 1 a (player) para que le toque al siguiente
		player++;
		// Si el estado (-1) repetir el ciclo. Con el array lugar nuevo.
	} while (i == -1);

	// Si el estado es (1) Decir el Ganador.
	// Si el estado es (0) Decir empate.
	board();
	if (i == 1)
		if (ganador == 1) {
			cout << jugador2 << " ha ganado! ";
		}
		else {
			cout << jugador1 << " ha ganado! ";
		}
	else {
		cout << " Gato!";
	}
	cin.ignore();
	cin.get();
	return 0;
}

/*********************************************
Regresa el estado del juego.
Regresa 1 si hay un ganador o perdedor.
Regresa -1 si no hay ganador o perdedor. (Continua el juego)
Regresa 0 si el juego quedo en empate porque 
termino pero no hay ganador o perdedor.
**********************************************/

int checkwin()
{
	if (lugar[1] == lugar[2] && lugar[2] == lugar[3])

		return 1;
	else if (lugar[4] == lugar[5] && lugar[5] == lugar[6])

		return 1;
	else if (lugar[7] == lugar[8] && lugar[8] == lugar[9])

		return 1;
	else if (lugar[1] == lugar[4] && lugar[4] == lugar[7])

		return 1;
	else if (lugar[2] == lugar[5] && lugar[5] == lugar[8])

		return 1;
	else if (lugar[3] == lugar[6] && lugar[6] == lugar[9])

		return 1;
	else if (lugar[1] == lugar[5] && lugar[5] == lugar[9])

		return 1;
	else if (lugar[3] == lugar[5] && lugar[5] == lugar[7])

		return 1;
	else if (lugar[1] != '1' && lugar[2] != '2' && lugar[3] != '3'
		&& lugar[4] != '4' && lugar[5] != '5' && lugar[6] != '6'
		&& lugar[7] != '7' && lugar[8] != '8' && lugar[9] != '9')

		return 0;
	else
		return -1;
}

/*******************************************************************

Primero Limpia la Consola.
Despues imprime el Titulo.
Por ultimo imprime el tablero con los 9 caracteres del array (lugar),
de cada lugar correspondiente.

********************************************************************/

void board()
{

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "   " << jugador1 << " (X)" << "  -  " << " " << jugador2 << " (O)" << endl << endl << endl;

	cout << "     |     |     " << endl;
	cout << "  " << lugar[1] << "  |  " << lugar[2] << "  |  " << lugar[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << lugar[4] << "  |  " << lugar[5] << "  |  " << lugar[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << lugar[7] << "  |  " << lugar[8] << "  |  " << lugar[9] << endl;

	cout << "     |     |     " << endl << endl;
}
