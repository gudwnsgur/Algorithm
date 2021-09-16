import java.io.*;
import java.util.*;
class Loc {
	int x, y;
	Loc(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static final int INF = 987654321;
	

	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		while(tc-- > 0 ) {
			int n = Integer.parseInt(br.readLine());
			ArrayList<Loc> arr = new ArrayList<>();
			int[][] dist = new int[n+2][n+2];
			
			for(int i=0; i<n+2; i++) {
				tk = new StringTokenizer(br.readLine());
				arr.add(new Loc(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken())));
			}
			
			for(int i=0; i<n+2 ; i++) {
				for(int j=0; j<n+2; j++) {
					dist[i][j] = Math.abs(arr.get(i).x - arr.get(j).x) + 
							Math.abs(arr.get(i).y - arr.get(j).y);
					if(dist[i][j] > 1000) {
						dist[i][j] = dist[j][i] = INF;
					}
				}
			}
			
			for(int k=0; k<n+2; k++) {
				for(int i =0; i<n+2; i++) {
					for(int j=0; j<n+2; j++) {
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
			
			System.out.println(dist[0][n+1] == INF ? "sad" : "happy");
		}
	}
}

