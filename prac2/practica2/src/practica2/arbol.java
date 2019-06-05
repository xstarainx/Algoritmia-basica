package practica2;

public class arbol {
	public arbol izq, der;		// Hijos izquierdo y derecho
	public arbol padre;			// Arbol padre
	public Pedido p;			// Pedido
	public int total;			
	public boolean es;			// True si izq, false si der
			
	
	// Constructor vacio
	public arbol() {}
	
	// Constructor con parametros
	public arbol(arbol _padre, Pedido _p, boolean _es) {
		this.padre = _padre;
		this.p = _p;
		this.es = _es;
	}
	
	// Actualizar pedido
	public void setPedido(Pedido _p) {
		this.p = _p;
	}
	
	// Actualizar hijo izquierdo
	public void setIzq(arbol _izq) {
		this.izq = _izq;
	}
	
	// Actualizar hijo derecho
	public void setDer(arbol _der) {
		this.der = _der;
	}
	
	// Obtener hijo izquierdo
	public arbol getIzq() {
		return this.izq;
	}
	
	// Obtener hijo derecho
	public arbol getDer() {
		return this.der;
	}
	
	public int printPas() {
		return p.getPasajeros();
	}
}
