import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static final int INF = 987654321;
	static int n;
	
	static int solve() throws Exception{
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());

		
		int[][] dist = new int[n+1][n+1];
		for(int i=1; i<=n; i++) {
			Arrays.fill(dist[i], INF);
			dist[i][i] = 0;
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n ; j++) {
				boolean connected = (tk.nextToken().equals("1"));
				if(connected) {
					dist[i][j] = 1;
					dist[j][i] = 1;
				}
			}
		}
		for(int k = 1; k <=n ; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n ;j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	
		
		int[] result = new int[n+1];
		for(int i=1; i<=n; i++) {
			int sum = 0;
			for(int j=1; j<=n; j++) {
				sum += dist[i][j];
			}
			result[i] = sum;
		}
		
		int min = Integer.MAX_VALUE;
		for(int i=1; i<=n; i++) min = Math.min(min, result[i]);
		return min;
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int i=1; i<=tc; i++) {
			System.out.println("#" + i + " " + solve());
		}
	}

}

