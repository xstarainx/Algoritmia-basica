//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>

template<typename T> struct arbol;

template<typename T> void crearHoja (arbol<T>& a, const T& elem);

template<typename T> void crearArbol (arbol<T>& a, const T& elem, const arbol<T>& izq, const arbol<T>& der);

template<typename T>
struct arbol{
  friend void crearHoja<T> (arbol<T>& a, const T& elem);
  friend void crearArbol<T> (arbol<T>& a, const T& elem, const arbol<T>& izq, const arbol<T>& der);

	private:	//declaracion de la representacion interna del tipo:
	struct Nodo{
			T elemento;
			Nodo* h_der;
			Nodo* h_izq;
	};
	Nodo* raiz;
	//pila<Nodo*> iter;
};

template<typename T>
void crearHoja (arbol<T>& a, const T& elem){
  typename arbol<T>::Nodo* aux= new typename arbol<T>::Nodo;
  aux->elemento = elem;
	aux->h_der = nullptr;
  aux->h_izq = nullptr;
	a.raiz = aux;
	a.iter = nullptr;
}

template<typename T>
void crearArbol (arbol<T>& a, const T& elem, const arbol<T>& izq, const arbol<T>& der){
  typename arbol<T>::Nodo* aux= new typename arbol<T>::Nodo;
  aux->elemento = elem;
	aux->h_der = der;
  aux->h_izq = izq;
	a.raiz = aux;
	a.iter = nullptr;
}
#endif
