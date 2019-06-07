// ESTA VAINA DOCUMENTARLA BIEN
//*************************************************************************
//Autores: Guillermo Cruz (682433) y Miguel Gomez (741302)
//Fecha: 07/03/2019
//Fichero de interfaz arbol.h del TAD genérico arbol
//*************************************************************************
#include "monticulo.h"
#include <iostream>

using namespace std;

// Implementacion de las operaciones del TAD monticulo.

void crearVacia(mont& m) {
	m.total = 0;
	for(int i=0; i<maxNum; i++) {  //maxNum es el limite de elementos del vector
		crearArbol(m.dato[i]);
	}
}

bool esVacia(const mont& m) {
	return m.total==0;
}

int cardinal(mont& m){
  return m.total;
}

// Devuelve el elemento minimo o primero del monticulo
//Pre:  esVacia(m) = Falso
void min(const mont& m, arbol& a) {
  asignar(a, m.dato[0]);
}

bool insertarHoja(mont& m, const char& c, const int& f) { //Ojo cambiar esto en .h y en el main
	bool res=false;

	if(m.total != maxNum) {
		res=true;
    bool debeSubir;
    int i = m.total;
    m.total++;

    anyadirHoja(m.dato[i], c, f);

		if(i > 0) {
			debeSubir = esMenor(m.dato[i], m.dato[i/2]);
		}
		else { //i=0
			debeSubir = false;
		}

		while (debeSubir) {
      intercambiarCharYFrec(m.dato[i], m.dato[i/2]);

			i = i/2;
			if(i > 0) {
				debeSubir = esMenor(m.dato[i], m.dato[i/2]);
			}
			else { //i=0
				debeSubir = false;
			}
		}
	}

	return res;
}

bool insertarArbol(mont& m, const arbol& a) { //Ojo cambiar esto en .h y en el main
	bool res=false;

	if(m.total != maxNum) {
		res=true;
    bool debeSubir;
    int i = m.total;
    m.total++;

    asignar(m.dato[i], a);

		if(i > 0) {
			debeSubir = esMenor(m.dato[i], m.dato[i/2]);
		}
		else { //i=0
			debeSubir = false;
		}

		while (debeSubir) {
      intercambiarCharYFrec(m.dato[i], m.dato[i/2]);

			i = i/2;
			if(i > 0) {
				debeSubir = esMenor(m.dato[i], m.dato[i/2]);
			}
			else { //i=0
				debeSubir = false;
			}
		}
	}

	return res;
}

//Pre:  esVacia(m) = Falso
void borrarMin(mont& m) {
  if(m.total==1){ //Solo hay que borrar el unico elemento que existe, ningun cambio mas
    //borrarHoja(m.dato[m.total-1]);
    crearArbol(m.dato[m.total-1]); //Unicamente reseteamos este arbol, de borrar el nodo se encarga el main
  	m.total--;
  }
  else{ //Hay que reorganizar el monticulo
    intercambiarCharYFrec(m.dato[0], m.dato[m.total-1]);
    //borrarHoja(m.dato[m.total-1]);
    crearArbol(m.dato[m.total-1]); //Unicamente reseteamos este arbol, de borrar el nodo se encarga el main
  	m.total--;

  	int i = 0;
    int j;
  	while(i <= (m.total/2)) {
      if(2*i==m.total){  /* TENGO Q PONER ESTA CONDICION ANTES DEL esMenor!!!! pq si no segmentation */
        j = 2*i;   //hijo izquierdo
      }
      else{
        if(esMenor(m.dato[2*i], m.dato[2*i+1])) {
          j = 2*i;   //hijo izquierdo
        }
        else{
          j = 2*i+1;  //hijo derecho
        } //j=hijo de i con menor valor, o su unico hijo
      }

  		if (esMayor(m.dato[i], m.dato[j])) {
  			intercambiarCharYFrec(m.dato[i], m.dato[j]);
  			i = j;
  		}
  		else {
  			i = m.total; //para salir del bucle
  		}
  	}
  }
}

void pruebaInsertar(mont& m){
  char c; int f;
  for(int i=0; i<m.total; i++){
    getRaiz(m.dato[i], c, f);
    cout << c << ", " << f << endl;
  }
}
