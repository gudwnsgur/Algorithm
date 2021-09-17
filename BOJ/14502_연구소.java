import java.io.*;
import java.util.*;

class Loc {
	int x,y;
	Loc(int x, int y ) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static final int[] dx = {-1, 1, 0, 0};
	static final int[] dy = {0, 0, -1, 1};
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, m;
	static int[][] map;
	static ArrayList<Loc> emp = new ArrayList<>();
	
	static int bfs(Loc a, Loc b, Loc c) {
		Queue<Loc> q = new LinkedList<>();
		int[][] tmp = new int[n][m];
		boolean[][] visited = new boolean[n][m];

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				tmp[i][j] = map[i][j];
				if(tmp[i][j] == 2) {
					q.add(new Loc(i, j));
					visited[i][j] = true;
				}
			}
		}
		tmp[a.x][a.y] = tmp[b.x][b.y] = tmp[c.x][c.y] = 1;
		
		while(!q.isEmpty()) {
			Loc cur = q.poll();
			for(int i=0; i<4; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && tmp[nx][ny] == 0) {
					visited[nx][ny] = true;
					tmp[nx][ny] = 2;
					q.add(new Loc(nx, ny));
				}
			}
		}
		
		int cnt = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(tmp[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}
	
	public static void main(String[] args) throws Exception {
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		
		map = new int[n][m];
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(tk.nextToken());
				if(map[i][j] == 0 ) emp.add(new Loc(i, j));
			}
		}
		int result = Integer.MIN_VALUE;
		for(int i=0; i<emp.size()-2; i++) {
			for(int j=i+1; j<emp.size()-1; j++) {
				for(int k=j+1; k<emp.size(); k++) {
					Loc a = emp.get(i), b = emp.get(j), c = emp.get(k);
					if(map[a.x][a.y] == 0 && map[b.x][b.y] == 0 && map[c.x][c.y] == 0)
						result = Math.max(result, bfs(emp.get(i), emp.get(j), emp.get(k)));
				}
			}
		}
		System.out.println(result);
		
	}

}

