/*
 * Fichero de prueba
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>

const int MAX_CHARS = 300;

using namespace std;

int main(int argc, char *argv[]) {
	//Si el numero de parametros es incorrecto indicar y finalizar
	if (argc != 2) {
		cout << "Numero de parametros incorrecto" << endl;
		exit(0);
	}
    //PRUEBA
	string nom_fich = argv[1];

	ifstream f;		//Flujo de entrada
	ofstream f2;	//Flujo de salida

	f.open(argv[1]);

	if (f.is_open()) {
		cout << "Abierto correctamente" << endl;

		char c;
		map<char,int> tabla;
		//Recorrido del fichero contando apariciones
		while(!f.eof()) {
			c = f.get();
			tabla[c] += 1;
		}

		
		//Iterador que muestra la tabla de frecuencias
		map<char, int>::iterator it;
		for ( it = tabla.begin(); it != tabla.end(); it++) {
    		std::cout << it->first << ':'<< it->second << std::endl ;
		}
		


		f.close();
	}
	else {
		cout << "Error al abrir el fichero o nombre de fichero incorrecto" << nom_fich << endl;
	}


}
