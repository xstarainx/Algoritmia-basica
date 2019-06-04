package practica2;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Iterator;
import practica2.Nodo;

public class transporte {
	
	public static void main(String args[]) throws FileNotFoundException {
		// Lectua del fichero
		Scanner fich = new Scanner (new File("pruebas.txt"));
		
		boolean descartar=false, fin=false;
		int n=0, m=0, p=0;
		int nX=0, mX=0, pX=0;
		
		PriorityQueue<Nodo> cola = new PriorityQueue<Nodo>(new Comparator<Nodo>() {
		    public int compare(Nodo node1, Nodo node2) {
		        if (node1.getBeneficio() > node2.getBeneficio()) return -1;
		        if (node1.getBeneficio() < node2.getBeneficio()) return 1;
		        return 0;
		    }
		});
		
		
		
		int[] C = {0};	// Vector capacidad por tramo
		
		while(!fin) {
			n = Integer.parseInt(fich.next());
			m = Integer.parseInt(fich.next());
			p = Integer.parseInt(fich.next());
			if(n == 0 && m == 0 && p == 0) {
				fin = true;
			}
			else {
				C = new int[m];
				for(int i=0; i<m; i++) {
					C[i] = n;
				}
				for(int i=0; i<C.length; i++) {
					System.out.println("Contiene: "+C[i]);
				}
				
				for(int j=0; j<p; j++) {
					nX = Integer.parseInt(fich.next());
					mX = Integer.parseInt(fich.next());
					pX = Integer.parseInt(fich.next());
					
					System.out.println("Creando nodo con: "+nX+" salida, "+mX+" llegada, "+pX+" pasajeros");
					
					int[] aux = C.clone();		// Clonado por si se descarta
					for(int i=nX; i<mX; i++) {
						C[i] = C[i] - pX;		// Restar pasajeros del pedido
						System.out.println("Ahora en "+i+" hay "+C[i]);
						if(C[i] < 0) {			// Se ha pasado, se descarta el nodo
							descartar = true;
						}
					}
					if(descartar) {
						System.out.println("Se descarta el nodo");
						C = aux.clone();
						descartar = false;
					}
					else {	// Si no se descarta se añade el pedido a la cola
						Nodo x = new Nodo(nX,mX,pX);
						System.out.println("Se mete el nodo con: "+nX+" salida, "+mX+" llegada, "+pX+" pasajeros");
						cola.add(x);
					}
				}
			}
			
			// resetear nodo, cola prioridad etc
			System.out.println("Tamaño: "+cola.size());
			System.out.println("Termina");
			
			
	        Iterator<Nodo> value = cola.iterator(); 
			while (value.hasNext()) { 
				Nodo y = value.next();
	            y.print(); 
	        } 
		}	
		fich.close();
	}
	
	
	
	public int calcularCosteEstimacion(int ben, int obj) {
		System.out.println();
		
		return ben; // return ben+capLibre/peso[obj]*benef[obj]
	}
	
	public void u_mejor() {
		System.out.println();
	}
	
}
