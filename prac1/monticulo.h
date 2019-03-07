#ifndef MONTICULO_H
#define MONTICULO_H

#include <iostream>
using namespace std;

template<typename t> struct mont;

template<typename t> void crearVacia(mont<t>& m);

template<typename t> void insertar(const mont<t>& m, const T& d);

template<typename t> bool borrar(const mont<t>& m, const T& d);

template<typename t> bool min(const mont<t>& m);


template<typename t>
struct mont {
	friend void crearVacia();
	friend void insertar();
	friend bool borrar();
	friend bool min();

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

}

template<typename t> 
void insertar(const mont<t>& m, const T& d) {

}

template<typename t>
bool borrar(const mont<t>& m, const T& d) {

}

template<typename t>
bool min(const mont<t>& m) {
	
}


#endif
