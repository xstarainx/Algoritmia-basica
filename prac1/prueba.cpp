/*
 * Fichero de prueba
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <queue>
#include "arbol.h"
#include "monticulo.h"


const int MAX_CHARS = 300;

using namespace std;


void funcHuffman(map<char,int> tabla_frec) {
	mont<arbol <char,int> > cola;
	int i,fx,fy,fz;
	arbol<char,int> z,x,y;

	//crearVacia(cola);

	map<char, int>::iterator it;
	for ( it = tabla_frec.begin(); it != tabla_frec.end(); it++) {
		char caracter = it->first;
		int frecuencia = it->second;
		
		crearHoja(x,caracter,frecuencia);
		
		//insertar(cola, x);

    	cout << "Insertando: "<< caracter << " : " << frecuencia << endl ;
	}

}


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
		map<char,int> tabla_frec;
		//Recorrido del fichero contando apariciones
		while(!f.eof()) {
			c = f.get();
			tabla_frec[c] += 1;
		}

		f.close();

		/*
		//Iterador que muestra la tabla de frecuencias
		map<char, int>::iterator it;
		for ( it = tabla_frec.begin(); it != tabla_frec.end(); it++) {
    		std::cout << it->first << ':'<< it->second << std::endl ;
		}
		*/
		funcHuffman(tabla_frec);
		
	}
	else {
		cout << "Error al abrir el fichero o nombre de fichero incorrecto" << nom_fich << endl;
	}


}
