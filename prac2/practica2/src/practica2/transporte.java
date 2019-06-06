package practica2;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.ArrayList;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;


public class transporte {
	public static int N;
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException {
		// Lectua del fichero
		Scanner fich = new Scanner (new File("pruebas.txt"));
		PrintWriter w = new PrintWriter("resultados.txt", "UTF-8");
		
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
			
			long startTime = System.nanoTime();
			
			n = Integer.parseInt(fich.next());
			m = Integer.parseInt(fich.next());
			p = Integer.parseInt(fich.next());
			N = p;
			if(n == 0 && m == 0 && p == 0) {
				fin = true;
			}
			else {		// Generar cola
				arbol a = new arbol();
				C = new int[m];
				for(int i=0; i<m; i++) {
					C[i] = n;
				}
				for(int j=0; j<p; j++) {
					nX = Integer.parseInt(fich.next());
					mX = Integer.parseInt(fich.next());
					pX = Integer.parseInt(fich.next());
					
					Pedido x = new Pedido(nX,mX,pX);
					System.out.println("Se mete el Pedido con: "+nX+" salida, "+mX+" llegada, "+pX+" pasajeros");
					cola.add(x);
				}
				System.out.println("Pedidos: "+cola.size());

				// Creacion del arbol de pedidos
				ArrayList<Pedido> colaP = new ArrayList<Pedido>();
				Pedido auxiliar;
				int longi = cola.size();
				for(int i=0; i<longi; i++) {
					auxiliar = cola.poll();
					colaP.add(auxiliar);
				}
				
				arbol raiz = new arbol(); 
				
				llenarArbol(a,colaP,C,0,0,raiz);
				mostrarArbol(a,0);
				recorrerArbol(raiz,0);	// Cambiar por el nodo raiz
				
				long endTime   = System.nanoTime();
				imprimirSolucion(endTime-startTime,3,w);
				
				
			
			}
		}	
		w.close();
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
	
	public static void llenarArbol(arbol a, ArrayList<Pedido> colaP, int[] C, int cont, int uFacil, arbol raiz) {
		if(cont < colaP.size()) {
			int ini,fini,pas;
			Pedido x = colaP.get(cont);		// Obtener pedido actual
					
			//x.setEstimacion(calcularCosteEstimacion(C,cont,colaP));
			x.setU(u_mejor(C,cont,uFacil,colaP));	
			x.setU(uFacil);
			a.setPedido(x);
			uFacil = uFacil - (x.getBeneficio());
			x.print();
	
	        ini = x.getEstIni();
			fini = x.getEstFin();
			pas = x.getPasajeros();
			// Mirar a ver si se puede incluir
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
			if(cont == colaP.size()-1) {
				n.setU(uFacil);
				// TABMIE AÑADIR C(X) !!!!!!!!!!!!!
			}
			if(descartar) {	// Caso descartar pedido
				System.out.println("Se descarta el Pedido");
				C = aux.clone();				
				descartar = false;
				a.setDer(new arbol(a,n,false));
				
				System.out.println("LLamada hijo derecho por descarte");
				if(cont == 0) {
					raiz = a;
				}
				
				llenarArbol(a.getDer(),colaP,C,cont+1,uFacil,raiz);
			}
			else {	// Caso meter pedido
				a.setIzq(new arbol(a,n,true));
				System.out.println("LLamada hijo izquerdo");
				if(cont == 0) {
					raiz = a;
				}
				
				llenarArbol(a.getIzq(),colaP,C,cont+1,uFacil,raiz);
				
				a.setDer(new arbol(a,n,false));
				System.out.println("LLamada hijo derecho");
				
				C = aux.clone();	
				llenarArbol(a.getDer(),colaP,C,cont+1,uFacil,raiz);
			}
		}
	}
	
	
	public static void recorrerArbol(arbol a, int cont) {
		if(a.izq == null && a.der == null) {	// Es nodo hoja(posible solucion)
			System.out.println("final: "+cont);
		}
		else if(a.izq == null) {	// Solo tiene hijo derecho
			arbol y = a.der;
			if(y.p.estimacion <= y.p.u) {	// Solo si c(x) <= U del hijo der
				System.out.println("Comparando "+y.p.estimacion+" con "+y.p.u+ " y va por der");
				recorrerArbol(a.der,cont+1);
			}
			else {
				System.out.println("error1");
			}
		}
		else if(a.izq != null && a.der != null) {	// Tiene los dos hijos
			arbol x = a.izq;
			arbol y = a.der;
			if(x.p.estimacion < y.p.estimacion) {	// Es mejor el izq
				if(x.p.estimacion <= x.p.u) {	// Solo si c(x) <= U del hijo izq
					System.out.println("Comparando "+x.p.estimacion+" con "+x.p.u+ " y va por izq");
					recorrerArbol(a.izq,cont+1);
				}
				else {
					System.out.println("error2");
				}
			}
			else if (x.p.estimacion > y.p.estimacion) {	// es mejor la der
				if(y.p.estimacion <= y.p.u) {	// Solo si c(x) <= U del hijo der
					System.out.println("Comparando "+y.p.estimacion+" con "+y.p.u+ " y va por der");
					recorrerArbol(a.der,cont+1);
				}
				else {
					System.out.println("error3");
				}
			}
			else {	// si hay que comparar las U
				if(x.p.u <= y.p.u) {	// es mejor la u de izq
					if(x.p.estimacion <= x.p.u) {	// Solo si c(x) <= U del hijo izq
						System.out.println("Comparando "+x.p.estimacion+" con "+x.p.u+ " y va por izq");
						recorrerArbol(a.izq,cont+1);
					}
					else {
						System.out.println("error4");
					}
				}
				else {	// es mejor la u de der
					if(y.p.estimacion <= y.p.u) {	// Solo si c(x) <= U del hijo der
						System.out.println("Comparando "+y.p.estimacion+" con "+y.p.u+ " y va por der");
						recorrerArbol(a.der,cont+1);
					}
					else {
						System.out.println("error5");
					}
				}
			}
		}
		else {
			System.out.println("error");
		}

	}
	
	/*
	public static int calcularCosteEstimacion(int[] cap, int obj, ArrayList<Pedido> colaP) {
		if(obj > N || cap[] < 0) {
			return ben;
		}
		else {
			if() {
				
			}
			else {
				
			}
		}
		
		return ben; // return ben+capLibre/peso[obj]*benef[obj]
	}
	*/
	
	public static int u_mejor(int[] cap, int obj, int uFacil, ArrayList<Pedido> colaP) {
		int U = uFacil;
		int[] ca = cap.clone();
		Pedido x;
		for(int i=obj; i<N; i++) {
			x = colaP.get(i);
			for(int j=x.getEstIni(); j<x.getEstFin(); j++) {	
				if((ca[j] - x.getPasajeros()) >= 0) {			
					ca[j] = ca[j] - x.getPasajeros();	
					U = U - x.getBeneficio();
				}
			}
		}
		return U;
	}
	
	public static void imprimirSolucion(long time, int ben, PrintWriter w) throws FileNotFoundException, UnsupportedEncodingException {
		double seconds = (double)time / 1_000_000_000.0;
		w.println(ben+" "+seconds);
	}
	
}
