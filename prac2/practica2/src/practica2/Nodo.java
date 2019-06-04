package practica2;

public class Nodo {
	int estIni;			// Estacion inicial
	int estFin;			// Estacion final
	int nPasajeros;		// Numero de pasajeros
	
	int estimacion;
	int u;
	
	// Constructor
	public Nodo(int _estIni, int _estFin, int _nPasajeros) {
		estIni = _estIni;
		estFin = _estFin;
		nPasajeros = _nPasajeros;
	}
	
	// Devuelve el beneficio total de un pedido de estacion
	public int getBeneficio() {
		return (this.estFin - this.estIni)*this.nPasajeros;
	}
	
	// Mostrar el contenido del nodo
	public void print() {
		System.out.println("Nodo: "+this.estIni+", "+this.estFin+", "+this.nPasajeros);
	}
	
}
