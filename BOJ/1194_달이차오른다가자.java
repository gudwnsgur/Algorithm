import java.io.*;
import java.util.*;

class Loc {
	int x, y;
	Loc(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
class Node {
	int x, y, keyInfo, value;
	Node(int x, int y, int keyInfo, int value) {
		this.x = x;
		this.y = y;
		this.keyInfo = keyInfo;
		this.value = value;
	}
}

public class Main {
	static final int[] dx = {-1, 1, 0, 0};
	static final int[] dy = {0, 0, 1, -1};
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static char[][] maze;
    static boolean[][][] visited;
    static Loc minsik;
	
    static int solve() {
    	Queue<Node> q = new LinkedList<>();
    	q.add(new Node(minsik.x, minsik.y, 0, 1));
    	
    	while(!q.isEmpty()) {
    		Node cur = q.poll();
//    		System.out.println(cur.value + " : (" + cur.x + "," + cur.y + ") 를 " + cur.keyInfo + "로 확인");
    		visited[cur.x][cur.y][cur.keyInfo] = true;
			for(int i=0; i<4; i++) {
    			int nx = cur.x + dx[i];
    			int ny = cur.y + dy[i];
    			int nKeyInfo = cur.keyInfo;
    			
    			if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
    			
    			
    			// 000001 a 
    			// 000010 b
    			// 000100 c
    			// 001000 d
    			// 010000 e
    			// 100000 f
    			
    			if(maze[nx][ny] == '1') return cur.value; // 탈출
    			if(maze[nx][ny] == '#') continue; // 벽
    			if(maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F') {
    				if((nKeyInfo & (1 << maze[nx][ny] -'A')) == 0) continue;
    			} // 문을 열지 못할 때
    			
    			// key 정보 최신화
    			if(maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') {
    				nKeyInfo = nKeyInfo | (1 << maze[nx][ny] -'a');
    			}
    			
    			if(visited[nx][ny][nKeyInfo]) continue;
    			visited[nx][ny][nKeyInfo] = true;
    			q.add(new Node(nx, ny, nKeyInfo, cur.value+1));
    		}
    	}
    	return -1;
    }
    
	public static void main(String[] args) throws Exception {
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		
		visited = new boolean[n][m][64];
		maze = new char[n][m];
	
		
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			for(int j=0; j<m; j++) {
				maze[i][j] = str.charAt(j);
				if(maze[i][j] == '0') {
					maze[i][j] = '.';
					minsik = new Loc(i, j);
				}
			}
		}
		System.out.println(solve());
	}

}

