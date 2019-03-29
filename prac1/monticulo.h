#ifndef MONtICULO_H
#define MONtICULO_H

#include <iostream>
#include "arbol.h"
using namespace std;

template<typename t> struct mont;

template<typename t> void crearVacia(mont<t>& m);

template<typename t> bool esVacia(const mont<t>& m);

template<typename t> void insertar(const mont<t>& m, const t& d);

template<typename t> bool borrar(const mont<t>& m, const t& d);

template<typename t> bool min(const mont<t>& m);


template<typename t>
struct mont {
	friend void crearVacia<t>(mont<t>& m);
	friend bool esVacia<t>(const mont<t>& m);
	friend void insertar<t>(const mont<t>& m, const t& d);
	friend bool borrar<t>(const mont<t>& m, const t& d);
	friend bool min<t>(const mont<t>& m);

private:
	struct Nodo{
		t dato;
		Nodo* izq;
		Nodo* der;
	};
	unsigned int total;
	Nodo* raiz;
	
};



template<typename t> 
void crearVacia(mont<t>& m) {
	m.total = 0;
	m.raiz = NULL;
}


template<typename t>
bool esVacia(const mont<t>& m) {
	if(m.total == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename t> 
void insertar(const mont<t>& m, const t& d) {
	int i;
	bool debeSubir;
	t aux;
	m.total++;
	

}

template<typename t>
bool borrar(const mont<t>& m, const t& d) {

}

// Devuelve el elemento minimo o primero del monticulo
template<typename t>
bool min(const mont<t>& m, t minimo) {
	if(!esVacia(m)) {
		minimo = m.raiz;
		return true;
	}
	else {
		return false;
	}
}


#endif
