import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int diff = Integer.MAX_VALUE;
    static int[] sourness, bitterness;
    static boolean[] visited;
    
    static void subset(int len, int n) {
    	if(len == n ) {
    		int sour = 1, bitter = 0;
    		for(int i=0; i<n; i++) {
    			if(visited[i]) {
    				sour *= sourness[i];
    				bitter += bitterness[i];
    			}
    		}
    		if(bitter != 0) diff = Math.min(Math.abs(sour - bitter), diff);
    		return;
    	}
    	
    	visited[len] = true;
    	subset(len+1, n);
    	visited[len] = false;
    	subset(len+1, n);
    }
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		sourness = new int[n];
		bitterness = new int[n];
		visited = new boolean[n];
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			sourness[i] = Integer.parseInt(tk.nextToken());
			bitterness[i] = Integer.parseInt(tk.nextToken());
		}
		
		subset(0, n);
		System.out.println(diff);
	}

}

