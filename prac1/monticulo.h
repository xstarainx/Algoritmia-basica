#ifndef MONTICULO_H
#define MONTICULO_H

#include <iostream>
#include "arbol.h"
using namespace std;

const int maxNum = 256;

struct mont;

void crearVacia(mont& m);

bool esVacia(const mont& m);

bool insertar(mont& m, const arbol& d);

bool borrar(mont& m);

bool min(const mont& m, arbol& minimo);

int recorrer(const mont& m);

struct mont {
	friend void crearVacia(mont& m);
	friend bool esVacia(const mont& m);
	friend bool insertar(mont& m, const arbol& d);
	friend bool borrar(mont& m);
	friend bool min(const mont& m, arbol& minimo);
	friend int recorrer(const mont& m);

private:
	arbol dato[maxNum];
	unsigned int total;
};

void crearVacia(mont& m) {
	m.total = 0;
	for(int i=0; i<maxNum; i++) {
		crearArbol(m.dato[i]);
	}
}

bool esVacia(const mont& m) {
	if(m.total == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool insertar(mont& m, const arbol& d) {
	bool res=false;
	int i;
	bool debeSubir;
	arbol aux;
	crearArbol(aux);

	if(m.total != maxNum) {
		res=true;
		asignar(m.dato[m.total], d);
		i = m.total;
		m.total++;
		if(i > 0) {
			debeSubir = esMenor(m.dato[i], m.dato[i/2]);
		}
		else {
			debeSubir = false;
		}
		while (debeSubir) {
			asignar(aux, m.dato[i]);
			asignar(m.dato[i], m.dato[i/2]);
			asignar(m.dato[i/2], aux);
			i = i/2;
			if(i > 0) {
				debeSubir = esMenor(m.dato[i], m.dato[i/2]);
			}
			else {
				debeSubir = false;
			}
		}
	}
	//vaciarArbol(aux); IMPORTANTE!!!
	return res;
}

bool borrar(mont& m) {
	int i,j;
	arbol aux;
	crearArbol(aux);
	asignar(m.dato[0], m.dato[m.total]);
	m.total--;
	i = 1;
	while(i <= (m.total/2)) {
		if(esMenor(m.dato[2*i], m.dato[2*i+1]) || (2*i == m.total)) {
			j = 2*i+1;
		}
		if (esMayor(m.dato[i], m.dato[j])) {
			asignar(aux, m.dato[i]);
			asignar(m.dato[i],  m.dato[j]);
			asignar(m.dato[j], aux);
			i = j;
		}
		else {
			i = m.total;
		}
	}
	//vaciarArbol(aux); IMPORTANTE!!!
}

// Devuelve el elemento minimo o primero del monticulo
bool min(const mont& m, arbol& minimo) {
	if(!esVacia(m)) {
		//minimo = m.dato[0];
		asignar(minimo, m.dato[0]);
		return true;
	}
	else {
		return false;
	}
}

int recorrer(const mont& m){
	int tot=0;
	char c; int f;
	for(int i=0; i<maxNum; i++){
		if(getRaiz(m.dato[i],c,f)){
			cout << c << " --- " << f << endl;
			tot++;
		}
	}
	return tot;
}

#endif
