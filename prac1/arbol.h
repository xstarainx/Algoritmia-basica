//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************
#ifndef ARBOL_H
#define ARBOL_H
#include <string>
#include <map>
#include "pilaGenerica.h"

struct arbol;

// TODO ESTO HABRA Q ESPECIFICARLO
void crearArbol(arbol& a);
bool esVacio(const arbol& a);
void anyadirHoja(arbol& a, const char& c, const int& f);
void borrarHoja (arbol& a);
void juntarArboles (arbol& r, const arbol& hijoIzq, const arbol& hijoDer);
void agregarHijoIzq (arbol& r, arbol& hijoIzq);
void agregarHijoDer (arbol& r, arbol& hijoDer);
void setF (arbol& z, const int& f);
bool esMayor(const arbol& a, const arbol& b);
bool esMenor(const arbol& a, const arbol& b);
bool getRaiz(const arbol& a, char& c, int& f);
void getF(const arbol& a, int& f);
void getC(const arbol& a, char& c);
void intercambiarCharYFrec(arbol& a, arbol&b);
void asignar(arbol& a, const arbol& b);
//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
void codificar(const arbol& a, std::map<char, std::string>& tabla_cod);
/*//Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario
bool existeSiguiente (const arbol& a);
//Asigna a <c>, <v> y <m> la clave, valor y marca respectivamente del elemento visitado y avanza el iterador de <d>
//Parcial: la operación no está definida si not existeSiguiente?(d).
bool siguienteYAvanza (arbol& a, char& c);*/

struct arbol{
  friend void crearArbol(arbol& a);
  friend bool esVacio(const arbol& a);
  friend void anyadirHoja(arbol& a, const char& c, const int& f);
  friend void borrarHoja (arbol& a);
  friend void juntarArboles (arbol& r, const arbol& hijoIzq, const arbol& hijoDer);
  friend void agregarHijoIzq (arbol& r, arbol& hijoIzq);
  friend void agregarHijoDer (arbol& r, arbol& hijoDer);
  friend void setF (arbol& z, const int& f);
  friend bool esMayor(const arbol& a, const arbol& b);
  friend bool esMenor(const arbol& a, const arbol& b);
  friend bool getRaiz(const arbol& a, char& c, int& f);
  friend void getF(const arbol& a, int& f);
  friend void getC(const arbol& a, char& c);
  friend void intercambiarCharYFrec(arbol& a, arbol&b);
  friend void asignar(arbol& a, const arbol& b);
  ///////////////////////ITERADOR//////////////////////////////
  friend void codificar(const arbol& a, std::map<char, std::string>& tabla_cod);
  //friend void codificarAux(typename arbol::Nodo* a, std::map<char, std::string>& tabla_cod, std::string cod);
  /*friend bool existeSiguiente(const arbol& a);
  friend bool siguienteYAvanza(arbol& a, char& c);*/

	private:	//declaracion de la representacion interna del tipo:
	struct Nodo{
			char c;
      int f;
			Nodo* h_der;
			Nodo* h_izq;
	};
	Nodo* raiz;

  friend void codificarAux(typename arbol::Nodo* a, std::map<char, std::string>& tabla_cod, std::string cod);
};

void codificarAux(typename arbol::Nodo* a, std::map<char, std::string>& tabla_cod, std::string cod);
//void codificarAux(typename arbol::Nodo* a, std::map<char, std::string>& tabla_cod, std::string cod);

#endif
