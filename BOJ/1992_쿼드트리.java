import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder result = new StringBuilder();
	static int n;
	static int[][] map;

	static boolean isSame(int x1, int y1, int x2, int y2) {
		int num = map[x1][y1];
		for(int i=x1; i<x2; i++) {
			for(int j=y1; j<y2; j++) {
				if(num != map[i][j]) return false;
			}
		}
		return true;
	}
	
	static void recursion(int x1, int y1, int x2, int y2) {
		if(isSame(x1, y1, x2, y2) || (x1 == x2-1 && y1 == y2-1)) {
			result.append(map[x1][y1] == 1 ? "1" : "0");
			return;
		}
		
		result.append("(");
		recursion(x1, y1, (x1+x2)/2, (y1+y2)/2);
		recursion(x1, (y1+y2)/2, (x1+x2)/2, y2);
		recursion((x1+x2)/2, y1, x2, (y1+y2)/2);
		recursion((x1+x2)/2, (y1+y2)/2, x2, y2);
		result.append(")");
	}
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			for(int j=0; j<n; j++) map[i][j] = str.charAt(j) == '1' ? 1 : 0;
		}
		
		recursion(0, 0, n, n);
		System.out.println(result.toString());
	}
}
