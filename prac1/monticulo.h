// ESTA VAINA DOCUMENTARLA BIEN
//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************
#ifndef MONTICULO_H
#define MONTICULO_H

#include "arbol.h"

using namespace std;

const int maxNum = 256;
struct mont;

// TODO ESTO HABRA Q ESPECIFICARLO
void crearVacia(mont& m);
bool esVacia(const mont& m);
int cardinal(mont& m);
bool insertarHoja(mont& m, const char& c, const int& f);
bool insertarArbol(mont& m, const arbol& a);
void borrarMin(mont& m);
void min(const mont& m, arbol& a);
void pruebaInsertar(mont& m);

struct mont {
	friend void crearVacia(mont& m);
	friend bool esVacia(const mont& m);
	friend int cardinal(mont& m);
	friend bool insertarHoja(mont& m, const char& c, const int& f);
	friend bool insertarArbol(mont& m, const arbol& a);
	friend void borrarMin(mont& m);
	friend void min(const mont& m, arbol& a);
	friend void pruebaInsertar(mont& m);

private:
	arbol dato[maxNum];
	unsigned int total;
};

#endif
