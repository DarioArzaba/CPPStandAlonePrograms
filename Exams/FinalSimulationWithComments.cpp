#pragma comment (lib, "User32.lib")
//Funcion del profesor para poder utilizar GOTOXY
#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif

//Importar Librerias
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <istream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;

//Esta funcion cambia el tamano de la ventana, necesario para que se alcancen a imprimir todos los datos.
void cambiarTamanoVentana (int largo, int alto) {
	HWND console = GetConsoleWindow(); RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, largo, alto, TRUE);
}

//Esta funcion despliega la mayoria de los mensajes de error del programa.
//Los mensajes pueden utilizar un minimo y un maximo opcional en el caso de que el error sea por un dato fuera de rango.
void error(int numError, int min, int max) {
	if (numError == 1) {
		printf("Error. La opcion debe ser un numero entero entre %d y %d", min, max);
	} else if (numError == 2) {
		printf("Error. La matricula debe tener exactamente %d posiciones.", min);
	} else if (numError == 3) {
		printf("Error. La matricula debe de iniciar con la letra %c", min);
	} else if (numError == 4) {
		printf("Error. La matricula debe de terminar con tres cifras numericas.");
	} else if (numError == 5) {
		printf("Error. La matricula ya fue ingresada en la base de datos.");
	} else if (numError == 6) {
		printf("Error. El dia debe ser un numero entero entre %d y %d", min, max);
	} else if (numError == 7) {
		printf("Error. El mes debe ser un numero entero entre %d y %d", min, max);
	} else if (numError == 8) {
		printf("Error. El a%co debe ser un numero entero superior a %d", 164, min);
	} else if (numError == 9) {
		printf("Error. El nombre debe tener entre %d y %d letras.", min, max);
	} else if (numError == 10) {
		printf("Error. El apellido paterno debe tener entre %d y %d letras.", min, max);
	} else if (numError == 11) {
		printf("Error. El apellido materno debe tener entre %d y %d letras.", min, max);
	} else if (numError == 12) {
		printf("Error. El promedio debe ser un numero flotante entre %d y %d.", min, max);
	} else if (numError == 13) {
		printf("Error. La clave de carrera debe tener entre %d y %d posiciones.", min, max);
	} else if (numError == 14) {
		printf("Error. La clave de carrera no es valida ya que no existe en la base de datos.");
	}
}

//Esta funcion utiliza una matricula proporcionada por el usuario y la busca en el archivo de alumnos.
//Si la matricula se encuentra en dicho archivo genera un booleano verdadero, de lo contrario genera uno falso.
bool buscarMatricula(char* m) {
  //Variables del archivo a capturar
	char mat[5], nom[20], ap[20], am[20], clave[3], correo[30];
	int dia, mes, anno;
	float prom;
  //Copiamos la matricula proporcionada por el usuario (m) a una temporal (mat_aux)
	char mat_aux[5]; strcpy(mat_aux, m);
  //Creamos el booleano que va a terminar por generar la funcion al final
	bool sw_existe = false;
  //Abrimos el archivo de alumnos.txt en modo de Lectura
	ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
  //Si no se puede abrir el archivo generamos de inmediato el booleano como falso.
	if (archivoAlumnos.fail()) {
		archivoAlumnos.close();
		return sw_existe;
	} else {
    //Si si se pudo abrir el archivo el siguiente (while) buscara LINEA POR LINEA hasta el final del mismo.
		while (!archivoAlumnos.eof()) {
      //Capturamos todos los datos de la primer (segunda etc..) linea:
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
      //Si la matricula proporcionada por el usuario (copiada a mat_aux) es igual a la de la linea que acabamos de capturar...
      //... entonces acabamos de encontrar al alumno correcto.
			if ( strcmp(mat, mat_aux) ==0) {
        //Dado que cada alumno tiene una unica matricula ya no tenemos que seguir buscando.
        //Podemos cerrar el archivo. Generamos el booleano final como verdadero.
				archivoAlumnos.close();
				sw_existe = true;
				return sw_existe;
			}
      //Si la matricula NO es igual a la de la linea entonces no pasa nada.
      //Y el (while) continua a buscar en la siguiente linea.
		}
    //Si el programa llego ha este punto significa que pudo abrir el archivo
    //Y el (while) busco linea por linea pero nunca encontro una matricula igual a la introducida por el usuario.
    //Entonces asumimos que la matricula no existe dentro del archivo. Lo cerramos y generamos el booleano final como falso.
		archivoAlumnos.close();
		return sw_existe;
	}
}

//Esta funcion utiliza una clave de carrera proporcionada por el usuario y la busca en el archivo de carreras.
//Si la clave se encuentra en dicho archivo genera un booleano verdadero, de lo contrario genera uno falso.
//Es exactamente igual a la funcion anterior, solo que busca una clave y no una matricula.
bool buscarClave(char* clave) {
	char c[3], nom[30];
	char clave_aux[3]; strcpy(clave_aux, clave);
	bool sw_existe = false;
	ifstream archivoCarreras;
	archivoCarreras.open("carreras.txt",ios::in);
	if (archivoCarreras.fail()) {
		archivoCarreras.close();
		return sw_existe;
	} else {
		while (!archivoCarreras.eof()) {
			archivoCarreras >> c >> nom;
			if ( strcmp(c, clave_aux) ==0) {
				archivoCarreras.close();
				sw_existe = true;
				return sw_existe;
			}
		}
		archivoCarreras.close();
		return sw_existe;
	}
}

//Esta funcion le pide al usuario una matricula, busca la matricula en el archivo de alumnos y de encontrarla despliega los datos de dicho alumno.
void consultaMatricula () {
  //Variables del archivo a capturar
	char mat[5], nom[20], ap[20], am[20], clave[5], correo[50];
	int dia, mes, anno;
	float prom;
  //Renglon desde donde imprimir al alumno que encontremos con dicha matricula
  //El primer renglon es para los titulos de los datos y el segundo es una linea divisora
	int ren = 3;
  //Variable en donde vamos a copiar la matricula que proporcione el usuario
	char mat_aux[5]; 
  //Este booleano se volvera verdadero cuando encontremos a un alumno con la matricula
  //Para lo unico que lo utilizo es por si no encontramos ningun alumno se va a quedar en falso y por tanto puedo enviar el mensaje de error de que no se encontro ningun alumno con dicha matricula.
	bool encontrado = false;
  //Limpiamos la ventana que se quedo con el menu original.
	system("cls");
  //Pedimos y guardamos la matricula del usuario en la variable (mat_aux)
	printf("\n\nIndica la Matr%ccula a consultar : ", 161); 
	gets_s(mat_aux);
  //Volvemos a limpiar la pantalla e imprimimos el titulo de los datos y la linea divisora
  //Todos los resultados o mensajes de error comenzaran desde el tercer renglon
	system("cls");
	gotoxy(1,1); printf(" Matr%ccula |       Nombre       |  Apellido Paterno  |  Apellido Materno  | D  | M  | A%co  | Promedio | Clave | Correo ", 161, 164);
	gotoxy(2,2); printf("-------------------------------------------------------------------------------------------------------------------------------");
	//Abrimos el archivo de alumnos en modo Lectura
  ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
  //Si no pudimos abrir el archivo significa que no existe y como resultado solo imprimirmos el error.
	if (archivoAlumnos.fail()) {
		printf("\n\n Error. El archivo alumnos.txt no existe !");
		getche();
	} else {
    //Si si se pudo abrir entonces si existe.
    //Este (while) buscara linea por linea hasta terminar el archivo.
		while (!archivoAlumnos.eof()) {
      //Capturamos todos los datos de la linea actual
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
      //Si no estamos en la ultima linea y la matricula del usuario (mat_aux) es igual a la capturada (mat) entonces encontramos
      //al alumno de la matricula
			if (  !archivoAlumnos.eof() && (strcmp(mat, mat_aux) ==0)) {
        //Antes de imprimir los datos del alumno sustityo los guiones por espacios en su nombre y apellidos
				for (int i = 0; i < strlen(nom); i++){ if (nom[i] == '_') { nom[i] = ' '; } }
				for (int i = 0; i < strlen(ap); i++){ if (ap[i] == '_') { ap[i] = ' '; } }
				for (int i = 0; i < strlen(am); i++){ if (am[i] == '_') { am[i] = ' '; } }
				gotoxy(4,ren); printf("%s",mat); gotoxy(12,ren); printf("|");
				gotoxy(13,ren); printf("%s",nom); gotoxy(33,ren); printf("|");
				gotoxy(34,ren); printf("%s",ap); gotoxy(54,ren); printf("|");
				gotoxy(55,ren); printf("%s",am); gotoxy(75,ren); printf("|");
				gotoxy(77,ren); printf("%d", dia); gotoxy(80,ren); printf("|");
				gotoxy(82,ren); printf("%d", mes); gotoxy(85,ren); printf("|");
				gotoxy(87,ren); printf("%d", anno); gotoxy(92,ren); printf("|");
				gotoxy(94,ren); printf("%6.2f",prom); gotoxy(103,ren); printf("|");
				gotoxy(105,ren); printf("%s",clave); gotoxy(111,ren); printf("|");
				gotoxy(113,ren); printf("%s",correo);
				ren++;
        //Debido a que si encontramos al alumno con la matricula el booleano se vuelve verdadero evitando el error que esta a continuacion.
				encontrado = true;
			}
		}
    //Este es el error que se activa si el booleano se quedo como falso, es decir que no encontramos al alumno.
		if (encontrado == false) {
			printf("\n\n Error. No se encontro la matricula %s", mat_aux);
			getche();
		} else {
			getche();
		}
	}
  //No importa si encontramos al alumno, no lo encontramos o nisiquera pudimos abrir el archivo. En todos los casos llegaremos a este punto.
  //Entonces en todos los casos terminamos por cerrar el archivo de alumnos y limpiamos la pantalla.
	archivoAlumnos.close();
	system("cls");	
}

//Esta funcion es exactamente igual a la anterior solo que en vez de comparar una matricula utilizamos un correo.
void consultaCorreo () {
	char mat[5], nom[20], ap[20], am[20], clave[5], correo[50];
	int dia, mes, anno;
	float prom;
	int ren = 3;
	char correo_aux[50]; 
	bool encontrado = false;
	system("cls");
	printf("\n\nIndica el Correo a consultar : "); 
	gets_s(correo_aux);	
	system("cls");
	gotoxy(1,1); printf(" Matr%ccula |       Nombre       |  Apellido Paterno  |  Apellido Materno  | D  | M  | A%co  | Promedio | Clave | Correo ", 161, 164);
	gotoxy(2,2); printf("-------------------------------------------------------------------------------------------------------------------------------");
	ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
	if (archivoAlumnos.fail()) {
		printf("\n\n Error. El archivo alumnos.txt no existe !");
		getche();
	} else {
		while (!archivoAlumnos.eof()) {
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
			if (  !archivoAlumnos.eof() && (strcmp(correo, correo_aux) ==0)) {
				for (int i = 0; i < strlen(nom); i++){ if (nom[i] == '_') { nom[i] = ' '; } }
				for (int i = 0; i < strlen(ap); i++){ if (ap[i] == '_') { ap[i] = ' '; } }
				for (int i = 0; i < strlen(am); i++){ if (am[i] == '_') { am[i] = ' '; } }
				gotoxy(4,ren); printf("%s",mat); gotoxy(12,ren); printf("|");
				gotoxy(13,ren); printf("%s",nom); gotoxy(33,ren); printf("|");
				gotoxy(34,ren); printf("%s",ap); gotoxy(54,ren); printf("|");
				gotoxy(55,ren); printf("%s",am); gotoxy(75,ren); printf("|");
				gotoxy(77,ren); printf("%d", dia); gotoxy(80,ren); printf("|");
				gotoxy(82,ren); printf("%d", mes); gotoxy(85,ren); printf("|");
				gotoxy(87,ren); printf("%d", anno); gotoxy(92,ren); printf("|");
				gotoxy(94,ren); printf("%6.2f",prom); gotoxy(103,ren); printf("|");
				gotoxy(105,ren); printf("%s",clave); gotoxy(111,ren); printf("|");
				gotoxy(113,ren); printf("%s",correo);
				ren++;
				encontrado = true;
			}
		}
		if (encontrado == false) {
			printf("\n\n Error. No se encontro un alumno con el correo %s", correo_aux);
			getche();
		} else {
			getche();
		}
	}
	archivoAlumnos.close();
	system("cls");	
}

//Exactamente igual a la funcion anterior solo que en vez de utilizar el correo utilizo el apellido paterno
void listaApellidoPaterno () {
	char mat[5], nom[20], ap[20], am[20], clave[5], correo[50];
	int dia, mes, anno;
	float prom;
	int ren = 3;
	char ap_aux[20]; 
	bool encontrado = false;
	system("cls");
	printf("\n\nIndica el Apellido Paterno a consultar : "); 
	gets_s(ap_aux);	
	system("cls");
	gotoxy(1,1); printf(" Matr%ccula |       Nombre       |  Apellido Paterno  |  Apellido Materno  | D  | M  | A%co  | Promedio | Clave | Correo ", 161, 164);
	gotoxy(2,2); printf("-------------------------------------------------------------------------------------------------------------------------------");
	ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
	if (archivoAlumnos.fail()) {
		printf("\n\n Error. El archivo alumnos.txt no existe !");
		getche();
	} else {
		while (!archivoAlumnos.eof()) {
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
			if (  !archivoAlumnos.eof() && (strcmp(ap, ap_aux) == 0)) {
				for (int i = 0; i < strlen(nom); i++){ if (nom[i] == '_') { nom[i] = ' '; } }
				for (int i = 0; i < strlen(ap); i++){ if (ap[i] == '_') { ap[i] = ' '; } }
				for (int i = 0; i < strlen(am); i++){ if (am[i] == '_') { am[i] = ' '; } }
				gotoxy(4,ren); printf("%s",mat); gotoxy(12,ren); printf("|");
				gotoxy(13,ren); printf("%s",nom); gotoxy(33,ren); printf("|");
				gotoxy(34,ren); printf("%s",ap); gotoxy(54,ren); printf("|");
				gotoxy(55,ren); printf("%s",am); gotoxy(75,ren); printf("|");
				gotoxy(77,ren); printf("%d", dia); gotoxy(80,ren); printf("|");
				gotoxy(82,ren); printf("%d", mes); gotoxy(85,ren); printf("|");
				gotoxy(87,ren); printf("%d", anno); gotoxy(92,ren); printf("|");
				gotoxy(94,ren); printf("%6.2f",prom); gotoxy(103,ren); printf("|");
				gotoxy(105,ren); printf("%s",clave); gotoxy(111,ren); printf("|");
				gotoxy(113,ren); printf("%s",correo);
				ren++;
				encontrado = true;
			}
		}
		if (encontrado == false) {
			printf("\n\n Error. No se encontraron alumnos con el apellido %s", ap_aux);
			getche();
		} else {
			getche();
		}
	}
	archivoAlumnos.close();
	system("cls");
}

//Esta funcion es de hecho mucho mas facil que las anteriores.
//En este caso lo unico que hice fue agregar las variables float de alumnos y promedioSuma
//No estoy comparando nada como en las anteriores [strcmp(ap, ap_aux) == 0)] porque quiero que se impriman todos los alumnos.
//Cada ves que se imprime un nuevo alumno utilizo su promedio y lo sumo a PromedioSuma
//Al final de la funcion, despues de que se imprimeron todos los alumnos obtengo el promedioGlobal  y simplemente lo imprimo.
void reporteTodos () {
	char mat[5], nom[20], ap[20], am[20], clave[5], correo[50];
	int dia, mes, anno;
	float prom;
	int ren = 3;
	float alumnos = 0;
	float promedioSuma = 0;
	system("cls");
	gotoxy(1,1); printf(" Matr%ccula |       Nombre       |  Apellido Paterno  |  Apellido Materno  | D  | M  | A%co  | Promedio | Clave | Correo ", 161, 164);
	gotoxy(2,2); printf("-------------------------------------------------------------------------------------------------------------------------------");
	ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
	if (archivoAlumnos.fail()) {
		printf("\n\n Error. El archivo alumnos.txt no existe !");
		getche();
	} else {
		while (!archivoAlumnos.eof()) {
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
			
			if (!archivoAlumnos.eof()){
				for (int i = 0; i < strlen(nom); i++){ if (nom[i] == '_') { nom[i] = ' '; } }
				for (int i = 0; i < strlen(ap); i++){ if (ap[i] == '_') { ap[i] = ' '; } }
				for (int i = 0; i < strlen(am); i++){ if (am[i] == '_') { am[i] = ' '; } }
				gotoxy(4,ren); printf("%s",mat); gotoxy(12,ren); printf("|");
				gotoxy(13,ren); printf("%s",nom); gotoxy(33,ren); printf("|");
				gotoxy(34,ren); printf("%s",ap); gotoxy(54,ren); printf("|");
				gotoxy(55,ren); printf("%s",am); gotoxy(75,ren); printf("|");
				gotoxy(77,ren); printf("%d", dia); gotoxy(80,ren); printf("|");
				gotoxy(82,ren); printf("%d", mes); gotoxy(85,ren); printf("|");
				gotoxy(87,ren); printf("%d", anno); gotoxy(92,ren); printf("|");
				gotoxy(94,ren); printf("%6.2f",prom); gotoxy(103,ren); printf("|");
				gotoxy(105,ren); printf("%s",clave); gotoxy(111,ren); printf("|");
				gotoxy(113,ren); printf("%s",correo);
				ren++;
				alumnos++;
				promedioSuma += prom;
			}	
		}
		float promedioGlobal = (promedioSuma / alumnos);
		gotoxy(2,ren); printf("-------------------------------------------------------------------------------------------------------------------------------");
		gotoxy(1,ren+2); printf(" El Promedio Global de todos los alumnos es de %6.2f ", promedioGlobal);
		getche();
	}
	archivoAlumnos.close();
	system("cls");
}

//Este es igual a la funcion al anterior, unicamente que no voy a imprimir todos los alumnos solo los que tengan la Clave correcta [strcmp(clave, clave_aux) == 0)]
void reporteCarrera() {
	char mat[5], nom[20], ap[20], am[20], clave[5], correo[50];
	int dia, mes, anno;
	float prom;
	int ren = 3;
	char clave_aux[20]; 
	bool encontrado = false;
	float alumnos = 0;
	float promedioSuma = 0;
	system("cls");
	printf("\n\nIndica la Clave de Carrera a consultar : "); 
	gets_s(clave_aux);	
	system("cls");
	gotoxy(1,1); printf(" Matr%ccula |       Nombre       |  Apellido Paterno  |  Apellido Materno  | D  | M  | A%co  | Promedio | Clave | Correo ", 161, 164);
	gotoxy(2,2); printf("-------------------------------------------------------------------------------------------------------------------------------");
	ifstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt",ios::in);
	if (archivoAlumnos.fail()) {
		printf("\n\n Error. El archivo alumnos.txt no existe !");
		getche();
	} else {
		while (!archivoAlumnos.eof()) {
			archivoAlumnos >> mat >> nom >> ap >> am >> dia >> mes >> anno >> prom >> clave >> correo;
			if (  !archivoAlumnos.eof() && (strcmp(clave, clave_aux) == 0)) {
				for (int i = 0; i < strlen(nom); i++){ if (nom[i] == '_') { nom[i] = ' '; } }
				for (int i = 0; i < strlen(ap); i++){ if (ap[i] == '_') { ap[i] = ' '; } }
				for (int i = 0; i < strlen(am); i++){ if (am[i] == '_') { am[i] = ' '; } }
				gotoxy(4,ren); printf("%s",mat); gotoxy(12,ren); printf("|");
				gotoxy(13,ren); printf("%s",nom); gotoxy(33,ren); printf("|");
				gotoxy(34,ren); printf("%s",ap); gotoxy(54,ren); printf("|");
				gotoxy(55,ren); printf("%s",am); gotoxy(75,ren); printf("|");
				gotoxy(77,ren); printf("%d", dia); gotoxy(80,ren); printf("|");
				gotoxy(82,ren); printf("%d", mes); gotoxy(85,ren); printf("|");
				gotoxy(87,ren); printf("%d", anno); gotoxy(92,ren); printf("|");
				gotoxy(94,ren); printf("%6.2f",prom); gotoxy(103,ren); printf("|");
				gotoxy(105,ren); printf("%s",clave); gotoxy(111,ren); printf("|");
				gotoxy(113,ren); printf("%s",correo);
				ren++;
				alumnos++;
				promedioSuma += prom;
				encontrado = true;
			}
		}
		if (encontrado == false) {
			printf("\n\n Error. No se encontraron alumnos con la clave %s", clave_aux);
			getche();
		} else {
			float promedioGlobal = (promedioSuma / alumnos);
			gotoxy(2,ren); printf("-------------------------------------------------------------------------------------------------------------------------------");
			gotoxy(1,ren+2); printf(" El promedio de los alumnos de %s es de %6.2f ", clave  ,promedioGlobal);
			getche();
		}
	}
	archivoAlumnos.close();
	system("cls");
}

//Esta funcion es parecida a la de reporteTodos solo que no pongo el promedio al final y utilizo los datos de carreras.txt pero el formato es el mismo
void listaCarreras() {
	char clave[5], carrera[31];
	int ren = 3;
	system("cls");
	gotoxy(1,1); printf(" Clave  |  Nombre de la Carrera           ");
	gotoxy(2,2); printf("-------------------------------------------");
	ifstream archivoCarreras;
	archivoCarreras.open("carreras.txt", ios::in);
	if (archivoCarreras.fail()) {
		printf("\n\n Error. El archivo carreras.txt no existe !");
		getche();
	} else {
		while (!archivoCarreras.eof()) {
			archivoCarreras >> clave >> carrera;
			if (!archivoCarreras.eof()){
				for (int i = 0; i < strlen(carrera); i++){ if (carrera[i] == '_') { carrera[i] = ' '; } }
				gotoxy(2,ren); printf("%s", clave); gotoxy(9,ren); printf("|");
				gotoxy(12,ren); printf("%s", carrera);
				ren++;	
			}
		}
		getche();
	}
	archivoCarreras.close();
	system("cls");
}

//Esta de nuevo es igual a consulaMatricula pero en vez de una matricula comparo una clave strcmp(clave, clave_aux) == 0)
//Y en vez de hacerlo en alumnos.txt lo hago en carreras.txt para obtener el nombre de la carrera
void consultaCarrera() {
	char clave[5], carrera[31];
	int ren = 3;
	char clave_aux[5]; 
	bool encontrado = false;
	system("cls");
	printf("\n\nIndica la Clave de Carrera a consultar : "); 
	gets_s(clave_aux);
	system("cls");
	gotoxy(1,1); printf(" Clave  |  Nombre de la Carrera           ");
	gotoxy(2,2); printf("-------------------------------------------");
	ifstream archivoCarreras;
	archivoCarreras.open("carreras.txt", ios::in);
	if (archivoCarreras.fail()) {
		printf("\n\n Error. El archivo carreras.txt no existe !");
		getche();
	} else {
		while (!archivoCarreras.eof()) {
			archivoCarreras >> clave >> carrera;
			if ( !archivoCarreras.eof() && (strcmp(clave, clave_aux) == 0)) {
				for (int i = 0; i < strlen(carrera); i++){ if (carrera[i] == '_') { carrera[i] = ' '; } }
				gotoxy(2,ren); printf("%s", clave); gotoxy(9,ren); printf("|");
				gotoxy(12,ren); printf("%s", carrera);
				ren++;
				encontrado = true;
			}
		}
		if (encontrado == false) {
			printf("\n\n Error. No se encontro una carrera con clave %s", clave_aux);
			getche();
		} else {
			getche();
		}
	}
	archivoCarreras.close();
	system("cls");	
}


char* obtenerMatricula() {
	static char str[4];
	printf("Indica la Matricula : ");
	gets_s(str);
	int tamanoMatricula = strlen(str);
	bool tamanoCorrecto = false;
	bool primerCaracter = false;
	bool numerosFinales = false;
	bool otrasMatriculas = false;
	bool matriculaValida = false;
	tamanoCorrecto = (tamanoMatricula == 4);
	primerCaracter = (str[0] == 'A');
	numerosFinales = isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]);
	otrasMatriculas = buscarMatricula(str);
	matriculaValida = ((tamanoCorrecto == true) && (primerCaracter == true) && (numerosFinales == true) && (otrasMatriculas == false));
	while (!matriculaValida) {
		if (tamanoCorrecto == false){
			error(2, 4, 1);
		} else if (primerCaracter == false){
			error(3, 65, 1);
		} else if (numerosFinales == false){
			error(4, 1, 1);
		} else if (otrasMatriculas == true){
			error(5, 1, 1);
		}
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : ");
		gets_s(str);
		tamanoMatricula = strlen(str);
		tamanoCorrecto = false;
		primerCaracter = false;
		numerosFinales = false;
		otrasMatriculas = false;
		matriculaValida = false;
		tamanoCorrecto = (tamanoMatricula == 4);
		primerCaracter = ((str[0]) == 'A');
		numerosFinales = isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]);
		otrasMatriculas = buscarMatricula(str);
		matriculaValida = ((tamanoCorrecto == true) && (primerCaracter == true) && (numerosFinales == true)  && (otrasMatriculas == false) );
	}
	return str;
}

char* obtenerNombre(char* m) {
	char matricula[5]; strcpy(matricula, m);
	static char str[20];	
	printf("Indica el Nombre : ");
	gets_s(str);
	int tamanoNombre = strlen(str);
	bool soloLetras = true;
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i])) {
			soloLetras = false;
		}		
	}
	while ((tamanoNombre < 1) || (tamanoNombre > 20) || (!soloLetras) ) {
		error(9, 1, 20);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : ");
		gets_s(str);
		tamanoNombre = strlen(str);
		soloLetras = true;
		for (int i = 0; i < strlen(str); i++){
			if (isdigit(str[i])) {
				soloLetras = false;
			}		
		}
	}
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') { str[i] = '_'; } 
		else if (str[i] == char(160)){ str[i] = 'a'; } 
		else if (str[i] == char(181)){ str[i] = 'A'; } 
		else if (str[i] == char(130)){ str[i] = 'e'; } 
		else if (str[i] == char(144)){ str[i] = 'E'; } 
		else if (str[i] == char(161)){ str[i] = 'i'; } 
		else if (str[i] == char(214)){ str[i] = 'I'; } 
		else if (str[i] == char(162)){ str[i] = 'o'; } 
		else if (str[i] == char(224)){ str[i] = 'O'; } 
		else if (str[i] == char(163)){ str[i] = 'u'; } 
		else if (str[i] == char(233)){ str[i] = 'U'; } 
		else if (str[i] == char(164)){ str[i] = 'n'; } 
		else if (str[i] == char(165)){ str[i] = 'N'; }		
	}
	return str;
}

char* obtenerApellidoPaterno(char* m, char* n) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	static char str[20];
	printf("Indica el Apellido Paterno : ");
	gets_s(str);
	int tamanoApellidoP = strlen(str);
	bool soloLetras = true;
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i])) {
			soloLetras = false;
		}		
	}
	while ((tamanoApellidoP < 1) || (tamanoApellidoP > 20) || (!soloLetras)  ) {
		error(10, 1, 20);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : ");
		gets_s(str);
		tamanoApellidoP = strlen(str);
		soloLetras = true;
		for (int i = 0; i < strlen(str); i++){
			if (isdigit(str[i])) {
				soloLetras = false;
			}		
		}
	}
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') { str[i] = '_'; } 
		else if (str[i] == char(160)){ str[i] = 'a'; } 
		else if (str[i] == char(181)){ str[i] = 'A'; } 
		else if (str[i] == char(130)){ str[i] = 'e'; } 
		else if (str[i] == char(144)){ str[i] = 'E'; } 
		else if (str[i] == char(161)){ str[i] = 'i'; } 
		else if (str[i] == char(214)){ str[i] = 'I'; } 
		else if (str[i] == char(162)){ str[i] = 'o'; } 
		else if (str[i] == char(224)){ str[i] = 'O'; } 
		else if (str[i] == char(163)){ str[i] = 'u'; } 
		else if (str[i] == char(233)){ str[i] = 'U'; } 
		else if (str[i] == char(164)){ str[i] = 'n'; } 
		else if (str[i] == char(165)){ str[i] = 'N'; }		
	}
	return str;
}

char* obtenerApellidoMaterno(char* m, char* n, char* ap) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	static char str[20];
	printf("Indica el Apellido Materno : ");
	gets_s(str);
	int tamanoApellidoM = strlen(str);
	bool soloLetras = true;
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i])) {
			soloLetras = false;
		}		
	}
	while ((tamanoApellidoM < 1) || (tamanoApellidoM > 20) || (!soloLetras)  ) {
		error(11, 1, 20);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : ");
		gets_s(str);
		tamanoApellidoM = strlen(str);
		soloLetras = true;
		for (int i = 0; i < strlen(str); i++){
			if (isdigit(str[i])) {
				soloLetras = false;
			}		
		}
	}
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') { str[i] = '_'; } 
		else if (str[i] == char(160)){ str[i] = 'a'; } 
		else if (str[i] == char(181)){ str[i] = 'A'; } 
		else if (str[i] == char(130)){ str[i] = 'e'; } 
		else if (str[i] == char(144)){ str[i] = 'E'; } 
		else if (str[i] == char(161)){ str[i] = 'i'; } 
		else if (str[i] == char(214)){ str[i] = 'I'; } 
		else if (str[i] == char(162)){ str[i] = 'o'; } 
		else if (str[i] == char(224)){ str[i] = 'O'; } 
		else if (str[i] == char(163)){ str[i] = 'u'; } 
		else if (str[i] == char(233)){ str[i] = 'U'; } 
		else if (str[i] == char(164)){ str[i] = 'n'; } 
		else if (str[i] == char(165)){ str[i] = 'N'; }		
	}
	return str;
}

int obtenerDia (int min, int max, char* m, char* n, char* ap, char* am) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	char apellidoMaterno[20]; strcpy(apellidoMaterno, am);
	int diaNacimiento;
	printf("Indica el Dia de Nacimiento: ");
	string dia; getline(cin, dia);
	bool soloNumeros = true;
	bool rangoValido = true;
	for (int i = 0; i < strlen(dia.c_str()); i++){
		if (!isdigit(dia[i])){
			soloNumeros = false;
		}
	}
	rangoValido = ((atoi(dia.c_str()) <= max) && (atoi(dia.c_str()) >= min));
	while (!(soloNumeros && rangoValido)) {
		error(6, min, max);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : %s \n", apellidoMaterno);
		printf("Indica el Dia de Nacimiento: ");
		getline(cin, dia);
		soloNumeros = true;
		rangoValido = true;
		for (int i = 0; i < strlen(dia.c_str()); i++){
			if (!isdigit(dia[i])){
				soloNumeros = false;
			}
		}
		rangoValido = ((atoi(dia.c_str()) <= max) && (atoi(dia.c_str()) >= min));
	}
	diaNacimiento = atoi(dia.c_str());
	return diaNacimiento;
}

int obtenerMes (int min, int max, char* m, int diaNacimiento, char* n, char* ap, char* am) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	char apellidoMaterno[20]; strcpy(apellidoMaterno, am);
	int mesNacimiento;
	printf("Indica el Mes de Nacimiento: ");
	string mes; getline(cin, mes);
	bool soloNumeros = true;
	bool rangoValido = true;
	for (int i = 0; i < strlen(mes.c_str()); i++){
		if (!isdigit(mes[i])){
			soloNumeros = false;
		}
	}
	rangoValido = ((atoi(mes.c_str()) <= max) && (atoi(mes.c_str()) >= min));
	while (!(soloNumeros && rangoValido)) {
		error(7, min, max);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : %s \n", apellidoMaterno);
		printf("Indica el Dia de Nacimiento: %d \n", diaNacimiento);
		printf("Indica el Mes de Nacimiento: ");
		getline(cin, mes);
		soloNumeros = true;
		rangoValido = true;
		for (int i = 0; i < strlen(mes.c_str()); i++){
			if (!isdigit(mes[i])){
				soloNumeros = false;
			}
		}
		rangoValido = ((atoi(mes.c_str()) <= max) && (atoi(mes.c_str()) >= min));
	}
	mesNacimiento = atoi(mes.c_str());
	return mesNacimiento;
}

int obtenerAnno(int min, int max, char* m, int diaNacimiento, int mesNacimiento , char* n, char* ap, char* am) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	char apellidoMaterno[20]; strcpy(apellidoMaterno, am);
	int annoNacimiento;
	printf("Indica el A%co de Nacimiento: ", 164);
	string anno; getline(cin, anno);
	bool soloNumeros = true;
	bool rangoValido = true;
	for (int i = 0; i < strlen(anno.c_str()); i++){
		if (!isdigit(anno[i])){
			soloNumeros = false;
		}
	}
	rangoValido = ((atoi(anno.c_str()) <= max) && (atoi(anno.c_str()) >= min));
	while (!(soloNumeros && rangoValido)) {
		error(8, min, max);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : %s \n", apellidoMaterno);
		printf("Indica el Dia de Nacimiento: %d \n", diaNacimiento);
		printf("Indica el Mes de Nacimiento: %d \n", mesNacimiento);
		printf("Indica el A%co de Nacimiento: ", 164);
		getline(cin, anno);
		soloNumeros = true;
		rangoValido = true;
		for (int i = 0; i < strlen(anno.c_str()); i++){
			if (!isdigit(anno[i])){
				soloNumeros = false;
			}
		}
		rangoValido = ((atoi(anno.c_str()) <= max) && (atoi(anno.c_str()) >= min));
	}
	annoNacimiento = atoi(anno.c_str());
	return annoNacimiento;
}

float obtenerPromedio (int min, int max, char* m, int diaNacimiento, int mesNacimiento, int annoNacimiento, char* n, char* ap, char* am) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	char apellidoMaterno[20]; strcpy(apellidoMaterno, am);
	float promedio, promedioFinal;
	printf("Indica el Promedio: ");
	string prom; getline(cin, prom);
	bool soloNumeros = true;
	bool rangoValido = true;
	for (int i = 0; i < strlen(prom.c_str()); i++){
		if (!isdigit(prom[i])){
			if (prom[i] != '.'){
				soloNumeros = false;
			}
		}
	}
	rangoValido = ((atof(prom.c_str()) <= max) && (atof(prom.c_str()) >= min));
	while (!(soloNumeros && rangoValido)) {
		error(12, 0, 100);
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : %s \n", apellidoMaterno);
		printf("Indica el Dia de Nacimiento: %d \n", diaNacimiento);
		printf("Indica el Mes de Nacimiento: %d \n", mesNacimiento);
		printf("Indica el A%co de Nacimiento: %d \n", 164, annoNacimiento);
		printf("Indica el Promedio: ");
		getline(cin, prom);
		soloNumeros = true;
		rangoValido = true;
		for (int i = 0; i < strlen(prom.c_str()); i++){
			if (!isdigit(prom[i])){
				if (prom[i] != '.'){
					soloNumeros = false;
				}
			}
		}
		rangoValido = ((atof(prom.c_str()) <= max) && (atof(prom.c_str()) >= min));
	}
	promedio = atof(prom.c_str());
	promedioFinal = roundf(promedio * 100) / 100;
	return promedioFinal;
}

char* obtenerCarrera(char* m, int diaNacimiento, int mesNacimiento, int annoNacimiento, float promedio, char* n, char* ap, char* am) {
	char matricula[5]; strcpy(matricula, m);
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
	char apellidoMaterno[20]; strcpy(apellidoMaterno, am);
	static char str[5];
	printf("Indica la Clave de Carrera : "); gets_s(str);
	int tamanoClave = strlen(str);
	bool tamanoCorrecto = false;
	bool claveExiste = false;
	bool claveValida = false;
	tamanoCorrecto = ( (tamanoClave == 2) || (tamanoClave == 3) || (tamanoClave == 4) );
	claveExiste = buscarClave(str);
	claveValida = ((tamanoCorrecto == true) && (claveExiste == true));
	while (!claveValida ) {
		if (tamanoCorrecto == false){
			error(13, 2, 4);
		}  else if (claveExiste == false){
			error(14, 1, 1);
		}
		Sleep(2000);
		system("cls");
		printf("Dar de Alta a Nuevo Alumno\n\n");
		printf("Indica la Matricula : %s \n", matricula);
		printf("Indica el Nombre : %s \n", nombre);
		printf("Indica el Apellido Paterno : %s \n", apellidoPaterno);
		printf("Indica el Apellido Materno : %s \n", apellidoMaterno);
		printf("Indica el Dia de Nacimiento: %d \n", diaNacimiento);
		printf("Indica el Mes de Nacimiento: %d \n", mesNacimiento);
		printf("Indica el A%co de Nacimiento: %d \n", 164, annoNacimiento);
		printf("Indica el Promedio: %f \n", promedio);
		printf("Indica la Clave de Carrera : ");
		gets_s(str);
		tamanoClave = strlen(str);
		tamanoCorrecto = false;
		claveExiste = false;
		claveValida = false;
		tamanoCorrecto = (  (tamanoClave == 2) || (tamanoClave == 3) || (tamanoClave == 4)  );
		claveExiste = buscarClave(str);
		claveValida = ((tamanoCorrecto == true) && (claveExiste == true));
	}
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ') { str[i] = '_'; } 
		else if (str[i] == char(160)){ str[i] = 'a'; } 
		else if (str[i] == char(181)){ str[i] = 'A'; } 
		else if (str[i] == char(130)){ str[i] = 'e'; } 
		else if (str[i] == char(144)){ str[i] = 'E'; } 
		else if (str[i] == char(161)){ str[i] = 'i'; } 
		else if (str[i] == char(214)){ str[i] = 'I'; } 
		else if (str[i] == char(162)){ str[i] = 'o'; } 
		else if (str[i] == char(224)){ str[i] = 'O'; } 
		else if (str[i] == char(163)){ str[i] = 'u'; } 
		else if (str[i] == char(233)){ str[i] = 'U'; } 
		else if (str[i] == char(164)){ str[i] = 'n'; } 
		else if (str[i] == char(165)){ str[i] = 'N'; }		
	}
	return str;
}

//La funcion de obtener correo es la unica funcion de captura que no necesita del usuario.
//Podemos utilizar los resultados de las funciones anteriores para generar el texto que necesitamos.
//En concreto utilizaremos el nombre para la primer letra, todo el apellido y el dia, mes y anno de nacimiento.
char* obtenerCorreo(char* n, char* ap, int d, int m, int y) {
  //El correo lo guardaremos en la variable (str)
   static char str[50];
   //Copiamos los valores originales del nombre y apellido a variables temporales.
	char nombre[20]; strcpy(nombre, n);
	char apellidoPaterno[20]; strcpy(apellidoPaterno, ap);
  //Pasamos la primer letra del nombre a minusculas
    nombre[0] = tolower(nombre[0]);
  //Asignamos la primer letra del nombre a la primer letra del correo
	str[0] = nombre[0];
  //Asignamos TODAS las letras del apellido al correo. Note como el ciclo empieza en 1 y no en 0 porque nos estamos saltando la primer letra
	for (int i = 1; i < strlen(apellidoPaterno)+1; i++){
		str[i] = apellidoPaterno[i-1];
	}
  //La posicion en la que comenzaremos a introducir la fecha de nacimiento es igual a la longitud del apellido mas la primer letra del nombre
	int posicion = (strlen(apellidoPaterno)) + 1;	
  //Convertimos el anno de nacimiento a texto para poder extraer los ultimos dos digitos.
    char year[4];
	sprintf(year,"%d",y); 
  //Colocamos en la posicion correcta tercer digito del anno
	str[posicion] = year[2]; 
  //Colocamos en la posicion correcta el cuarto digito del anno
	str[posicion+1] = year[3]; 
  //Si el numero del mes es menor que 10 signfica que es de un solo digito y tenemos que anteponer un cero
	if (m < 10) { 
    //Convertimos el mes a texto
	    char month[1]; 
	    sprintf(month,"%d", m);
      //Anteponemos el cero
	    str[posicion+2] = '0';
      //Escribimos el digito del mes
	    str[posicion+3] = month[0];
	} else {
    //Si el numero del mes es igual o mayor a 10 significa que es de dos digitos y no tenemos que anteponer el cero
	    char month[2]; 
	    sprintf(month,"%d", m);
	    str[posicion+2] = month[0];
	    str[posicion+3] = month[1];
	}
  //Realizamos lo mismo con el dia para anteponer un cero en caso de que sea menor que 10
	if (d < 10) {
	    char day[1];
	    sprintf(day,"%d", d);
	    str[posicion+4] = '0';
	    str[posicion+5] = day[0];
	} else {
	    char day[2];
	    sprintf(day,"%d", d);
	    str[posicion+4] = day[0];
	    str[posicion+5] = day[1];
	}
  //Creamos el ultimo texto que ira al final del correo
	char final[] = "@itesm.mx";
  //Lo agregamos en la posicion correcta es decir (nombre+apellido+anno+mes+dia) = (posicion+2+2+2) = posicion + 6
	for (int i = 0; i < strlen(final); i++){
		str[(posicion+6)+i] = final[i];
	}
  //Convertimos el correo final a minusculas en caso de que el apellido contenga una.
	for (int i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
  //Delimitamos el final del correo con el siguiente caracter
	str[(posicion+6)+9] = '\0'; 
  //Generamos el correo final.
	return str;
}

//Esta funcion va a ejecutar el resto de las funciones de captura
void altasAlumnos() {
  //Introduci un limite arbitrario para la captura del anno de nacimiento
	int MaxAnno = 9999;
  //Limpiamos la pantalla
	system("cls");
	printf("Dar de Alta a Nuevo Alumno\n\n");
  //Aqui estamos creando las variables y usando las funciones de captura para guardar los datos correspondientes.
  //La validacion de cada dato se encuentra dentro de las funciones de captura
	char matricula[5]; snprintf(matricula, sizeof(matricula), "%s", obtenerMatricula());
	char nombre[20]; strcpy(nombre, obtenerNombre(matricula));
	char apellidoPaterno[20]; strcpy(apellidoPaterno, obtenerApellidoPaterno(matricula, nombre));
	char apellidoMaterno[20]; strcpy(apellidoMaterno, obtenerApellidoMaterno(matricula, nombre, apellidoPaterno));
	int diaNacimiento = obtenerDia(1, 31, matricula, nombre, apellidoPaterno, apellidoMaterno);
	int mesNacimiento = obtenerMes(1, 12, matricula, diaNacimiento, nombre, apellidoPaterno, apellidoMaterno);
	int annoNacimiento = obtenerAnno(1900, MaxAnno, matricula, diaNacimiento, mesNacimiento, nombre, apellidoPaterno, apellidoMaterno);
	float promedio = obtenerPromedio(0, 100, matricula, diaNacimiento, mesNacimiento, annoNacimiento, nombre, apellidoPaterno, apellidoMaterno);
	char claveCarrera[5]; strcpy(claveCarrera, obtenerCarrera(matricula, diaNacimiento, mesNacimiento, annoNacimiento, promedio, nombre, apellidoPaterno, apellidoMaterno));
	char correo[50]; strcpy(correo, obtenerCorreo(nombre, apellidoPaterno, diaNacimiento, mesNacimiento, annoNacimiento));
	//Si llegamos a este punto es que todas las variables fueron capturadas correctamente.
  //Abrimos el archivo de alumnos en modo de Escritura
  ofstream archivoAlumnos;
	archivoAlumnos.open("alumnos.txt", ios::app);
  //Escribimos los datos que acabamos de capturar como un nuevo registro
	archivoAlumnos << matricula << " " << nombre << " " << apellidoPaterno << " " << apellidoMaterno << " " << diaNacimiento << " " << mesNacimiento << " " << annoNacimiento << " " << promedio << " " << claveCarrera << " " << correo << "\n";
	archivoAlumnos.close(); //cerramos el archivo y limpiamos la pantalla.
	system("cls");
}

void imprimirMenu() {
	printf("\n");
	printf("1) Altas de alumnos \n");
	printf("2) Consulta de alumnos por matr%ccula \n", 161);
	printf("3) Consulta de alumnos por correo \n");
	printf("4) Listado de alumnos por apellido paterno \n");
	printf("5) Reporte de calificaciones de la universidad \n");
	printf("6) Reporte de calificaciones de una carrera \n");
	printf("7) Consulta de carreras por clave \n");
	printf("8) Listar todas las carreras \n");
	printf("9) Terminar \n");
	printf("\nOpcion: ");
}

//Esta funcion genera un numero que sera utilizado por el menu para ver que otra funcion se ejecuta
int seleccionarOpcionDelMenu() {
  //Establecemos los limites de las posibles funciones
	int opcionMinima = 1;
	int opcionMaxima = 9;
  //Imprimimos el menu para que el usuario pueda ver sus opciones
	imprimirMenu();
  //Lo que introdusca el usuario lo capturamos como texto no como numero
  //Esto es con la finalidad de que si el usuario introduce texto en vez de un numero podamos enviar un mensaje de error.
	string opcionDelUsuario; 
  //Capturamos lo que introdusca el usuario
	getline(cin, opcionDelUsuario);
  //Dado que las opciones van del 1 al 9 solo necesitamos el primer digito de lo que introdusca el usuario-
	char primerLetraDeOpcion = opcionDelUsuario.at(0);
  //Este primer digito sera valido como opcion del menu si es un digito numerico y si esta dentro del rango que habiamos establecido.
	bool opcionEsValida = ((isdigit(primerLetraDeOpcion)) && (atoi(opcionDelUsuario.c_str()) <= opcionMaxima) && (atoi(opcionDelUsuario.c_str()) >= opcionMinima));
	//Mientras el digito no sea valido seguira pidiendolo.
  while (!opcionEsValida) {
    //Enviar primer mensaje de error si el digito no es valido.
		error(1, opcionMinima, opcionMaxima);
    //Esperar dos segundos para que el usuario pueda leer el error.
		Sleep(2000);
    //Limpiar la ventana
		system("cls");
    //Imprimir un nuevo menu y volver a pedir la opcion del usuario.
		imprimirMenu();
		getline(cin, opcionDelUsuario);
		primerLetraDeOpcion = opcionDelUsuario.at(0);
		opcionEsValida = ((isdigit(primerLetraDeOpcion)) && (atoi(opcionDelUsuario.c_str()) <= opcionMaxima) && (atoi(opcionDelUsuario.c_str()) >= opcionMinima));
	}
  //Si llegamos a este punto es que porfin el usuario puso una opcion correcta, es decir un numero del 1 al 9
  //Para pasar este primer digito (Que sigue siendo texto) a un numero utilizamos la siguiente resta:
	int opcionFinal = (primerLetraDeOpcion - '0');
  //Finalmente generamos el numero
	return opcionFinal;
}

//Funcion principal del programa
int main() {
  //Creo una ventana grande para que quepan todos los datos de los alumnos.
	cambiarTamanoVentana(1250, 600);
  //Booleano que cambiara a verdadero cuando queramos salir del programa
	bool salirDelPrograma = false;
  //Numero que guardara la opcion del menu a ejecutar
	int ejecutarOpcion;
  //Mientras el booleano siga siendo falso, el programa nunca temrinara
	while (!salirDelPrograma) {
    //La opcion del usuario la genera la siguiente funcion y la guarda en el numero
		ejecutarOpcion = seleccionarOpcionDelMenu();
    //Dependiendo del numero guardado es la funcion del menu que se ejecuta.
		if (ejecutarOpcion == 1) { altasAlumnos(); } 
		else if (ejecutarOpcion == 2) { consultaMatricula(); } 
		else if (ejecutarOpcion == 3) { consultaCorreo(); } 
		else if (ejecutarOpcion == 4) { listaApellidoPaterno(); } 
		else if (ejecutarOpcion == 5) { reporteTodos(); } 
		else if (ejecutarOpcion == 6) { reporteCarrera(); } 
		else if (ejecutarOpcion == 7) { consultaCarrera(); } 
		else if (ejecutarOpcion == 8) { listaCarreras(); } 
		else if (ejecutarOpcion == 9) { salirDelPrograma = true; }
    //El booleano se vuelve verdadero justo cuando el usuario introduce el numero 9 como su opcion.
	}
}
