import java.io.*;
import java.util.*;

class Node {
	int name, value;
	Node(int name, int value ){
		this.name = name;
		this.value = value;
	}
}

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int v, e, start;
	static int[] dist;
	static boolean[] visited;
	static ArrayList<ArrayList<Node>> graph = new ArrayList<>();
	
	static void dijkstra(int src) {
		PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				if(o1.value == o2.value) return Integer.compare(o1.name, o2.name);
				return Integer.compare(o1.value, o2.value);
			}
		});
		
		pq.add(new Node(src, dist[src]));
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			visited[cur.name] = true;
			for(int i=0; i<graph.get(cur.name).size(); i++) {
				Node next = graph.get(cur.name).get(i);
				if(dist[next.name] > next.value + dist[cur.name]) {
					dist[next.name] = next.value + dist[cur.name];
					if(!visited[next.name]) {
						pq.add(new Node(next.name, dist[next.name]));
					}
				}
			}
		}
		
	}
	public static void main(String[] args) throws IOException {
		tk = new StringTokenizer(br.readLine());
		v = Integer.parseInt(tk.nextToken());
		e = Integer.parseInt(tk.nextToken());
		
		for(int i=0; i<=v; i++) graph.add(new ArrayList<>());
		
		start = Integer.parseInt(br.readLine());
		for(int i=0; i<e; i++) {
			tk = new StringTokenizer(br.readLine());
			int src, dest, w;
			src = Integer.parseInt(tk.nextToken());
			dest = Integer.parseInt(tk.nextToken());
			w = Integer.parseInt(tk.nextToken());
			
			graph.get(src).add(new Node(dest, w));
		}
		dist = new int[v+1];
		visited = new boolean[v+1];
		
		for(int i=1; i<=v; i++) dist[i] = Integer.MAX_VALUE;
		dist[start] = 0;
		
		dijkstra(start);
		for(int i=1; i<=v; i++) {
			if(dist[i] == Integer.MAX_VALUE) System.out.println("INF");
			else System.out.println(dist[i]);
		}
	}

}

