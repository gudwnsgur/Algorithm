import java.io.*;
import java.util.*;

class Loc {
	int x, y;
	Loc (int x, int y ) {
		this.x = x;
		this.y = y;
	}
}

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	static int n, result;
	static Loc[] customer;
	static Loc house, company;
	static int[] arr;
	static boolean[] visited;
	
	static int getDist() {
		int localRes = Math.abs(customer[arr[0]].x - house.x) + Math.abs(customer[arr[0]].y - house.y);
		for(int i=1; i<n; i++) 
			localRes += Math.abs(customer[arr[i]].x - customer[arr[i-1]].x) + Math.abs(customer[arr[i]].y - customer[arr[i-1]].y);
		localRes += Math.abs(company.x - customer[arr[n-1]].x) + Math.abs(company.y - customer[arr[n-1]].y);
		return localRes;
	}
	
	static void dfs(int len) {
		if(len == n) {
			result = Math.min(result, getDist());
			return;
		}
		
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				visited[i] = true;
				arr[len] = i;
				dfs(len+1);
				visited[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for(int t = 1; t <= tc ; t++) {
			n = Integer.parseInt(br.readLine());
			result = Integer.MAX_VALUE;
			customer = new Loc[n];
			arr = new int[n];
			visited = new boolean[n];
			
			tk = new StringTokenizer(br.readLine());
			company = new Loc(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));
			house = new Loc(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));
			
			for(int i=0; i<n; i++) 
				customer[i] = new Loc(Integer.parseInt(tk.nextToken()), 
						Integer.parseInt(tk.nextToken()));
			
			dfs(0);
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb.toString());
	}

}
