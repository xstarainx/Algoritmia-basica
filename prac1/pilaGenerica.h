//*************************************************************************
//Autores: Guillermo Cruz (682433) y Lucía Cristóbal (764641)
//Fecha: 10/12/2018
//Fichero de interfaz pilaGenerica.h del TAD genérico recopilación
//*************************************************************************

#ifndef PILAGENERICA_H
#define PILAGENERICA_H

// Interfaz del TAD pila genérica. Pre-declaraciones:

//Los valores del TAD pila representan secuencias de elementos con
//acceso LIFO (last in, first out), esto es, el último elemento añadido
//será el primero en ser borrado.
template<typename T> struct pila;

//definir operaciones de pila

//Devuelve en <p> la pila vacía, sin elementos
template<typename T> void crearVacia (pila<T>& p);

//Devuelve en <p> la pila resultante de añadir <elemento> a <p>
template<typename T> void apilar (pila<T>& p, const T& elemento);

//Devuelve verdad si y sólo si <p> no tiene elementos
template<typename T> bool esVacia (const pila<T>& p);

//Si <p> es no vacía, devuelve en <elemento> el último elemento apilado en <p> y <error>=falso.
//Si <p> es vacía, devuelve <error>=verdad y <elemento> queda indefinido
template<typename T> void cima (const pila<T>& p, T& elemento, bool& error);

//Si <p> es no vacía, devuelve en <p> la pila resultante de eliminar de <p> el último
//elemento que fue apilado. Si <p> es vacía, la deja igual
template<typename T> void desapilar (pila<T>& p);

//Declaracion:
template<typename T>
struct pila{
	friend void crearVacia<T> (pila<T>& p);
	friend void apilar<T> (pila<T>& p, const T& elemento);
    friend bool esVacia<T> (const pila<T>& p);
    friend void cima<T> (const pila<T>& p, T& elemento, bool& error);
    friend void desapilar<T> (pila<T>& p);

  private:	//Declaracion de la representacion interna del tipo:
	struct UnDato{
		T dato;         //Elemento a almacenar en la pila
		UnDato* sig;    //Puntero que senyala al elemento anterior
	};

	UnDato* cima;       //Puntero que senyala al ultimo elemento anyadido a la pila
};

//Devuelve en <p> la pila vacía, sin elementos
template<typename T>
void crearVacia (pila<T>& p){
	p.cima=NULL;
}

//Devuelve en <p> la pila resultante de añadir <elemento> a <p>
template<typename T>
void apilar (pila<T>& p, const T& elemento){
	typename pila<T>::UnDato* nuevo= new typename pila<T>::UnDato;
	nuevo->dato = elemento;
	nuevo->sig = p.cima;
	p.cima = nuevo;
}

//Devuelve verdad si y sólo si <p> no tiene elementos
template<typename T>
bool esVacia (const pila<T>& p){
	return (p.cima==NULL);
}

//Si <p> es no vacía, devuelve en <elemento> el último elemento apilado en <p> y <error>=falso.
//Si <p> es vacía, devuelve <error>=verdad y <elemento> queda indefinido
template<typename T>
void cima (const pila<T>& p, T& elemento, bool& error){
	if(esVacia(p)){
	    error = true;
	}
	else{
	    error = false;
	    elemento = p.cima->dato;
	}
}

//Si <p> es no vacía, devuelve en <p> la pila resultante de eliminar de <p> el último
//elemento que fue apilado. Si <p> es vacía, la deja igual
template<typename T>
void desapilar (pila<T>& p){
	if(!esVacia(p)){
        typename pila<T>::UnDato* pAux = p.cima;
        p.cima = p.cima->sig;
        delete(pAux);
	}
}

#endif
