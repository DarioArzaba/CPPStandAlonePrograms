/*Genera un documento de texto y 
Escribe una serie de numeros utilizando un ciclo For.*/

#include <fstream>
#include <string>
using namespace std;

int main() {

int i;
int numeroIteraciones = 10;

ofstream outputFile;
outputFile.open("ArchivoDeTexto.txt");
    
if(outputFile.is_open()) {
								
	for (i = 1; i <= numeroIteraciones; i++)			
	{
		outputFile<<i<<"\n";		 
	}

}

outputFile.close();
return 0;
}
