import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	static int n, m;
	static boolean[] visited;
	static boolean[][] graph;
	
	static void dfs(int node) {
		visited[node] = true;
		for(int i=1; i<=n; i++) if(!visited[i] && graph[node][i]) dfs(i);
	}
	
	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++ ) {
			tk = new StringTokenizer(br.readLine());
			n = Integer.parseInt(tk.nextToken());
			m = Integer.parseInt(tk.nextToken());
			
			visited = new boolean[n+1];
			graph = new boolean[n+1][n+1];
			for(int i=0; i<m; i++) {
				tk = new StringTokenizer(br.readLine());
				int s = Integer.parseInt(tk.nextToken());
				int e = Integer.parseInt(tk.nextToken());
				graph[s][e] = true;
				graph[e][s] = true;
			}
			int result = 0;
			for(int i=1; i<=n; i++) {
				if(!visited[i]) {
					result++;
					dfs(i);
				}
			}
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb.toString());
	}
}

