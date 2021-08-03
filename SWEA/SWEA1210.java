import java.io.*;
import java.util.*;

public class SWEA1210 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	
	static int n = 100;
	static int[][] map;
	
	static int solve(int x, int y) {
		do {
			if(y > 0 && map[x][y-1] == 1) while(y > 0 && map[x][y-1] == 1) y--;
			else if(y < n-1 && map[x][y+1] == 1) while(y < n-1 && map[x][y+1] == 1) y++;
			
			x--;
		} while(x != 0);
		return y;
	}
	
	
	public static void main(String[] args) throws IOException {
		for(int i=1; i<=10 ; i++) {
			int tc = Integer.parseInt(br.readLine());
			map = new int[100][100];
			
			for(int j=0; j<100; j++) {
				tk = new StringTokenizer(br.readLine());
				for(int k=0; k<100; k++) {
					map[j][k] = Integer.parseInt(tk.nextToken());
					if(map[j][k] == 2) {
						sb.append("#").append(tc).append(" ").append(solve(j,k)).append("\n");
						break;
					}
				}
			}
		}
		System.out.println(sb.toString());
	}
}

