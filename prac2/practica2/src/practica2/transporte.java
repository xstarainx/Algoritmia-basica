package practica2;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Iterator;

public class transporte {
	public static void main(String args[]) throws FileNotFoundException {
		// Lectua del fichero
		Scanner fich = new Scanner (new File("pruebas.txt"));
		
		PriorityQueue<Pedido> cola = new PriorityQueue<Pedido>(new Comparator<Pedido>() {	// Cola con prioridad descendente
		    public int compare(Pedido p1, Pedido p2) {
		        if (p1.getBeneficio() > p2.getBeneficio()) return -1;
		        if (p1.getBeneficio() <= p2.getBeneficio()) return 1;
		        return 0;
		    }
		});
		
		boolean fin=false;
		int n=0, m=0, p=0;
		int nX=0, mX=0, pX=0;
		
		int[] C = {0};	// Vector capacidad por tramo
		
		while(!fin) {	// Obtener primera linea
			
			n = Integer.parseInt(fich.next());
			m = Integer.parseInt(fich.next());
			p = Integer.parseInt(fich.next());
			if(n == 0 && m == 0 && p == 0) {
				fin = true;
			}
			else {		// Generar cola
				arbol a = new arbol();
				C = new int[m];
				for(int i=0; i<m; i++) {
					C[i] = n;
				}
				for(int j=0; j<p-1; j++) {
					nX = Integer.parseInt(fich.next());
					mX = Integer.parseInt(fich.next());
					pX = Integer.parseInt(fich.next());
					
					Pedido x = new Pedido(nX,mX,pX);
					System.out.println("Se mete el Pedido con: "+nX+" salida, "+mX+" llegada, "+pX+" pasajeros");
					cola.add(x);
				}
				System.out.println("Pedidos: "+cola.size());
				Iterator<Pedido> value = cola.iterator(); 
				while (value.hasNext()) { 
						Pedido y = value.next();
			            y.print(); 
			    } 
				// Creacion del arbol de pedidos
				llenarArbol(a,cola,C);
				mostrarArbol(a, 0);
			}
		}	
		fich.close();
	}
	
	public static void mostrarArbol(arbol al, int cont) throws NullPointerException {
		if(al!=null){
			mostrarArbol(al.getDer(),cont+1);
			for(int i=0;i<cont;i++){
				System.out.print("    ");
			}
			System.out.println(al.printPas());
			mostrarArbol(al.getIzq(),cont+1);
		}
	}
	
	public static void llenarArbol(arbol a, PriorityQueue<Pedido> cola, int[] C) {
		if(!cola.isEmpty()) {
			int ini,fini,pas;
			Pedido x = cola.peek();
			x.print();
	
	        ini = x.getEstIni();
			fini = x.getEstFin();
			pas = x.getPasajeros();
			
			boolean descartar = false;
			int[] aux = C.clone();			// Clonado por si se descarta
			for(int i=ini; i<fini; i++) {
				C[i] = C[i] - pas;			// Restar pasajeros del pedido
				System.out.println("Ahora en "+i+" hay "+C[i]);
				if(C[i] < 0) {				// Se ha pasado, se descarta el Pedido
					descartar = true;
				}
			}
			Pedido n = new Pedido();
			if(descartar) {					// Caso descartar pedido
				System.out.println("Se descarta el Pedido");
				C = aux.clone();
				cola.poll();
				descartar = false;
				a.setDer(new arbol(a,n,false));		// Crear hijo derecho
				arbol sig = a.getDer();				// Obtener hijo derecho
				System.out.println("LLamada hijo derecho por descarte");
				
				llenarArbol(sig,cola,C);			// Llamada recursiva
			}
			else {							// Caso meter pedido
				cola.poll();
				a.setIzq(new arbol(a,n,true));		// Crear hijo izquierdo
				arbol sig = a.getIzq();				// Obtener hijo izquierdo
				System.out.println("LLamada hijo izquerdo");
				
				llenarArbol(sig,cola,C);
				a.setDer(new arbol(a,n,false));		// Crear hijo derecho
				sig = a.getDer();					// Obtener hijo derecho
				System.out.println("LLamada hijo derecho");
				
				llenarArbol(sig,cola,C);
			}
		}
	}
	
	
	
	public static  int calcularCosteEstimacion(int ben, int obj) {
		System.out.println();
		
		return ben; // return ben+capLibre/peso[obj]*benef[obj]
	}
	
	public static void u_mejor() {
		System.out.println();
	}
	
}
