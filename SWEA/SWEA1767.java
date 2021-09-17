import java.io.*;
import java.util.*;

class Loc {
	int x,y;
	Loc(int x, int y ) {
		this.x = x;
		this.y = y;
	}
}

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n;
	static int result, cnt;
	static boolean[][] map;
	static ArrayList<Loc> core;
	static boolean pos;
	
	static void dfs(int len, int m, int curCnt, int curResult) {
		if(len == m) {
			if(cnt == curCnt) result = Math.min(result, curResult);
			else if(cnt < curCnt) {
				result = curResult;
				cnt = curCnt;
			}
			return;
		}
		Loc cur = core.get(len);
		

		// 위로 전선을 이을 수 있는지
		pos = true;
		for(int i=0; i<cur.x; i++) if(map[i][cur.y]) pos = false;

		if(pos) {
			for(int i=0; i<cur.x; i++) map[i][cur.y] = true;
			dfs(len+1, m, curCnt+1, curResult+cur.x);
			for(int i=0; i<cur.x; i++) map[i][cur.y] = false;
		}
		
		// 아래로 전선을 이을 수 있는지
		pos = true;
		for(int i=cur.x+1; i<n; i++) if(map[i][cur.y]) pos = false;
		
		if(pos) {
			for(int i=cur.x+1; i<n; i++) map[i][cur.y] = true;
			dfs(len+1, m, curCnt+1, curResult + ( (n-1) - cur.x ) );
			for(int i=cur.x+1; i<n; i++) map[i][cur.y] = false;
		}
		
		// 왼쪽으로 전선을 이을 수 있는지
		pos = true;
		for(int i=0; i<cur.y; i++) if(map[cur.x][i]) pos = false;
		
		if(pos) {
			for(int i=0; i<cur.y; i++) map[cur.x][i] = true;
			dfs(len+1, m, curCnt+1, curResult+cur.y);
			for(int i=0; i<cur.y; i++) map[cur.x][i] = false;
		}
		
		// 오른쪽으로 전선을 이을 수 있는지
		pos = true;
		for(int i=cur.y+1; i<n; i++) if(map[cur.x][i]) pos = false;
		
		if(pos) {
			for(int i=cur.y+1; i<n; i++) map[cur.x][i] = true;
			dfs(len+1, m, curCnt+1, curResult + ( (n-1) - cur.y ) );
			for(int i=cur.y+1; i<n; i++) map[cur.x][i] = false;
		}
		
		// 안쓰고 다음꺼 다썼을때 cnt 보다 크거나 같으면 dfs(len+1, m, curCnt, curResult)
		if( m-len-1 >= cnt-curCnt) dfs(len+1, m, curCnt, curResult);
	}
	
	static int solve() throws Exception {
		n = Integer.parseInt(br.readLine());
		map = new boolean[n][n];
		core = new ArrayList<>();
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = tk.nextToken().equals("1");
				if(map[i][j]) core.add(new Loc(i, j));
			}
		}
		
		cnt = 0;
		result = 0;
		dfs(0, core.size(), 0, 0);
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int i=1; i<=tc; i++) {
			System.out.println("#" + i + " " + solve());
		}
    }
}

