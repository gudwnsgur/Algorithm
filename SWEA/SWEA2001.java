import java.io.*;
import java.util.*;

public class SWEA2001 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++) {
			tk = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(tk.nextToken());
			int m = Integer.parseInt(tk.nextToken());
			
			int [][]board = new int[n][n];
			for(int j=0; j<n; j++) {
				tk = new StringTokenizer(br.readLine());
				for(int k=0; k<n; k++) board[j][k] = Integer.parseInt(tk.nextToken());
			}
			int result = Integer.MIN_VALUE;
			for(int ii=0; ii<=n-m; ii++) {
				for(int jj=0; jj<=n-m; jj++) {
					int local = 0;
					for(int i=ii; i<ii+m; i++) {
						for(int j=jj; j<jj+m; j++) {
							local += board[i][j];
						}
					}
					result = Math.max(result, local);
				}
			}
			sb.append("#").append(t).append(" ").append(result).append("\n");
		}
		System.out.println(sb.toString());
	}

}


