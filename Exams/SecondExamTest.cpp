/* GENERATE HISTOGRAM */

#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iostream>     //for using cout
#include <stdlib.h>
using namespace std;

int pedirValidar( int i) {

	int limMin = 3;
	int limMax = 21;
	int numUno;

   printf("\nIntroduzca numero entero %d : "  , i); scanf("%d", &numUno);
	while (numUno > limMax || numUno < limMin) {
		system("cls");
		printf("\nError. El numero se debe encontrar entre %d y %d", limMin, limMax);
		Sleep(2000);
		
		gotoxy(0,3); printf("                                                                        ");
		gotoxy(0,1); printf("                                                                     ");
		printf("\nIntroduzca numero entero %d : ", i); scanf("%d", &numUno);
	}

   return numUno;
}

void pintarLinea() {
	system("cls");
	gotoxy(1,23);
	for (int i = 0; i < 78; i++){
		printf("-");
		Sleep(50);
	}
}

void pintarAsteriscos(int arr[]) {
	gotoxy(35,22);
	int renglon = 22;
	int columna =32;
	int regreso = 0;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < arr[i]; j++){
			regreso = arr[i];
			renglon--;
			gotoxy(columna, renglon);
			printf("*");
			Sleep(50);
		}
		columna+=2;
		renglon+=regreso;
		gotoxy(columna, renglon);
	}
	
}

int main() {

	
	int first[5];
	
	first[0]= pedirValidar( 1);
	first[1]= pedirValidar(2);
	first[2]= pedirValidar(3);
	first[3]= pedirValidar(4);
	first[4]= pedirValidar(5);
	
	pintarLinea();
	
	pintarAsteriscos(first);
	
	_getche();
	return 0;

}

