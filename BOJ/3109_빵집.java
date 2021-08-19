import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int r, c;
	static int cnt = 0;
	static char[][] map;
	static boolean[][] visited;
	static boolean fin = false;
	
	static boolean dfs(int x, int y) {
		if(y == c) {
			cnt++;
			visited[x][y] = fin = true;
			return visited[x][y];
		}
		
		for(int i=-1; i<=1; i++) {
			if(fin) break;
			int nx = x + i, ny = y + 1;
			if(nx <=0 || nx > r || ny > c) continue;
			if(map[nx][ny] == '.' && !visited[nx][ny]) visited[x][y] = dfs(nx, ny);
		}
		return visited[x][y] = true;
	}
	
	public static void main(String[] args) throws IOException {
		tk = new StringTokenizer(br.readLine());
		r = Integer.parseInt(tk.nextToken());
		c = Integer.parseInt(tk.nextToken());
		
		map = new char[r+1][c+1];
		visited = new boolean[r+1][c+1];
		
		for(int i=1; i<=r; i++) {
			String s = br.readLine();
			for(int j=1; j<=s.length(); j++) {
				map[i][j] = s.charAt(j-1);
			}
		}
		
		for(int i=1; i<=r; i++) {
			fin = false;
			visited[i][1] = dfs(i,1);
		}
		System.out.println(cnt);
	}

}

