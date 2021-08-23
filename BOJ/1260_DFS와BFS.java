import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static int n;
	static boolean[] visited;
	
	static void dfs(int node) {
		visited[node] = true;
		System.out.print(node + " ");
		
		for(int i=0; i<graph.get(node).size(); i++) {
			int next = graph.get(node).get(i);
			if(!visited[next]) {
				dfs(next);
			}
		}
	}
	static void bfs(int node) {
		visited[node] = true;
		Queue<Integer> q = new LinkedList<>();
		q.add(node);
		
		while(!q.isEmpty()) {
			int cur = q.poll();
			System.out.print(cur + " ");
			for(int i=0; i<graph.get(cur).size(); i++) {
				int next = graph.get(cur).get(i);
				if(!visited[next]) {
					visited[next] = true;
					q.add(next);
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		tk = new StringTokenizer(br.readLine());
		
		n  = Integer.parseInt(tk.nextToken());
		int edges = Integer.parseInt(tk.nextToken());
		int	start = Integer.parseInt(tk.nextToken());
		
		for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
		for(int i=0; i<edges; i++) {
			tk = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(tk.nextToken());
			int e = Integer.parseInt(tk.nextToken());
			graph.get(s).add(e);
			graph.get(e).add(s);
		}
		for(int i=1; i<=n; i++) Collections.sort(graph.get(i));
		
		visited = new boolean[n+1];
		dfs(start);
		System.out.println();
		
		visited = new boolean[n+1];
		bfs(start);
		System.out.println();
	}

}

