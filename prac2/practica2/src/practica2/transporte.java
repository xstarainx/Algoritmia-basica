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
					Pedido y = colaP.get(i);
					y.print();
				}
				
				arbol raiz = new arbol(); 
				
				arbol a = new arbol();
				//llenarArbol(a,colaP,C,0,0,0,raiz);
				prueba(a,colaP,C,0,0);
				mostrarArbol(a,0);
				//recorrerArbol(raiz,0);	// Cambiar por el nodo raiz
				
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
			System.out.println(al.p.uFacil);
			mostrarArbol(al.getIzq(),cont+1);
		}
	}
	
	public static void prueba(arbol a, ArrayList<Pedido> colaP, int[] C,  int cont, int uFacil) {
		if(cont < colaP.size()) {
			int ini,fini,pas;
			Pedido x = colaP.get(cont);		// Obtener pedido actual
			
			if(cont == 0) {
				x.setU(0);
				int uu = u_mejor(C,cont,uFacil,colaP);
				x.setU(uu);
			}
			else {
				int uu = u_mejor(C,cont,uFacil,colaP);
				x.setU(uu);
				System.out.println("METIDOOOOO: "+x.getU());
			}
			x.setUfacil(uFacil);
			a.p = x;
			//a.setPedido(x);
	        ini = x.getEstIni();
			fini = x.getEstFin();
			pas = x.getPasajeros();
			boolean descartar = false;
			int[] aux = C.clone();			// Clonado por si se descarta
			for(int i=ini; i<fini; i++) {
				C[i] = C[i] - pas;			// Restar pasajeros del pedido
				if(C[i] < 0) {				// Se ha pasado, se descarta el Pedido
					descartar = true;
				}
			}
			Pedido n = new Pedido();			
			if(descartar) {	// Caso descartar pedido
				C = aux.clone();				
				descartar = false;
				
				for (int i=0; i<C.length; i++) {
					System.out.print(" "+C[i]+" ");
				}
				
				System.out.println();
				a.setDer(new arbol(a,n,false));

				prueba(a.getDer(),colaP,C,cont+1,uFacil);
				
			}
			else {	// Caso meter pedido
				for (int i=0; i<C.length; i++) {
					System.out.print(" "+C[i]+" ");
				}
				System.out.println();
				
				a.setIzq(new arbol(a,n,true));
				int uFacilSig = uFacil -x.getBeneficio();
				System.out.println("ddlsfjlsdjfdslfj: "+uFacilSig);
				prueba(a.getIzq(),colaP,C,cont+1,uFacil-x.getBeneficio());
				
				C = aux.clone();			
				a.setDer(new arbol(a,n,false));	
				
				for (int i=0; i<C.length; i++) {
					System.out.print(" "+C[i]+" ");
				}
				System.out.println();
				prueba(a.getDer(),colaP,C,cont+1,uFacil);
			}
		}
	}
	
	public static void llenarArbol(arbol a, ArrayList<Pedido> colaP, int[] C, int cont, int ben, int uFacil, arbol raiz) {
		if(cont < colaP.size()) {
			
			int ini,fini,pas;
			Pedido x = colaP.get(cont);		// Obtener pedido actual
			
			x.setEstimacion(calcularCosteEstimacion(C,cont,ben,colaP));
			System.out.println("LLAMANDO A U");
			if(cont == 0) {
				x.setU(0);
			}
			else {
				x.setU(u_mejor(C,cont,uFacil,colaP));
				
			}
				
			
			a.setPedido(x);
			System.out.println("arbol insertado con u: "+a.p.getU());
	
	        ini = x.getEstIni();
			fini = x.getEstFin();
			pas = x.getPasajeros();
			// Mirar a ver si se puede incluir
			boolean descartar = false;
			int[] aux = C.clone();			// Clonado por si se descarta
			for(int i=ini; i<fini; i++) {
				C[i] = C[i] - pas;			// Restar pasajeros del pedido
				if(C[i] < 0) {				// Se ha pasado, se descarta el Pedido
					descartar = true;
				}
			}
			Pedido n = new Pedido();
			if(cont == colaP.size()-1) {
				n.setU(uFacil);
				System.out.println("Ojoooooo");
				// TABMIE AÑADIR C(X) !!!!!!!!!!!!!
			}
			
			
			if(descartar) {	// Caso descartar pedido
				C = aux.clone();				
				descartar = false;
				a.setDer(new arbol(a,n,false));
				
				if(cont == 0) {
					raiz = a;
				}
				
				llenarArbol(a.getDer(),colaP,C,cont+1,ben,uFacil,raiz);
			}
			else {	// Caso meter pedido
				a.setIzq(new arbol(a,n,true));
				if(cont == 0) {
					raiz = a;
				}
				int benf = x.getBeneficio();
				int uFacilsig = uFacil - (x.getBeneficio());
				System.out.println("Le paso uFacil con "+uFacilsig);
				System.out.println("Nodo en nivel: "+cont+" con u: "+x.getU());
				llenarArbol(a.getIzq(),colaP,C,cont+1,ben+benf,uFacilsig,raiz);
				
				a.setDer(new arbol(a,n,false));
				
				C = aux.clone();	
				llenarArbol(a.getDer(),colaP,C,cont+1,ben,uFacil,raiz);
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
	
	
	public static int calcularCosteEstimacion(int[] cap, int obj, int ben, ArrayList<Pedido> colaP) {
		if(obj > N) {	// Mirar si eres ultimo nodo del arbol
			return ben;
		}
		int tope = 0;
		for(int i=0; i<cap.length; i++) {
			if(cap[i] == 0) {
				tope++;
			}
		}
		if(tope == cap.length) {	// Mirar si ya no caben mas pedidos
			return ben;
		}
		int[] ca = cap.clone();		// Clonado para no alterar el vector bueno
		Pedido x;
		// Recorrer desde el nodo en el que estoy(pedido actual) hasta el último válido (intentando 
		//    meter todos los pedidos)
		for(int i=obj; i<N; i++) {
			x = colaP.get(i);
			// Para cada nodo (pedido) comprobar si se pueden meter los pasajeros
			for(int j=x.getEstIni(); j<x.getEstFin(); j++) {	
				if((ca[j] - x.getPasajeros()) < 0) {	// Si se pasa, calculo todos los que puedo meter y el beneficio
					ca[j] = 0;
					int pasajerosMetidos = x.getPasajeros() - ca[j];
					ben = ben - ((x.getEstIni() - x.getEstFin()) * pasajerosMetidos);
				}
				else {	// Si caben resto los pasajeros al vector
					ca[j] = ca[j] - x.getPasajeros();
					ben = ben - x.getBeneficio();
				}
			}
		}
		return ben;
	}
	
	
	public static int u_mejor(int[] cap, int obj, int uFacil, ArrayList<Pedido> colaP) {
		int U = uFacil;
		int[] ca = cap.clone();
		Pedido x;
		for(int i=obj; i<N; i++) {
			x = colaP.get(i);
			boolean descartar = false;
			System.out.println(" 	Buscando U-mejor en nodo: "+x.getEstIni()+" y "+x.getEstFin());
			for(int j=x.getEstIni(); j<x.getEstFin(); j++) {	
				if((ca[j] - x.getPasajeros()) >= 0) {			
					ca[j] = ca[j] - x.getPasajeros();	
				}
				else {
					descartar = true;
				}
			}
			if(descartar) {
				descartar = false;
			}
			else {
				U = U - x.getBeneficio();
				System.out.println(" 	Sumando beneficio: "+U);
			}

		}
		System.out.println("      Definitivamente devuleve: "+U);
		return U;
	}
	
	public static void imprimirSolucion(long time, int ben, PrintWriter w) throws FileNotFoundException, UnsupportedEncodingException {
		double seconds = (double)time / 1_000_000_000.0;
		w.println(ben+" "+seconds);
	}
	
}
