#ifndef MONtICULO_H
#define MONtICULO_H

#include <iostream>
#include "arbol.h"
using namespace std;

const int maxNum = 256;

template<typename t> struct mont;

template<typename t> void crearVacia(mont<t>& m);

template<typename t> bool esVacia(const mont<t>& m);

template<typename t> bool insertar(const mont<t>& m, const t& d);

template<typename t> bool borrar(const mont<t>& m, const t& d);

template<typename t> bool min(const mont<t>& m);


template<typename t>
struct mont {
	friend void crearVacia<t>(mont<t>& m);
	friend bool esVacia<t>(const mont<t>& m);
	friend bool insertar<t>(const mont<t>& m, const t& d);
	friend bool borrar<t>(const mont<t>& m, const t& d);
	friend bool min<t>(const mont<t>& m);

private:
	t dato[maxNum];
	unsigned int total;
};



template<typename t> 
void crearVacia(mont<t>& m) {
	m.total = 0;
	for (int i=0; i<maxNum; ++i) {
		m.dato[i] = '\0';
	}
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
bool insertar(const mont<t>& m, const t& d) {
	int i;
	bool debeSubir;
	t aux;

	if(m.total==maxNum) {
		return false;
	}
	else {
		m.total++;
		m.dato[m.total] = d;
		i = m.total;
		if(i > 1) {
			debeSubir = m.dato[i]<m.dato[i/2];
		}
		else {
			debeSubir = false;
		}
		while (i > 1) {
			aux = m.dato[i];
			m.dato[i] = m.dato[i/2];
			m.dato[i/2] = aux;
			i = i/2;
			if(i > 1) {
				debeSubir = m.dato[i]<m.dato[i/2];
			}
			else {
				debeSubir = false;
			}
		}
	}
}

template<typename t>
bool borrar(const mont<t>& m, const t& d) {
	int i,j;
	t aux;
	m.dato[0] = m.dato[m.total];
	m.total--;
	i = 1;
	while(i <= (m.total/2)) {
		if(m.dato[2*i] < m.dato [2*i+1] || (2*i == m.total)) {
			j = 2*i+1;
		}
		if (m.dato[i] > m.dato[j]) {
			aux = m.dato[i];
			m.dato[i] = m.dato[j];
			m.dato[j] = aux;
			i = j;
		}
		else {
			i = m.total;
		}
	}
}

// Devuelve el elemento minimo o primero del monticulo
template<typename t>
bool min(const mont<t>& m, t minimo) {
	if(!esVacia(m)) {
		minimo = m.dato[0];
		return true;
	}
	else {
		return false;
	}
}


#endif
