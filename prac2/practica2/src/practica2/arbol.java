package practica2;

public class arbol {
	public arbol izq, der;
	public arbol padre;
	public Pedido p;
	public int total;
	public boolean es;	// True si izq, false si der
		
	
	
	public arbol() {}
	
	public arbol(arbol _padre, Pedido _p, boolean _es) {
		this.padre = _padre;
		this.p = _p;
		this.es = _es;
	}
	
	public void setPedido(Pedido _p) {
		this.p = _p;
	}
	
	public void setIzq(arbol _izq) {
		this.izq = _izq;
	}
	
	public void setDer(arbol _der) {
		this.der = _der;
	}
	
	public arbol getIzq() {
		return this.izq;
	}
	
	public arbol getDer() {
		return this.der;
	}
	
	public int printPas() {
		return p.getPasajeros();
	}
}
