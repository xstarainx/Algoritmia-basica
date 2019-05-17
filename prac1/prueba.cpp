/*
 * Fichero de prueba
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include "arbol.h"
#include "monticulo.h"


const int MAX_CHARS = 300;

using namespace std;


/*void funcHuffman(map<char,int>tabla_frec) {
	mont<arbol> cola;
	int i,fx,fy,fz;
	//arbol z,x,y;

	crearVacia(cola);

}*/


int main(int argc, char *argv[]) {
	arbol<char, int> a;
	arbol<char, int> c;
	arbol<char, int> b;
	arbol<char, int> f;
	arbol<char, int> e;
	arbol<char, int> d;
	crearHoja(a, 'a', 45);
	crearHoja(c, 'c', 12);
	crearHoja(b, 'b', 13);
	crearHoja(f, 'f', 5);
	crearHoja(e, 'e', 9);
	crearHoja(d, 'd', 16);

	arbol<char, int> aa;
	crearArbol(aa, '\0', 14, f, e);

	arbol<char, int> ab;
	crearArbol(ab, '\0', 30, aa, d);

	arbol<char, int> bb;
	crearArbol(bb, '\0', 25, c, b);

	arbol<char, int> cc;
	crearArbol(cc, '\0', 55, bb, ab);

	arbol<char, int> fin;
	crearArbol(fin, '\0', 100, a, cc);

	//Si el numero de parametros es incorrecto indicar y finalizar
	/*if (argc != 2) {
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

		//Iterador que muestra la tabla de frecuencias
		map<char, int>::iterator it;
		for ( it = tabla_frec.begin(); it != tabla_frec.end(); it++) {
    		std::cout << it->first << ':'<< it->second << std::endl ;
		}

		funcHuffman(tabla_frec);

	}
	else {
		cout << "Error al abrir el fichero o nombre de fichero incorrecto" << nom_fich << endl;
	}*/


}
