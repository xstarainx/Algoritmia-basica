//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************

#ifndef ARBOL_H
#define ARBOL_H

#include "pilaGenerica.h"

struct arbol;

void crearArbol(arbol& a);

bool esVacio(const arbol& a);

void anyadirHoja(arbol& a, const char& c, const int& f);

void juntarArboles(arbol& a, arbol& b, arbol& c);

bool esMayor(const arbol& a, const arbol& b);

bool esMenor(const arbol& a, const arbol& b);

void asignar(arbol& a, const arbol& b);

bool getRaiz(const arbol& a, char& c, int& f);

//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
void iniciarIterador (arbol& a);

//Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario
bool existeSiguiente (const arbol& a);

//Asigna a <c>, <v> y <m> la clave, valor y marca respectivamente del elemento visitado y avanza el iterador de <d>
//Parcial: la operación no está definida si not existeSiguiente?(d).
bool siguienteYAvanza (arbol& a, char& c);

struct arbol{
  friend void crearArbol(arbol& a);
  friend bool esVacio(const arbol& a);
  friend void anyadirHoja(arbol& a, const char& c, const int& f);
  friend void juntarArboles(arbol& a, arbol& b, arbol& c);
  friend bool esMayor(const arbol& a, const arbol& b);
  friend bool esMenor(const arbol& a, const arbol& b);
  friend void asignar(arbol& a, const arbol& b);
  friend bool getRaiz(const arbol& a, char& c, int& f);

  friend void iniciarIterador(arbol& a);
  friend bool existeSiguiente(const arbol& a);
  friend bool siguienteYAvanza(arbol& a, char& c);

	private:	//declaracion de la representacion interna del tipo:
	struct Nodo{
			char c;
      int f;
			Nodo* h_der;
			Nodo* h_izq;
	};
	Nodo* raiz;
	pila<Nodo*> iter;
  std::string codificacion;
};

void crearArbol(arbol& a){
  a.raiz = NULL;
  a.codificacion="";
}

bool esVacio(const arbol& a){
  bool res=false;
  if(a.raiz==NULL){
    res=true;
  }
  return res;
}

void anyadirHoja (arbol& a, const char& c, const int& f){
  typename arbol::Nodo* aux= new typename arbol::Nodo;
  aux->c = c;
  aux->f = f;
	aux->h_der = NULL;
  aux->h_izq = NULL;
	a.raiz = aux;
}

void juntarArboles (arbol& a, arbol& b, arbol& c){
  c.raiz->f=(a.raiz->f) + (b.raiz->f);
  c.raiz->c='\0';
  if((a.raiz->f) >= (b.raiz->f)){
    c.raiz->h_der=b.raiz;  //El hijo derecho es el de menor frecuencia
    c.raiz->h_izq=a.raiz;
  }
  else{
    c.raiz->h_der=a.raiz;
    c.raiz->h_izq=b.raiz;
  }
}

bool esMayor(const arbol& a, const arbol& b){
  bool res=true;
  if((a.raiz->f) <= (b.raiz->f)){
    res=false;
  }
  return res;
}

bool esMenor(const arbol& a, const arbol& b){
  bool res=true;
  if((a.raiz->f) >= (b.raiz->f)){
    res=false;
  }
  return res;
}

void asignar(arbol& a, const arbol& b){
  if(b.raiz==NULL){
    std::cout << "ARBOL VACIO" << std::endl;
  }
  a.raiz=b.raiz;
}

bool getRaiz(const arbol& a, char& c, int& f){
  bool res=false;
  if(a.raiz!=NULL){
    c=a.raiz->c;
    f=a.raiz->f;
    res=true;
  }
  return res;
}

//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
/*void iniciarIterador (arbol& a){
	crearVacia(a.iter);
	typename arbol<C,F>::Nodo* pAux = a.raiz;
	while(pAux != NULL){
		apilar(a.iter,pAux);
		pAux = pAux->h_izq;
    a.codificacion = a.codificacion +"0";
	}
}

//Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario
bool existeSiguiente (const arbol& a){
	return !esVacia(a.iter);
}

//Asigna a <c>, <v> y <m> la clave, valor y marca respectivamente del elemento visitado y avanza el iterador de <d>
//Parcial: la operación no está definida si not existeSiguiente?(d).
bool siguienteYAvanza (arbol& a, char& c){
    bool res = true;
    bool error = false;
    if(!esVacia(a.iter) && !error){
        res = false;
        typename arbol<C,F>::Nodo* pAux;
        cima(a.iter,pAux,error);

        if(!error){
	        desapilar(a.iter);
	        c = pAux->c;
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
}*/
#endif
