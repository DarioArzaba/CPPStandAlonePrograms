/*
Una empresa manufacturera de juguetes que cuenta con varias sucursales, desea determinar el mejor punto de ubicación 
para sus distribuidoras, para lograr tal efecto su programa debe solicitar los datos de las tiendas que se encuentran en una zona,
el número de tiendas por zona es variable desde dos tiendas hasta quince como máximo, los datos que se proporcionarán por cada tienda son: 
  a.	Nombre, la cual se identifica con una letra del abecedario
  b.	Coordenada en X valor flotante entre 1 y 300 (valide)
  c.	Coordenada en Y valor flotante entre 1 y 300 (valide)
  d.	Demanda de productos valor entero entre 1 y 1000 (valide)
Use un arreglo por cada dato.
Para indicar que se ha terminado la captura de tiendas el usuario usará una “x” para indicar que ha terminado de capturar.
Al final quedará algo como lo siguiente en cuatro arreglos diferentes:
Tienda	Coord X	Coord X	Demanda
A	97.5	30.1	150
B	82.3	28.7	120
C	88.4	31.2	100
D	93.4	25.4	150
E	90.2	28.3	180
F	91.7	30.4	190
G	88.9	28.7	170
Posteriormente se deben ordenar TODOS los datos de menor a mayor con respecto a la coordenada en X, 
es decir, la tabla quedará de la siguiente forma:
Tienda	Coord X	Coord X	Demanda
B	82.3	28.7	120
C	88.4	31.2	100
G	88.9	28.7	170
E	90.2	28.3	180
F	91.7	30.4	190
D	93.4	25.4	150
A	97.5	30.1	150
Una vez que se ha ordenado la tabla su programa debe obtener el total de la demanda, es decir, la suma de todas las demandas, 
en este caso: 1060, posteriormente obtendrá lo que se conoce como semisuma, el total de la demanda entre 2, en este caso: 530.
De acuerdo al orden su programa deberá obtener el acumulado de las demandas, es decir para la tienda B el acumulado es 120,
para la tienda C el acumulado es (120+100) 220, para la tienda G el acumulado es (120+100+170) 390, 
para la tienda E el acumulado es (120+100+170+180) 570; en este momento el acumulado ya es mayor que la semisuma (530), 
por la tanto la X óptima es la del renglón anterior, en este caso la tienda G por XO=88.9.
Posteriormente deberá hacer lo mismo para obtener la Y óptima.
Su programa debe dar como salida:
-	La tabla como se capturó en origen
-	La tabla ordenada con respecto a X y la XO
-	La tabla ordenada con respecto a Y y la YO
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename A, typename B>
void zip(const vector<A> &a, const vector<B> &b, vector<pair<A, B>> &zipped) {
	for (size_t i = 0; i < a.size(); ++i) {
		zipped.push_back(make_pair(a[i], b[i]));
	}
}

template <typename A, typename B>
void unzip(const vector<pair<A, B>> &zipped, vector<A> &a, vector<B> &b) {
	for (size_t i = 0; i < a.size(); i++) {
		a[i] = zipped[i].first;
		b[i] = zipped[i].second;
	}
}

void error(int num) {
	if (num == 1) {
		printf("\nError. Debe de haber por lo menos dos tiendas en el area.\n");
	} else if (num == 2) {
		printf("\nError. La coordenada debe ser un numero entero y estar entre (1 - 300)\n\n");
	} else if (num == 3) {
		printf("\nError. El nombre debe ser una letra entre (a-z)\n\n");
	} else if (num == 4) {
		printf("\nError. La demanda debe ser un numero entero y estar entre (1 - 1000)\n\n");
	} else if (num == 5) {
		printf("\nError. Otra tienda ya tiene ese nombre. Intentalo de nuevo.\n\n");
	}
}

void capturar(vector<char> &nombre, vector<int> &x, vector<int> &y, vector<int> &demanda) {
	vector<char> usadas;
	char letraNombre = 'z';
	int coordenadaX, coordenadaY, cantidadDemanda;
	int minimoTiendas = 1;
	int maximoTiendas = 15;
	nombre.clear();
	x.clear();
	y.clear();
	demanda.clear();
	int numTiendas = 0;
	bool dejarCapturar = false;

	while (dejarCapturar == false) {
		numTiendas++;
		if (numTiendas > maximoTiendas) {
			dejarCapturar = true;
		} else {
			printf("\nIntroduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
			int correctName = scanf("%c", &letraNombre);
			getchar();

			while (find(usadas.begin(), usadas.end(), toupper(letraNombre)) != usadas.end()) {
				error(5);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			while (letraNombre == 'x' && numTiendas < (minimoTiendas+2)) {
				error(1);
				printf("\nIntroduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			while ((correctName != 1) || (!isalpha(letraNombre))) {
				error(3);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				getchar();
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			if (letraNombre == 'x' && numTiendas > (minimoTiendas + 1)) {
				dejarCapturar = true;
				break;
			}
			while (letraNombre == 'x' && numTiendas < (minimoTiendas + 2)) {
				error(1);
				printf("\nIntroduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			while (find(usadas.begin(), usadas.end(), toupper(letraNombre)) != usadas.end()) {
				error(5);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}	
			while ((correctName != 1) || (!isalpha(letraNombre))) {
				error(3);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				getchar();
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			if (letraNombre == 'x' && numTiendas > (minimoTiendas + 1)) {
				dejarCapturar = true;
				break;
			}
			while ((correctName != 1) || (!isalpha(letraNombre))) {
				error(3);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				getchar();
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			while (find(usadas.begin(), usadas.end(), toupper(letraNombre))!=usadas.end()){
				error(5);
				printf("Introduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			while (letraNombre == 'x' && numTiendas < (minimoTiendas + 2)) {
				error(1);
				printf("\nIntroduzca el nombre de la tienda (%d) con una letra : ", numTiendas);
				correctName = scanf("%c", &letraNombre);
				getchar();
			}
			if (letraNombre == 'x' && numTiendas > (minimoTiendas + 1)) {
				dejarCapturar = true;
				break;
			}
			
			usadas.push_back(toupper(letraNombre));
			nombre.push_back(toupper(letraNombre));

			printf("Introduzca la coordenada X de la tienda (%c) entre 1 y 300: ", toupper(letraNombre));
			int correctCoordX = scanf("%d", &coordenadaX);
			getchar();
			while ((correctCoordX != 1) || (coordenadaX > 300 || coordenadaX < 1)) {
				error(2);
				printf("Introduzca la coordenada X de la tienda (%c) entre 1 y 300 : ", toupper(letraNombre));
				correctCoordX = scanf("%d", &coordenadaX);
				getchar();
			}
			x.push_back(coordenadaX);

			printf("Introduzca la coordenada Y de la tienda (%c) entre 1 y 300: ", toupper(letraNombre));
			int correctCoordY = scanf("%d", &coordenadaY);
			getchar();
			while ((correctCoordY != 1) || (coordenadaY > 300 || coordenadaY < 1)) {
				error(2);
				printf("Introduzca la coordenada Y de la tienda (%c) entre 1 y 300: ", toupper(letraNombre));
				correctCoordY = scanf("%d", &coordenadaY);
				getchar();
			}
			y.push_back(coordenadaY);

			printf("Introduzca la demanda de la tienda (%c) entre 1 y 1000: ", toupper(letraNombre));
			int correctCantidad = scanf("%d", &cantidadDemanda);
			getchar();
			while ((correctCantidad != 1) || (cantidadDemanda > 1000 || cantidadDemanda < 1)) {
				error(4);
				printf("Introduzca la demanda de la tienda (%c) entre 1 y 1000: ", toupper(letraNombre));
				correctCantidad = scanf("%d", &cantidadDemanda);
				getchar();
			}
			demanda.push_back(cantidadDemanda);

		}
		
	}
}

void imprimirO(vector<char> nombre, vector<int> x, vector<int> y, vector<int> demanda) {
	printf("\n             Tabla Original       \n");
	printf("\n Tienda   Coord X    Coord Y    Demanda\n");
	for (size_t i = 0; i < nombre.size(); i++) {
		if (x[i] < 10) { 
			if (y[i] < 10) {
				printf("   %c        %d         %d          %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d         %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d         %d        %d \n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 10 && x[i] <= 99) { 
			if (y[i] < 10) {
				printf("   %c        %d        %d          %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d        %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d        %d        %d \n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 100 && x[i] <= 999) { 
			if (y[i] < 10) {
				printf("   %c        %d       %d          %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d       %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d       %d        %d \n", nombre[i], x[i], y[i], demanda[i]);
			}
		}
	}
}

void imprimirX(vector<char> nombre, vector<int> x, vector<int> y, vector<int> demanda, char tiendaO, int xOptima) {
	printf("\n         Tabla Con Respecto a X        \n");
	printf("\nTienda   Coord X    Coord Y    Demanda   \n");
	for (size_t i = 0; i < nombre.size(); i++) {
		if (x[i] < 10) {
			if (y[i] < 10) {
				printf("   %c        %d          %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d          %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d          %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 10 && x[i] <= 99) {
			if (y[i] < 10) {
				printf("   %c        %d         %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d         %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d         %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 100 && x[i] <= 999) {
			if (y[i] < 10) {
				printf("   %c        %d        %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d        %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d        %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		}
	}
	printf("\nTienda Optima por Coordenadas en X: %c = %d\n", tiendaO, xOptima);
}

void imprimirY(vector<char> nombre, vector<int> x, vector<int> y, vector<int> demanda, char tiendaO, int yOptima) {
	printf("\n        Tabla Con Respecto a Y             \n");
	printf("\nTienda   Coord X    Coord Y    Demanda    \n");
	for (size_t i = 0; i < nombre.size(); i++) {
		if (x[i] < 10) {
			if (y[i] < 10) {
				printf("   %c        %d          %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d          %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d          %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 10 && x[i] <= 99) {
			if (y[i] < 10) {
				printf("   %c        %d         %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d         %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d         %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		} else if (x[i] >= 100 && x[i] <= 999) {
			if (y[i] < 10) {
				printf("   %c        %d        %d          %d         %d \n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 10 && y[i] <= 99) {
				printf("   %c        %d        %d         %d          %d\n", nombre[i], x[i], y[i], demanda[i]);
			} else if (y[i] >= 100 && y[i] <= 999) {
				printf("   %c        %d        %d        %d           %d\n", nombre[i], x[i], y[i], demanda[i]);
			}
		}
	}
		printf("\nTienda Optima por Coordenadas en Y: %c = %d\n", tiendaO, yOptima);
}

int main() {	
	printf("\nBienvenido. \n\nPara terminar de introducir tiendas use la letra (x) como el nombre de alguna.\n");

	vector<char> nombresTiendasO;
	vector<int> coordXO, coordYO, demandaTiendasO;
	capturar(nombresTiendasO, coordXO, coordYO, demandaTiendasO);
	imprimirO(nombresTiendasO, coordXO, coordYO, demandaTiendasO);

	vector<char> nombresTiendas(nombresTiendasO);
	vector<int> coordX(coordXO);
	vector<int> coordY(coordYO);
	vector<int> demandaTiendas(demandaTiendasO);

	vector<pair<char, int>> zippedUno;
	vector<pair<int, int>> zippedDos;
	vector<pair<int, int>> zippedTres;

	zip(nombresTiendasO, coordXO, zippedUno);
	sort(begin(zippedUno), end(zippedUno), [&](const auto& a, const auto& b) {return a.second < b.second;});
	unzip(zippedUno, nombresTiendas, coordX);

	zip(coordYO, coordXO, zippedDos);
	sort(begin(zippedDos), end(zippedDos), [&](const auto& a, const auto& b) {return a.second < b.second; });
	unzip(zippedDos, coordY, coordX);

	zip(demandaTiendasO, coordXO, zippedTres);
	sort(begin(zippedTres), end(zippedTres), [&](const auto& a, const auto& b) {return a.second < b.second; });
	unzip(zippedTres, demandaTiendas, coordX);

	vector<int> acomuladoX;
	int xOptima;
	int sumX = 0;
	for (auto& n : demandaTiendas) {
		sumX += n;
		acomuladoX.push_back(sumX);
	}
	double semiSumX = ((double)(sumX) / 2.0);
	int contadorAcomX = -1;
	char tiendaOptimaX;
	int acomX = 0;
	for (auto& n : demandaTiendas) {
		contadorAcomX++;
		acomX += n;
		if (acomX >= semiSumX) {
			tiendaOptimaX = nombresTiendas[(contadorAcomX-1)];
			xOptima = coordX[(contadorAcomX-1)];
			break;
		}
	}
	imprimirX(nombresTiendas, coordX, coordY, demandaTiendas, tiendaOptimaX, xOptima);
	zippedUno.clear(); zippedDos.clear(); zippedTres.clear();
	nombresTiendas.clear(); coordX.clear(); coordY.clear(); demandaTiendas.clear();
	nombresTiendas = nombresTiendasO; coordX = coordXO; coordY = coordYO; demandaTiendas = demandaTiendasO;

	zip(nombresTiendasO, coordYO, zippedUno);
	sort(begin(zippedUno), end(zippedUno), [&](const auto& a, const auto& b) {return a.second < b.second; });
	unzip(zippedUno, nombresTiendas, coordY);

	zip(coordXO, coordYO, zippedDos);
	sort(begin(zippedDos), end(zippedDos), [&](const auto& a, const auto& b) {return a.second < b.second; });
	unzip(zippedDos, coordX, coordY);

	zip(demandaTiendasO, coordYO, zippedTres);
	sort(begin(zippedTres), end(zippedTres), [&](const auto& a, const auto& b) {return a.second < b.second; });
	unzip(zippedTres, demandaTiendas, coordY);

	vector<int> acomuladoY;
	int yOptima;
	int sumY = 0;
	for (auto& n : demandaTiendas) {
		sumY += n;
		acomuladoY.push_back(sumY);
	}
	double semiSumY = ((double)(sumY) / 2.0);
	int contadorAcomY = -1;
	char tiendaOptimaY;
	int acomY = 0;
	for (auto& n : demandaTiendas) {
		contadorAcomY++;
		acomY += n;
		if (acomY >= semiSumY) {
			tiendaOptimaY = nombresTiendas[(contadorAcomY - 1)];
			yOptima = coordY[(contadorAcomY - 1)];
			break;
		}
	}
	imprimirY(nombresTiendas, coordX, coordY, demandaTiendas, tiendaOptimaY, yOptima);
	_getche();
	return 0;
}
