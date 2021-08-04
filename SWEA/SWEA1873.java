import java.io.*;
import java.util.*;


public class SWEA1873 {

	static final int[] dx = {-1, 1, 0, 0};
	static final int[] dy = { 0, 0,-1, 1};	
						   // U  D  L  R
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	static int H, W, N;
	static String str;
	static char[][] map;
	static int x, y, dir;
	

	
	static void input() throws IOException {
		tk = new StringTokenizer(br.readLine());
		H = Integer.parseInt(tk.nextToken());
		W = Integer.parseInt(tk.nextToken());
		map = new char[H][W];
		
		for(int j=0; j<H; j++) {
			String tmp = br.readLine();
			for(int k=0; k<W; k++) {
				map[j][k] = tmp.charAt(k);
				if(map[j][k] == '^' || map[j][k] == 'v' || map[j][k] == '<' || map[j][k] == '>')  {
					x = j; 
					y = k;
					if(map[j][k] == '^') dir = 0;
					else if(map[j][k] == 'v') dir = 1;
					else if(map[j][k] == '<') dir = 2;
					else dir = 3;
					
					map[j][k] = '.';
				}
			}
		}
		N = Integer.parseInt(br.readLine());
		str = br.readLine();
	}
	
	static void saveOutput(int tc) {
		sb.append("#").append(tc).append(" ");
		for(int h=0; h<H; h++) {
			for(int w=0; w<W; w++) {
				sb.append(map[h][w]);
			}
			sb.append("\n");
		}
	}
	
	static void move(char op) {
		if(op == 'U') dir = 0;
		else if(op == 'D') dir = 1;
		else if(op == 'L') dir = 2;
		else dir = 3;
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if(nx < 0 || nx >= H || ny < 0 || ny >= W || map[nx][ny] != '.') return;
		x = nx;
		y = ny;
	}
	
	static void shoot() {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		while(nx >= 0 && nx < H && ny >= 0 && ny < W) {
			if(map[nx][ny] == '*') {
				map[nx][ny] = '.';
				return;
			} // 벽돌 벽을 만나면 벽이 파괴되어 평지가 되고 포탄은 사라진다.
			else if(map[nx][ny] == '#') return; // 강철벽을 만나면 아무 일도 일어나지 않는다.
			
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	
	
	public static void main(String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=tc ; i++) {
			input();
			for(int j=0; j<N; j++) {
				if(str.charAt(j) == 'S') shoot();
				else move(str.charAt(j));
			}
			
			if(dir == 0) map[x][y] = '^';
			else if(dir == 1) map[x][y] = 'v';
			else if(dir == 2) map[x][y] = '<';
			else map[x][y] = '>';
			
			saveOutput(i);
		}
		System.out.println(sb.toString());
	}

}
