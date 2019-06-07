// ESTA VAINA DOCUMENTARLA BIEN
//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************
#include "arbol.h"
#include <iostream>

using namespace std;

// Implementacion de las operaciones del TAD arbol.

void crearArbol(arbol& a){
  a.raiz = nullptr;
}

bool esVacio(const arbol& a){
  bool res=false;
  if(a.raiz==nullptr){
    res=true;
  }
  return res;
}

void anyadirHoja (arbol& a, const char& c, const int& f){
  typename arbol::Nodo* aux= new typename arbol::Nodo;
  aux->c = c;
  aux->f = f;
	aux->h_der = nullptr;
  aux->h_izq = nullptr;
	a.raiz = aux;
}

void borrarHoja (arbol& a){
  delete(a.raiz);
  a.raiz=nullptr;
}

void juntarArboles (arbol& r, const arbol& hijoIzq, const arbol& hijoDer){
  r.raiz->h_izq = hijoIzq.raiz;
  r.raiz->h_der = hijoDer.raiz;
  /*cout << r.raiz->f << endl;
  cout << r.raiz->h_izq->f << endl;
  cout << r.raiz->h_der->f << endl;*/
}

void agregarHijoIzq (arbol& r, arbol& hijoIzq){
  r.raiz->h_izq = hijoIzq.raiz;
}

void agregarHijoDer (arbol& r, arbol& hijoDer){
  r.raiz->h_der = hijoDer.raiz;
}

void setF (arbol& z, const int& f){
  z.raiz->f = f;
}

bool esMayor(const arbol& a, const arbol& b){
  bool res=true;
  if(b.raiz==nullptr){  //necesario para que no de segmentation fault
    res=false;
  }
  else if((a.raiz->f) <= (b.raiz->f)){
    res=false;
  }
  return res;
}

bool esMenor(const arbol& a, const arbol& b){
  bool res=true;
  if((b.raiz!=nullptr) && ((a.raiz->f) >= (b.raiz->f))){
    res=false;
  }
  return res;
}

bool getRaiz(const arbol& a, char& c, int& f){
  bool res=false;
  if(a.raiz!=nullptr){
    c=a.raiz->c;
    f=a.raiz->f;
    //cout << c << ", " << f << endl;
    res=true;
  }
  return res;
}

//Pre:  esVacio(a) = Falso
void getF(const arbol& a, int& f){
    f=a.raiz->f;
}

//Pre:  esVacio(a) = Falso
void getC(const arbol& a, char& c){
  //if(c=='\0'){
    //c='f';
  //}
  //else{
    c=a.raiz->c;
  //}
}

void intercambiarCharYFrec(arbol& a, arbol&b){
  if(a.raiz!=nullptr && b.raiz!=nullptr){
    /*cout << "------------------------------" << endl;
    cout << a.raiz->c << ",,, " << a.raiz->f << endl;
    cout << b.raiz->c << ",,, " << b.raiz->f << endl;
    cout << "------------------------------" << endl;*/
    arbol::Nodo* aux = a.raiz;
    a.raiz=b.raiz;
    b.raiz=aux;
    /*char cAux = a.raiz->c;
    int fAux = a.raiz->f;
    a.raiz->c = b.raiz->c;
    a.raiz->f = b.raiz->f;
    b.raiz->c = cAux;
    b.raiz->f = fAux;*/
  }
}

void asignar(arbol& a, const arbol& b){
  a.raiz=b.raiz;
}

//OPERACIONES DEL ITERADOR:
//Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la colecciónConMarca d (situación de no
//haber visitado ningún elemento).
void codificarAux(typename arbol::Nodo* a, std::map<char, std::string>& tabla_cod, std::string cod){
  if((a->h_izq==nullptr) && (a->h_der==nullptr)){
    tabla_cod[a->c] = cod;
  }
  else{
    cod = cod + "0";
    codificarAux(a->h_izq, tabla_cod, cod);
    cod = (cod).substr(0, cod.length()-1);
    cod = cod + "1";
    codificarAux(a->h_der, tabla_cod, cod);
    cod = (cod).substr(0, cod.length()-1);
  }
}

void codificar(const arbol& a, std::map<char, std::string>& tabla_cod){
  typename arbol::Nodo* pAux = a.raiz;

  codificarAux(pAux, tabla_cod, "");




  /*pila<typename arbol::Nodo*> p;
  bool error;
  bool sube = false;
  string cod = "";
  char c;
  typename arbol::Nodo* pAux = a.raiz;

	crearVacia(p);

	while(pAux != nullptr){
		apilar(p, pAux);
		pAux = pAux->h_izq;
    if(pAux!=nullptr){
      cod = cod + "0";
    }
	}

  while(!esVacia(p)){
    if(sube){
      cod = (cod).substr(0, cod.length()-1);
      sube=false;
    }
    cima(p, pAux, error);
    desapilar(p);
    if(pAux->c!='\0'){
      tabla_cod[pAux->c] = cod;
    }

    pAux = pAux->h_der;
    if(pAux!=nullptr){
      cod = cod + "1";
    }
    else{
      sube=true;
    }

    while(pAux != nullptr){
      //getC(pAux, c);
  		apilar(p, pAux);
  		pAux = pAux->h_izq;
      if(pAux!=nullptr){
        cod = cod + "0";
      }
  	}
  }*/
}
