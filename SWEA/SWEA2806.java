import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	static int n, result;
	static int[] arr;
	static boolean[] visited;

	static boolean promise(int x, int y) {
		for(int i=0; i<x; i++) {
			if(Math.abs(i - x) == Math.abs(arr[i] - y)) return false;
		}
		return true;
	}
	
	static void dfs(int len) {
		if(len == n) {
			result++;
			return;
		}
		
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				if(promise(len, i)) {
					visited[i] = true;
					arr[len] = i;
					dfs(len+1);
					visited[i] = false;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for(int t = 1;  t<=tc; t++) {
			n = Integer.parseInt(br.readLine());
			result = 0;
			arr = new int[n];
			visited = new boolean[n];
			
			dfs(0);
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb.toString());
	}

}

