import java.io.*;
import java.util.*;

class Loc {
	int x,y;
	Loc(int x, int y ) {
		this.x = x;
		this.y = y;
	}
}
class Dist {
	int s, e, value;
	Dist(int s, int e, int value) {
		this.s = s;
		this.e = e;
		this.value = value;
	}
}

public class Main {
	static final int INF = 987654321;
	static final int[] dx = {-1, 1, 0, 0};
	static final int[] dy = {0, 0, -1, 1};
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, m, result = -1;
	static int[][] numberedMap;
	static boolean[][] map, visited;
	

	static int island;
	static int[][] dist;
	
	static ArrayList<Dist> distArr;
	
	static int[] p;
	
	
	static void bfs(int x, int y, int no) {
		Queue<Loc> q = new LinkedList<>();
		q.add(new Loc(x, y));
		
		visited[x][y] = true;
		numberedMap[x][y] = no;
		
		while(!q.isEmpty()) {
			Loc cur = q.poll();
			for(int i=0; i<4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(!map[nx][ny] || visited[nx][ny] || numberedMap[nx][ny] != 0) continue;
				
				visited[nx][ny] = true;
				numberedMap[nx][ny] = no;
				q.add(new Loc(nx, ny));
			}
		}
	}
	
	
	static void numberingMap() {
		int no = 1;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(map[i][j] && !visited[i][j]) {
					bfs(i, j, no);
					no++;
				}
			}
		}
		island = no-1;
	}
	
	
	static void getDist() {
		for(int i=1; i<=island; i++) {
			Arrays.fill(dist[i], INF);
			dist[i][i] = 0;
		}
		
		boolean pos = false;
		for(int i=0; i<n*m-1; i++) {
			for(int j=i+1; j<n*m; j++) {
				Loc a = new Loc(i/m, i%m);
				Loc b = new Loc(j/m, j%m);
				int aNo = numberedMap[a.x][a.y];
				int bNo = numberedMap[b.x][b.y];
				if(aNo == 0 || bNo == 0 || aNo == bNo) continue;
				
				if(a.x == b.x && Math.abs(a.y-b.y) != 2) {
					pos = true;
					for(int k = Math.min(a.y, b.y)+1 ; k < Math.max(a.y, b.y); k++) {
						if(numberedMap[a.x][k] != 0) {
							pos = false;
							break;
						}
					}
					if(pos) {
						dist[aNo][bNo] = Math.min(dist[aNo][bNo], Math.abs(a.y-b.y)-1);
						dist[bNo][aNo] = dist[aNo][bNo];
					}
				}
				else if(a.y == b.y && Math.abs(a.x-b.x) != 2) {
					pos = true;
					for(int k = Math.min(a.x, b.x)+1 ; k < Math.max(a.x, b.x); k++) {
						if(numberedMap[k][a.y] != 0) {
							pos = false;
							break;
						}
					}
					if(pos) {
						dist[aNo][bNo] = Math.min(dist[aNo][bNo], Math.abs(a.x-b.x)-1);
						dist[bNo][aNo] = dist[aNo][bNo];
					}
				}
			}
		}
		
		for(int i=1; i<island; i++) {
			for(int j=i+1; j<=island; j++) {
				if(dist[i][j] != INF && dist[i][j] != 0)
					distArr.add(new Dist(i, j, dist[i][j]));
			}
		}
		Collections.sort(distArr, new Comparator<Dist>() {
			@Override
			public int compare(Dist o1, Dist o2) {
				return Integer.compare(o1.value, o2.value);
			}
		});
	}
	
	
	static void union(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		
		if(a < b) p[b] = a;
		else p[a] = b;
	}
	
	static int getParent(int node) {
		if(node == p[node]) return node;
		return p[node] = getParent(p[node]);
	}
	static int unionFind() {
		int cnt = 0, totalLen = 0;
		for(Dist cur : distArr) {
			if(getParent(cur.s) != getParent(cur.e)) {
				union(cur.s, cur.e);
				totalLen += cur.value;
				cnt++;
			}
		}
		return (cnt == island-1) ? totalLen : -1;
	}
	
	public static void main(String[] args) throws Exception{
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		
		map = new boolean[n][m];
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = tk.nextToken().equals("1");
			}
		}
		
		visited = new boolean[n][m];
		numberedMap = new int[n][m];
		numberingMap();
//		System.out.println();
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				System.out.print(numberedMap[i][j] + " ");
//			}
//			System.out.println();
//		}
//		System.out.println();

		
		dist = new int[island+1][island+1];
		distArr = new ArrayList<>();
		getDist();
		
//		for(int i=1; i<=island; i++) {
//			for(int j=1; j<=island; j++) {
//				System.out.print(dist[i][j] + " ");
//			}
//			System.out.println();
//		}
//		System.out.println();
		
		p = new int[island+1];
		for(int i=1; i<=island; i++) p[i] = i;
		System.out.println(unionFind());
	}
}


