#include<iostream>
#include <string>
using namespace std;

char place[6][7]; 
void tablero() {
	cout << "\n \t Juego: Conecta 4\n"; cout << "\n 1   2   3   4   5   6   7\n";
	for (int a = 0; a <= 5; a++) {
		for (int b = 0; b <= 6; b++) { cout << char(218) << char(196) << char(191) << " "; cout << '\n'; }
		for (int b = 0; b <= 6; b++) { cout << char(179) << place[a][b] << char(179) << " "; cout << '\n'; }
		for (int b = 0; b <= 6; b++) { cout << char(192) << char(196) << char(217) << " ";  cout << '\n'; }
	}
}
bool checar(int a, int b) {
	//a = fila b = columna
	// i=fila+1, vertical=1, cualjugador es el jugador del ultimo turno (15 or 254) termina cuando el
	//Check what the hell!!
	int vertical = 1, horizontal = 1, diagonal1 = 1, diagonal2 = 1, i, ii;
	char cualjugador = place[a][b];
	for (i=a+1; place[i][b] == cualjugador && i <= 5; i++, vertical++); {
		for (i=a-1; place[i][b] == cualjugador && i >= 0; i--, vertical++); { if (vertical >= 4) { return true; } }
	}
	for (ii=b-1; place[a][ii] == cualjugador && ii >= 0; ii--, horizontal++); {
		for (ii=b+1; place[a][ii] == cualjugador && ii <= 6; ii++, horizontal++);{ if (horizontal >= 4) {return true;} }
	}
	for (i=a-1, ii=b-1; place[i][ii] == cualjugador && i >= 0 && ii >= 0; diagonal1++, i--, ii--); {
		for (i=a+1, ii=b+1; place[i][ii] == cualjugador && i <= 5 && ii <= 6; diagonal1++, i++, ii++); { if (diagonal1 >= 4) { return true; } }
	}
	for (i=a-1, ii=b+1; place[i][ii] == cualjugador && i >= 0 && ii <= 6; diagonal2++, i--, ii++); {
		for (i=a+1, ii=b-1; place[i][ii] == cualjugador && i <= 5 && ii >= 0; diagonal2++, i++, ii--); { if (diagonal2 >= 4) { return true; } }
	}
	return false;
}
int jugada(int b, char jugador) {
	if (place[0][b] == ' ') {
		for (int i = 0; place[i][b] == ' '; i++) {
			if (i == 5) { place[i][b] = jugador; return i; }
			i--; place[i][b] = jugador; return i; }
	} else {return -1;}
}

int main() {
	for (int a = 0; a <= 5; a++) { for (int b = 0; b <= 6; b++) {place[a][b] = ' '; } }
	tablero();
	int guardar = 0, guardar2 = 0, piezasTotales = 0; bool ganaste = false; char jugador = 15;
	while (!ganaste) {
		if (guardar2 != -1) {
			if (jugador == 15) {cout << "\n Jugador 1, que columna? "; jugador = 254;}
			else {cout << "\n Jugador 2, que columna? "; jugador = 15;}
		}
		while (true) {
			if (piezasTotales == 42) { break; }
			cin >> guardar; cin.ignore(); guardar--;
			if (guardar <= 6 && guardar >= 0) { break; }
			else { cout << "\n Numero No Valido!" << endl; cout << "Escoja una columna del 1 al 7: "; }
			if (cin.fail()) { cin.clear(); char c; cin >> c; cin.ignore(); }
		}
		if (piezasTotales == 42) { break; }
		guardar2 = jugada(guardar, jugador);
		if (guardar2 == -1) { cout << "Columna Llena \nIntrodusca otro numero del 1 al 7: "; }
		else { ganaste = checar(guardar2, guardar); piezasTotales++; system("cls"); tablero(); }
	}
	if (piezasTotales == 42) { cout << "\nEmpate\n"; cin.get(); return 0; }
	if (jugador == 15) { cout << "\n\nGanador : jugador 2\n"; }
	else { cout << "\n\nGanador : jugador 1\n"; }
	cin.get();
	return 0;
}

/*
Conecta 4: Obten una hilera de cuatro fichas para ganar.

First loop fills logically the 6x7 char empty array "PLACE" with empty spaces.
We call "TABLERO" function so it prints the board using the "PLACE" array values to the display with nested loops.
We initialize 5 variables, 3 int(GUARDAR, GUARDAR2, PIEZASTOTALES) , 1 bool(GANASTE=falso), and 1 char(JUGADOR=15).
While the contrary to "GANASTE" is TRUE [no winner] repeat the fallowing:
	[GUARDAR2 will be (-1) just as an exeption in case the valid input of "GUARDAR" points to a full column in that case we dont want to change the players turn, just ask again for the user input]
	If "GUARDAR2" is not (-1) and "JUGADOR" is (15) then ask player 1 for the column. "JUGADOR" is now (254).
	If "GUARDAR2" is not (-1) and "JUGADOR" is no (15) meaning it is (254) then ask player 2 for the column. "JUGADOR" is now (15).
	While (true) [validate the the user input to break] repeat the fallowing:
		If "PIEZASTOTALES" is equal to 42 [Full board] then get out of the loop.
		If "PIEZZASTOTALES" is different than 42 [Not full] then asign the input into "guardar" minus one (because of the array order).
		If "GUARDAR" input is in range get out of the loop [valid input] get out of the loop.
		If "GUARDAR" input isn't in range ask again and empty the string cache.
	[Again] If "PIEZASTOTALES" is equal to 42 [Full board] we want to end the game so we break again out of the main loop.
	If the board isnt full and the input is valid then "GUARDAR2" will get the value of the function "JUGADA":
		"jugada" needs and int that will be the validated input "GUARDAR" (0-6) and a char that will be the char "JUGADOR" (15 or 254)
		If the column that "GUARDAR" points to is empty then start a for loop.
			The for loop goes throw all if it finds an empty row it asings "JUGADOR" to that place and returns the number of the row to "GUARDAR2"
		If the column that "GUARDAR" pints to is full return (-1) to "GUARDAR2" so that we dont change player turn.
	If "guardar2" was assigned (-1) then the column is full it asks again for the input to the same player..
	If "guardar2" is not (-1) then the column wasnt full, so in one of its rows it was a signed a value. We can use function "CHECAR" to update the winner state "ganar" [ending the full game loop] then update the board, and the full board piece counter.
		"checar" needs the input column "GUARDAR" and the used, asigned non (-1) row "GUARDAR2" and will return false or true to "GANADOR" if there is a formation of vertical, horizontal, digonal to the right or diagonal to the left formation. If true it effectably ends the game.
		We initialize the four positions as integers (1) and the two dummy coordinates (i and ii).
		What the hell eith its logic.
Once out of the game loop, we fallow [Again] the test for the full board for the third time and declare a draw.
If it wasnt a draw and "jugador" is (15) then the winner is the second player (254)
If it wasnt a draw and "jugador is not (15) then the winner is the fisrt player (15).

Wait for an enter to end the program and return (0 = to main).
*/