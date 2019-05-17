//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************

#ifndef ARBOL_H
#define ARBOL_H

#include "pilaGenerica.h"

template<typename C, typename F> struct arbol;

template<typename C, typename F> void crearHoja (arbol<C,F>& a, const C& c, const F& f);

template<typename C, typename F> void crearArbol (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der);

//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
template<typename C, typename F> void iniciarIterador (arbol<C,F>& a);

//Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario
template<typename C, typename F> bool existeSiguiente (const arbol<C,F>& a);

//Asigna a <c>, <v> y <m> la clave, valor y marca respectivamente del elemento visitado y avanza el iterador de <d>
//Parcial: la operación no está definida si not existeSiguiente?(d).
template<typename C, typename F> bool siguienteYAvanza (arbol<C,F>& a, C& c);

template<typename C, typename F>
struct arbol{
  friend void crearHoja<C,F> (arbol<C,F>& a, const C& c, const F& f);
  friend void crearArbol<C,F> (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der);
  friend void iniciarIterador<C,F> (arbol<C,F>& a);
  friend bool existeSiguiente<C,F> (const arbol<C,F>& a);
  friend bool siguienteYAvanza<C,F> (arbol<C,F>& a, C& c);

	private:	//declaracion de la representacion interna del tipo:
	struct Nodo{
			C elementoC;
      F elementoF;
			Nodo* h_der;
			Nodo* h_izq;
	};
	Nodo* raiz;
	pila<Nodo*> iter;
  std::string codificacion;
};

template<typename C, typename F>
void crearHoja (arbol<C,F>& a, const C& c, const F& f){
  typename arbol<C,F>::Nodo* aux= new typename arbol<C,F>::Nodo;
  aux->elementoC = c;
  aux->elementoF = f;
	aux->h_der = NULL;
  aux->h_izq = NULL;
	a.raiz = aux;
}

template<typename C, typename F>
void crearArbol (arbol<C,F>& a, const C& c, const F& f, const arbol<C,F>& izq, const arbol<C,F>& der){
  typename arbol<C,F>::Nodo* aux= new typename arbol<C,F>::Nodo;
  aux->elementoC = c;
  aux->elementoF = f;
	aux->h_der = der;
  aux->h_izq = izq;
	a.raiz = aux;
  a.codificacion = "";
}

//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
template<typename C, typename F>
void iniciarIterador (arbol<C,F>& a){
	crearVacia(a.iter);
	typename arbol<C,F>::Nodo* pAux = a.raiz;
	while(pAux != NULL){
		apilar(a.iter,pAux);
		pAux = pAux->h_izq;
    a.codificacion = a.codificacion +"0";
	}
}

//Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario
template<typename C, typename F>
bool existeSiguiente (const arbol<C,F>& a){
	return !esVacia(a.iter);
}

//Asigna a <c>, <v> y <m> la clave, valor y marca respectivamente del elemento visitado y avanza el iterador de <d>
//Parcial: la operación no está definida si not existeSiguiente?(d).
template<typename C, typename F>
bool siguienteYAvanza (arbol<C,F>& a, C& c){
    bool res = true;
    bool error = false;
    if(!esVacia(a.iter) && !error){
        res = false;
        typename arbol<C,F>::Nodo* pAux;
        cima(a.iter,pAux,error);

        if(!error){
	        desapilar(a.iter);
	        c = pAux->elementoC;
	        pAux = pAux->h_der;
          a.codificacion = (a.codificacion).substr(0, a.length()-1);

	        while(pAux != NULL){
	            apilar(a.iter, pAux);
	            pAux = pAux->h_izq;
              a.codificacion = a.codificacion +"1";
	        }
	    }
    }
    return res;
}
#endif
