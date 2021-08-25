import java.io.*;
import java.util.*;

class Node {
	char ch;
	int x, y;
	Node(char ch, int x, int  y ) {
		this.ch = ch;
		this.x = x;
		this.y =y;
	}
}

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n ;
	static int[] dx = {1, -1, 0, 0 };
	static int[] dy = {0, 0, 1, -1};
	static char[][] map;
	static boolean[][] visited;
	
	static int bfs() {
		Queue<Node> q = new LinkedList<>();
		int result = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j]) {
					result++;
					visited[i][j] = true;
					q.add(new Node(map[i][j], i, j));
					
					while(!q.isEmpty()) {
						Node cur = q.poll();
						for(int k=0; k<4; k++) {
							int nx = dx[k] + cur.x;
							int ny = dy[k] + cur.y;
							if(nx <0 || nx >=n || ny <0 || ny>=n) continue;
							if(visited[nx][ny] || map[nx][ny] != cur.ch) continue;
							visited[nx][ny] = true;
							q.add(new Node(map[nx][ny], nx, ny));
						}
					}
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException{
		n = Integer.parseInt(br.readLine());
		map = new char[n][n];
		visited = new boolean[n][n];
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			for(int j=0; j<n; j++) map[i][j] = str.charAt(j);
		}
		
		System.out.print(bfs() + " ");
		visited = new boolean[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j] == 'R') map[i][j] = 'G';
			}
		}
		System.out.println(bfs());
	}

}

