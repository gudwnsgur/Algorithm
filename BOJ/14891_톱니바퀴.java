import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int k;
	static int[][] magnet;
	static int[][] info;
	
	static int solution() {
		int[] idx = {0, 0, 0, 0};
		for(int i=0; i<info.length; i++) {
			int[] change = new int[4];
			change[info[i][0]] = info[i][1];
			
			for(int j= info[i][0]-1; j>=0 ; j--) {
				if(magnet[j][(idx[j] + 2)%8] == magnet[j+1][(idx[j+1] + 6)%8]) break;
				change[j] = change[j+1] * -1;
			}
			for(int j=info[i][0]+1; j<4; j++) {
				if(magnet[j][(idx[j] + 6)%8] == magnet[j-1][(idx[j-1] + 2)%8]) break;
				change[j] = change[j-1] * -1;
			}
			
			for(int j=0; j<4; j++) 
				idx[j] = (idx[j] + (change[j] * -1) + 8) % 8;
		}
		
		
		int result = 0;
		for(int i=0, score=1; i<4; i++, score *=2) {
			if(magnet[i][idx[i]] == 1) result += score;
		}
		return result;
	}
	
	
	public static void main(String[] args) throws Exception {
			magnet = new int[4][8];
			for(int i=0; i<4; i++) {
				String str = br.readLine();
				for(int j=0; j<8; j++) magnet[i][j] = str.charAt(j) == '1' ? 1:0;
			}
        
			k = Integer.parseInt(br.readLine());
			info = new int[k][2];
			for(int i=0; i<k; i++) {
				tk = new StringTokenizer(br.readLine());
				info[i][0] = Integer.parseInt(tk.nextToken()) - 1;
				info[i][1] = Integer.parseInt(tk.nextToken());
			}
        System.out.println(solution());
	}
}

