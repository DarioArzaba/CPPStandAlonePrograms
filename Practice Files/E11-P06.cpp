/*
Escriba y comente el siguiente codigo:
*/

# include <stdio.h>  //Importar libreria estandar de input y output
int i;               //Crear variable de tipo int y nombre (i)

//Primer funcion crea su variable local (i) y la inicia con (1)
void uno() {
	int i; 
	i = 1;	
}

//Segunda funcion crea su variable local (i) y la inicia con (2)
void dos() {
	int i; 
	i = 2;
}
//La funcion (main) inicia la variable global con (10).
//El valor de (i) es (10) porque la funcion printf solo tiene acceso a la variable global.
//Si la funcion printf se encontrara dentro de las funciones entonces escribiria el valor de las variables locales.
void main() {
	i = 10;
	uno();
	dos();
        printf("El valor final de I es: %d", i);
}
