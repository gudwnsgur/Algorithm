import java.io.*;
import java.util.*;

class Loc {
	int x, y;
	Loc(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Solution {
	static final int[] dx = {-1, 1, 0, 0};
	static final int[] dy = {0, 0, -1, 1};
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	
	static int result;
	static int n, w, h;
	static int[][] map;
	static int[] arr;
	static boolean[][] visited;
	
	static int simulate() {
		int cnt = 0;
		int[][] tmp = new int[h][w];
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
					tmp[i][j] = map[i][j];
				}
		}
		
		
		Queue<Loc> q = new LinkedList<>();
		ArrayList<Loc> erased = new ArrayList<>();
		
		
		for(int i=0; i<n; i++) {
			q.clear();
			erased.clear();
			visited = new boolean[h][w];
			
			int x = 0;
			while(x < h && tmp[x][arr[i]] == 0) x++;
			if(x >= h) continue;
			
			q.add((new Loc(x, arr[i])));
			while(!q.isEmpty()) {
				Loc cur = q.poll();
				erased.add(cur);
				
				for(int j=0; j<4; j++) {
					for(int k=1; k<tmp[cur.x][cur.y] ; k++) {
						int nx = cur.x + dx[j]*k;
						int ny = cur.y + dy[j]*k;
						
						if(nx <0 || nx >= h || ny < 0 || ny >= w) continue;
						if(visited[nx][ny] || tmp[nx][ny] == 0) continue;
						
						visited[nx][ny] = true;
						q.add(new Loc(nx, ny));
					}
				}
			}
			for(Loc erase : erased) {
				tmp[erase.x][erase.y] = 0;
			}
			
			int [][] nextTmp = new int[h][w];
			for(int ii=0; ii<w; ii++) {
				ArrayList<Integer> num = new ArrayList<>();
				for(int jj=h-1; jj>=0; jj--) {
					if(tmp[jj][ii] != 0) num.add(tmp[jj][ii]);
				}
				for(int idx=0, jj=h-1; idx < num.size(); idx++,jj--) {
					nextTmp[jj][ii] = num.get(idx);
				}
			}
			for(int ii=0; ii<h; ii++) {
				for(int jj=0; jj<w; jj++) {
					tmp[ii][jj] = nextTmp[ii][jj];
				}
			}
		}
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(tmp[i][j] != 0 ) cnt++;
			}
		}
		return cnt;
	}
	
	static void dfs(int len) {
		if(len == n) {
			int curRes = simulate();
			result = Math.min(result, curRes);
			return;
		}
		for(int i=0; i<w; i++) {
			arr[len] = i;
			dfs(len+1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++) {
			tk = new StringTokenizer(br.readLine());
			n = Integer.parseInt(tk.nextToken());
			w = Integer.parseInt(tk.nextToken());
			h = Integer.parseInt(tk.nextToken());
			result = w*h;

			map = new int[h][w];
			for(int i=0; i<h; i++) {
				tk = new StringTokenizer(br.readLine());
				for(int j=0; j<w; j++) {
					map[i][j] = Integer.parseInt(tk.nextToken());
				}
			}

			arr = new int[n];
			dfs(0);
			
			System.out.println("#" + t + " " + result);
		}
		
	}

}
