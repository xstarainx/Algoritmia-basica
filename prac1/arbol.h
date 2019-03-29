//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>

template<typename C, typename F> struct arbol;

template<typename C, typename F> void crearHoja (arbol<C,F>& a, const C& c, const F& f);

template<typename C, typename F> void crearArbol (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der);

template<typename C, typename F>
struct arbol{
  friend void crearHoja<C,F> (arbol<C,F>& a, const C& c, const F& f);
  friend void crearArbol<C,F> (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der);

	private:	//declaracion de la representacion interna del tipo:
	struct Nodo{
			C elementoC;
      F elementoF;
			Nodo* h_der;
			Nodo* h_izq;
	};
	Nodo* raiz;
	//pila<Nodo*> iter;
};

template<typename C, typename F>
void crearHoja (arbol<C,F>& a, const C& c, const F& f){
  typename arbol<C,F>::Nodo* aux= new typename arbol<C,F>::Nodo;
  aux->elementoC = c;
  aux->elementoF = f;
	aux->h_der = NULL;
  aux->h_izq = NULL;
	a.raiz = aux;
	//a.iter = nullptr;
}

template<typename T>
void crearArbol (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der){
  typename arbol<C,F>::Nodo* aux= new typename arbol<C,F>::Nodo;
  aux->elementoC = c;
  aux->elementoF = f;
	aux->h_der = der;
  aux->h_izq = izq;
	a.raiz = aux;
	//a.iter = nullptr;
}
#endif
