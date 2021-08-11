import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int[][] map;
    static int n, m;
    
    static boolean canRotate(int x1, int y1, int x2, int y2) {
    	if(x1 > x2 || y1 > y2) return false;
    	int tmp = map[x1][y1];
    	
    	for(int y = y1+1; y <= y2; y++) map[x1][y-1] = map[x1][y];
    	for(int x = x1+1; x <= x2; x++) map[x-1][y2] = map[x][y2];
    	for(int y = y2-1; y >= y1; y--) map[x2][y+1] = map[x2][y];
    	for(int x = x2-1; x >= x1; x--) map[x+1][y1] = map[x][y1];
    	map[x1+1][y1] = tmp;
    	return true;
    }
    
	public static void main(String[] args) throws IOException{
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		int r = Integer.parseInt(tk.nextToken());
		map = new int[n][m];
		
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) map[i][j] = Integer.parseInt(tk.nextToken());
		}
		
		for(int i=0; i<r; i++) {
			int x1 = 0, y1= 0, x2 = n-1, y2 = m-1;
			while(canRotate(x1++, y1++, x2--, y2--)); 
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
	}
}

