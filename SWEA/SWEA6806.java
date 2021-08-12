import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int[] A = new int[9];
    static int[] B = new int[9];
    static int[] arr;
    static boolean[] visited;
    static int aWin, bWin;
    
    static void dfs(int len, int n) {
    	if(len == n) {
    		int a = 0, b = 0;
    		for(int i =0; i<n; i++) {
    			if(A[i] > arr[i]) a += A[i] + arr[i];
    			else b += A[i] + arr[i];
    		}
    		if(a > b) aWin++;
    		else if(a < b) bWin++;
    		return;
    	}
    	
    	for(int i=0; i<9; i++) {
    		if(!visited[i]) {
    			visited[i] = true;
    			arr[len] = B[i];
    			dfs(len+1, n);
    			visited[i] = false;
    		}
    	}
    }
    
	public static void main(String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		for(int t = 1; t <= tc; t++) {
			aWin = bWin = 0;
			A = new int[9];
			B = new int[9];
			boolean[] used = new boolean[19];
			
			tk = new StringTokenizer(br.readLine());
			for(int i=0; i<9; i++) {
				A[i] = Integer.parseInt(tk.nextToken());
				used[A[i]] = true;
			}
			
			for(int i=1, j=0; i<=18; i++) {
				if(!used[i]) B[j++] = i;
			}
			
			visited = new boolean[9];
			arr = new int[9];
			dfs(0, 9);
			
			sb.append("#").append(t).append(" ").append(aWin).append(" ").append(bWin).append("\n");
		}
		System.out.println(sb.toString());
	}
}

