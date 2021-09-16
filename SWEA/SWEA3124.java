import java.util.*;
import java.io.*;

class Edge {
	int s, e, value ;
	Edge(int s, int e, int value) {
		this.s = s;
		this.e = e;
		this.value = value;
	}
}

public class Solution {
	static StringTokenizer tk;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int n, m;
	static int[] p;
	static ArrayList<Edge> edges = new ArrayList<>();
	
	static int getP(int a) {
		if( a == p[a]) return a;
		return p[a] = getP(p[a]);
	}
	static void union(int a, int b) {
		a = getP(a);
		b = getP(b);
		if(a < b) p[b] = a;
		else p[a] = b;
	}
	
	static long solve() throws Exception{
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		
		edges = new ArrayList<>();
		p = new int[n+1];
		for(int i=0; i<=n; i++) p[i] = i;
		
		for(int i=0; i<m; i++) {
			tk = new StringTokenizer(br.readLine());
			edges.add(new Edge(Integer.parseInt(tk.nextToken()), 
					Integer.parseInt(tk.nextToken()), 
					Integer.parseInt(tk.nextToken())));
		}
		Collections.sort(edges, new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.value, o2.value);
			}
		});
		long result = 0;
		for(Edge cur : edges) {
			if(getP(cur.s) != getP(cur.e)) {
				result += cur.value;
				union(cur.s, cur.e);
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int i=1; i<=tc; i++) {
			System.out.println("#" + i + " " + solve());
		}

	}

}

