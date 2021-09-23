import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, result = Integer.MAX_VALUE;
	static int[][] graph;
	static boolean[] visited;
	
	static void dfs(int node, int len, int value) {
		if(len == n && node == 0) {
			result = Math.min(result, value);
			return;
		}
		
		if((len >= 1 && node == 0) || value >=  result) return;
		
		for(int i=0; i<n; i++) {
			if(i != node && graph[node][i] != 0 && !visited[i]) {
				visited[i] = true;
				dfs(i, len+1, value+graph[node][i]);
				visited[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		n = Integer.parseInt(br.readLine());
		graph = new int[n][n];
		visited = new boolean[n];
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				graph[i][j] = Integer.parseInt(tk.nextToken());
			}
		}
			
		dfs(0, 0, 0);
		System.out.println(result);
	}
}


