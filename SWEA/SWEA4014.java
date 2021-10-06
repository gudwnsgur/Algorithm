import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, X;
	static int[][] map1, map2;
	static boolean[][] used;
	
	static boolean isRightRoad(int loc, boolean dir, int[] road) {
		 for (int i = 0; i < road.length; i++) {
	            if (i == 0) continue;
	            if (road[i] == road[i - 1]) continue;
	            if (Math.abs(road[i] - road[i - 1]) >= 2) return false;


	            if (road[i - 1] > road[i]) {
	                int j = i, x = dir ? loc : i, y = dir ? i : loc;
	                int cnt = 0, hegiht = road[i];
	                boolean pos = false;

	                for (; j < road.length; j++) {
	                    if (hegiht != road[j] || used[x][y]) break;
	                    used[x][y] = true;
	                    cnt++;
	                    if (cnt == X) {
	                        pos = true;
	                        break;
	                    }

	                    if (dir) y++;
	                    else x++;
	                }
	                if (!pos) return false;
	                i = j;
	            }

	            else {
	                int x = dir ? loc : i-1, y = dir ? i-1 : loc;
	                int cnt = 0, height = road[i - 1];
	                boolean pos = false;

	                for (int j = i - 1; j >= 0; j--) {
	                    if (height != road[j] || used[x][y]) break;
	                    used[x][y] = true;
	                    cnt++;

	                    if (cnt == X) {
	                        pos = true;
	                        break;
	                    }
	                    if (dir) y--;
	                    else x--;
	                }
	                if (!pos) return false;
	            }
	        }
	        return true;
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++) {
			tk = new StringTokenizer(br.readLine());
		    n = Integer.parseInt(tk.nextToken());
		    X = Integer.parseInt(tk.nextToken());
		    map1 = new int[n][n];
		    map2 = new int[n][n];


		    for (int i = 0; i < n; i++) {
		        tk = new StringTokenizer(br.readLine());
		        for (int j = 0; j < n; j++) {
		            int value = Integer.parseInt(tk.nextToken());
		            map1[i][j] = map2[j][i] = value;
		        }
		    }

		    int result = 0;
		    used = new boolean[n][n];
		    for (int i = 0; i < n; i++) if (isRightRoad(i, true, map1[i])) result++;
		    used = new boolean[n][n];
		    for (int i = 0; i < n; i++) if (isRightRoad(i, false, map2[i])) result++;

			System.out.println("#" + t + " " + result);
		}
	}

}

