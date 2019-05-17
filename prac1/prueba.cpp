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
	mont cola;
	int i,fx,fy,fz;
	arbol z,x,y;

	crearVacia(cola);

	map<char, int>::iterator it;
	char caracter;
	int frecuencia;
	crearArbol(x);
	int total=0;
	for( it = tabla_frec.begin(); it != tabla_frec.end(); it++) {
		caracter = it->first;
		frecuencia = it->second;
		anyadirHoja(x,caracter,frecuencia);
		insertar(cola,x);
		total++;
    //cout << "Insertando: "<< caracter << " : " << frecuencia << endl;
	}

	cout << "Total caracteres: " << total << endl;
	int metidos=recorrer(cola); //Probando si esto va bien
	cout << "Total metidos: " << metidos << endl;

	while(min(cola, x)){
		if(getRaiz(x,caracter,frecuencia)){
			cout << "Frecuencia: " << frecuencia << ", caracter: " << caracter << endl;
		}
		else{
			cout << "ERROR" << endl;
		}
		borrar(cola);
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
	f.open(nom_fich);

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

		/*//Iterador que muestra la tabla de frecuencias
		map<char, int>::iterator it;
		for ( it = tabla_frec.begin(); it != tabla_frec.end(); it++) {
    		cout << it->first << ':'<< it->second << endl ;
		}*/

		funcHuffman(tabla_frec);
	}
	else {
		cout << "Error al abrir el fichero o nombre de fichero incorrecto " << nom_fich << endl;
	}
}
