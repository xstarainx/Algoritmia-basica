package practica2;

public class Pedido {
	public int estIni;			// Estacion inicial
	public int estFin;			// Estacion final
	public int nPasajeros;		// Numero de pasajeros
	public int uFacil;
	
	public int estimacion;
	public int u;
	
	
	// Constructor vacio
	public Pedido() {}
		
	// Constructor con parametros
	public Pedido(int _estIni, int _estFin, int _nPasajeros) {
		this.estIni = _estIni;
		this.estFin = _estFin;
		this.nPasajeros = _nPasajeros;
		// Falta asignar estimacion y u
	}
	
	// Devuelve el numero de estacion inicial
	public int getEstIni() {
		return this.estIni;
	}
	
	// Devuelve el numero de estacion final
	public int getEstFin() {
		return this.estFin;
	}
	
	// Devuelve el numero de pasajeros
	public int getPasajeros() {
		return this.nPasajeros;
	}
	
	// Devuelve el beneficio total de un pedido de estacion
	public int getBeneficio() {
		return (this.estFin - this.estIni)*this.nPasajeros;
	}
	
	// Actualiza el valor de coste estimado
	public void setEstimacion(int e) {
		this.estimacion = e;
	}
	
	// Actuaiza el valor de u
	public void setU(int _u) {
		this.u = _u;
	}
	
	// Devuelve la el coste estimado
	public int getEstimacion() {
		return this.estimacion;
	}
	
	// Devuelve u
	public int getU() {
		return this.u;
	}
	
	public int getUfacil() {
		return this.uFacil;
	}
	
	public void setUfacil(int uf) {
		this.uFacil = uf;
	}
	
	// Mostrar el contenido del nodo
	public void print() {
		System.out.println("Nodo: "+this.estIni+", "+this.estFin+", "+this.nPasajeros);
	}
	
}
