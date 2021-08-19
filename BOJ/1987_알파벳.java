import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static final int[] dx = {-1, 0, 1, 0};
	static final int[] dy = {0, -1, 0, 1};
	static int r, c, result = 1;
	static char[][] map;
	static boolean[] alphabet;
	
	static void dfs(int len, int x, int y) {
		for(int i=0; i<4 ; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= r || ny < 0 || ny >= c || alphabet[map[nx][ny]]) continue;
			
			alphabet[map[nx][ny]] = true;
			result = Math.max(result, len+1);
			dfs(len + 1, nx, ny);
			alphabet[map[nx][ny]] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		tk = new StringTokenizer(br.readLine());
		r = Integer.parseInt(tk.nextToken());
		c = Integer.parseInt(tk.nextToken());
		map = new char[r][c];
		alphabet = new boolean[100];
		
		for(int i=0; i<r; i++) {
			String s = br.readLine();
			for(int j=0; j<c; j++) map[i][j] = s.charAt(j);
		}
		
		alphabet[map[0][0]] = true;
		dfs(1, 0, 0);
		System.out.println(result);
	}
}

