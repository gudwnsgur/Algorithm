import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	public static int [][] map = new int[21][21];
	
	public static boolean isFive(int x, int y) {
		if(map[x][y] == 0) return false;
		int cnt;
		
		
		// 오른쪽 위로 5개까지 연결될 수 있는지
		// 5개가 채워질 칸이 있으면서 그 라인의 전에 있는 돌과 같은 돌이 아니어야 한다.(기준이어야 하므로)
		if(x-4 > 0 && y+4 < 20 && map[x+1][y-1] != map[x][y]) {
			cnt = 1;
			int nextX = x-1, nextY = y+1;
			for(int i=0; i<4; i++) {
				if(map[nextX--][nextY++] == map[x][y]) cnt++;
			}
			
			if(cnt == 5) {
				if(nextX <= 0 || nextY >= 20 || map[nextX][nextY] != map[x][y]) return true;
			}
		}
		
		// 오른쪽으로 5개까지 연결될 수 있는지
		// 5개가 채워질 칸이 있으면서 그 라인의 전에 있는 돌과 같은 돌이 아니어야 한다.(기준이어야 하므로)
		if(y + 4 < 20 && map[x][y-1] != map[x][y]) {
			cnt = 1;
			int nextY = y+1;
			for(int i=0; i<4; i++) {
				if(map[x][nextY++] == map[x][y]) cnt++;
			}
			if(cnt == 5) {
				if(nextY >= 20 || map[x][nextY] != map[x][y]) return true;
			}
		}
		
		// 오른쪽 아래로 5개까지 연결될 수 있는지
		// 5개가 채워질 칸이 있으면서 그 라인의 전에 있는 돌과 같은 돌이 아니어야 한다.(기준이어야 하므로)
		if(x + 4 < 20 && y+4 < 20 && map[x-1][y-1] != map[x][y]) {
			cnt = 1;
			int nextX = x+1, nextY = y+1;
			for(int i=0; i<4; i++) {
				if(map[nextX++][nextY++] == map[x][y]) cnt++;
			}
			
			if(cnt == 5) {
				if(nextX >= 20 || nextY >= 20 || map[nextX][nextY] != map[x][y]) return true;
			} 
		}
		
		// 아래로 5개까지 연결될 수 있는지
		// 5개가 채워질 칸이 있으면서 그 라인의 전에 있는 돌과 같은 돌이 아니어야 한다.(기준이어야 하므로)
		if(x + 4 < 20 && map[x-1][y] != map[x][y]) {
			cnt = 1;
			int nextX = x+1;
			for(int i=0; i<4; i++) {
				if(map[nextX++][y] == map[x][y]) cnt++;
			}
			
			if(cnt == 5) {
				if(nextX >= 20 || map[nextX][y] != map[x][y]) return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		// 입력
		for(int i=1; i<=19; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=1; j<=19; j++ ) {
				map[i][j] = Integer.parseInt(tk.nextToken());
			}
		}
		
		for(int i=1; i<=19; i++) {
			for(int j=1; j<=19; j++) {
				// (i, j) 기준으로 오목이 형성되면 출력 후 종료
				if(isFive(i, j)) {
					System.out.println(map[i][j]);
					System.out.println(i + " " + j);
					return;
				}
			}
		}
		// 승부가 나지 않은 상태
		System.out.println(0);
	}
}

