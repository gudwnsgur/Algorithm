import java.io.*;
import java.util.*;

class Loc {
	int x, y;
	Loc(int x, int y ) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static final int[] dx = {-1, 0, 0, 1};
	static final int[] dy = {0, -1, 1, 0};
	static int n;
	static int time = 0, sharkSize = 2, eatCnt = 0; 
	static Loc shark;
	static int[][] space;
	static boolean[][] visited;
	static Queue<Loc> q = new LinkedList<>();
	static ArrayList<Loc> candidate = new ArrayList<>();
	 
	static int[] getNextLocation() {
		 visited = new boolean[n][n];
		 visited[shark.x][shark.y] = true;
		 
		 q.clear();
		 q.add(new Loc(shark.x, shark.y));
		 candidate.clear();
		 
		 int time = 0;
		 while(!q.isEmpty()) {
			 int size = q.size();
			 for(int s = 0; s<size; s++) {
				 Loc cur = q.poll();
			 	if(space[cur.x][cur.y] != 0 && sharkSize > space[cur.x][cur.y]) 
			 		candidate.add(new Loc(cur.x, cur.y));
			 
			 	for(int i=0; i<4; i++) {
				 	int nx = cur.x + dx[i];
				 	int ny = cur.y + dy[i];
				 	if(nx < 0 || nx >=n || ny < 0 || ny >= n ||
						 sharkSize < space[nx][ny]  || visited[nx][ny]) continue;
				 
				 	visited[nx][ny] = true;
				 	q.add(new Loc(nx, ny));
			 	}
			 }
			 if(!candidate.isEmpty()) {
				 Collections.sort(candidate, new Comparator<Loc>(){
					 @Override
					 public int compare(Loc a, Loc b) {
						 if(a.x == b.x) return Integer.compare(a.y, b.y);
						 return Integer.compare(a.x, b.x);
					 }
				 });
				 return new int[] {candidate.get(0).x, candidate.get(0).y, time};
			 }
			 time++;
		 }
		 
		return new int[] {-1,-1,-1};
	}
	
	static int getDist(Loc a, Loc b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}
	
	public static void main(String[] args) throws Exception {
		 n = Integer.parseInt(br.readLine());
		 space = new int[n][n];
		 for(int i=0; i<n; i++) {
			 tk = new StringTokenizer(br.readLine());
			 for(int j=0; j<n; j++) {
				 space[i][j] = Integer.parseInt(tk.nextToken());
				 if(space[i][j] == 9) {
					 space[i][j] = 0;
					 shark = new Loc(i, j);
				 }
			 }
		 }
		 
		 
		 while(true) {
			 int[] info = getNextLocation();
			 Loc next = new Loc(info[0], info[1]);
			 if(next.x == -1 && next.y == -1) break;

			 time += info[2];
			 space[next.x][next.y] = 0;
			 shark = new Loc(next.x, next.y);
			 
			 eatCnt++;
			 if(sharkSize == eatCnt) {
				 sharkSize++;
				 eatCnt = 0;
			 }
//			 System.out.println("(" + (next.x+1) + "," + (next.y+1) + ")" + " T " + 
//			 time + " | 크기 " + sharkSize + " | 먹은 개수 " + eatCnt);
		 }
		 
		 System.out.println(time);
	}
}

