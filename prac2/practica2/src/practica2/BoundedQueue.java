package practica2;
import practica2.Nodo;

public class BoundedQueue {
	public int N;
	public int nEl;
	public Nodo[] data;
	public int pri, sig;
	
	
	public BoundedQueue(int _N) {
		this.N = _N;
		data = new Nodo[_N];
		empty();
	}
	
	public void empty() {
		pri = 0;
		sig = 0;
		nEl = 0;
	}
	
	public void enqueue(Nodo d) {
		assert(nEl<N);
		data[sig] = d;
		sig = (sig + 1) % N;
		nEl++;
	}
	
	public void dequeue() {
		assert(nEl>0);
		pri = (pri+1) % N;
		nEl--;
	}
	
	public Nodo first() {
		assert(nEl>0);
		Nodo f = data[pri];
		return f;
	}
	
	public int size() {
		return N;
	}
	
	public void print() {
		if(nEl>0) {
			for(int i=0; i<nEl-1; i++) {
				System.out.println(data[(pri+i)%N]);
			}
			System.out.println(data[(pri+nEl-1)%N]);
		}
	}
}
