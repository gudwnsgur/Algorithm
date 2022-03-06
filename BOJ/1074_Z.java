import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, r, c;
	static int order = 0;
	static boolean solved = false;
	
	static void solve(int x1, int y1, int x2, int y2) {
		if(solved) return;
		if(x1 == x2-1 && y1 == y2-1) {
			if(x1 == r && y1 == c) {
				System.out.println(order);
				solved = true;
			}
			order++;
			return;
		}
		if(x1 <= r && r < (x1+x2)/2 && y1 <= c && c < (y1+y2)/2) 
			solve(x1, y1, (x1+x2)/2, (y1+y2)/2);
		
		else if(x1 <= r && r < (x1+x2)/2 && (y1+y2)/2 <= c && c < y2) {
			order += (((x2-x1)/2) * ((x2-x1)/2));
			solve(x1, (y1+y2)/2, (x1+x2)/2, y2);
		}
		else if((x1+x2)/2 <= r && r < x2  && y1 <= c && c < (y1+y2)/2) {
			order += (((x2-x1)/2) * ((x2-x1)/2))*2;
			solve((x1+x2)/2, y1, x2, (y1+y2)/2);
		}
		else {
			order += (((x2-x1)/2) * ((x2-x1)/2))*3;
			solve((x1+x2)/2, (y1+y2)/2, x2, y2);
		}
	}
	
	public static void main(String[] args) throws IOException {
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		r = Integer.parseInt(tk.nextToken());
		c = Integer.parseInt(tk.nextToken());
		solve(0,0, (int)Math.pow(2, n), (int)Math.pow(2, n));
	}
}

