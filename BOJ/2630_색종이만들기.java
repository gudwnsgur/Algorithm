import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n;
	static int[][] paper;
	static int white = 0, blue = 0;
	
	static boolean allSame(int x1, int y1, int x2, int y2) {
		int cur = paper[x1][y1];
		for(int i=x1; i<x2; i++) {
			for(int j=y1; j<y2; j++) {
				if(paper[i][j] != cur) {
					return false;
				}
			}
		}
		return true;
	}
	
	static void recursion(int x1, int y1, int x2, int y2) {
		if(x1 == x2-1 && y1 == y2-1) {
			if(paper[x1][y1] == 1) blue++;
			else white++;
			return;
		}
		
		if(allSame(x1, y1, x2, y2)) {
			if(paper[x1][y1] == 1) blue++;
			else white++;
			return;
		}
		
		
		// 순서는 상관 없다.
		recursion(x1, y1, (x1+x2)/2, (y1+y2)/2); // 1
		recursion(x1, (y1+y2)/2, (x1+x2)/2, y2); // 2
		recursion((x1+x2)/2, y1, x2, (y1+y2)/2); // 3
		recursion((x1+x2)/2, (y1+y2)/2, x2, y2); // 4		
	}
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		paper = new int[n][n];
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				paper[i][j] = Integer.parseInt(tk.nextToken());
			}
		}
		
		recursion(0, 0, n, n);
		System.out.println(white);
		System.out.println(blue);

	}

}


