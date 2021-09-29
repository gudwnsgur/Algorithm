import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static boolean[][] graph;
    static int n, m;
    
    static int solve() throws Exception {
    	tk = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(tk.nextToken());
    	m = Integer.parseInt(tk.nextToken());
    	graph = new boolean[n+1][n+1];
    	for(int i=1; i<=n; i++) graph[i][i] = true;
    	
    	for(int i=0; i<m; i++) {
    		tk = new StringTokenizer(br.readLine());
    		graph[Integer.parseInt(tk.nextToken())][Integer.parseInt(tk.nextToken())] = true;
    	}
    	
    	for(int k=1; k<=n; k++) {
    		for(int i=1; i<=n; i++) {
    			for(int j=1; j<=n; j++) {
    				graph[i][j] = graph[i][j] ? true : (graph[i][k] && graph[k][j]);
    			}
    		}
    	}

//    	for(int i=1; i<=n; i++) {
//    		for(int j=1; j<=n; j++) {
//    			System.out.print(graph[i][j] ? "O " : "X " );
//    		}
//    		System.out.println();
//    	}
    	
    	int result = 0;
    	for(int i=1; i<=n; i++) {
    		int cnt = 0;
    		for(int j=1; j<=n; j++) {
    			if( i!=j && ( graph[i][j] || graph[j][i])) cnt++;
    		}
    		if(cnt == n-1) result++;
    	}
    	return result;
    }

    
	public static void main(String[] args) throws Exception {
		System.out.println(solve());
	}
}

