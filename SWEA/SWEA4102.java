import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, minDiff;
	static int[][] arr;
	static int[] teamA;
	static boolean[] visited;
	static boolean[] team;
	
	static int getDiff() {
		int teamA = 0, teamB = 0;
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				if(team[i] && team[j]) teamA += (arr[i][j] + arr[j][i]);
				else if(!team[i] && !team[j]) teamB += (arr[i][j] + arr[j][i]);
			}
		}
		return Math.abs(teamA - teamB);
	}
	
	static void dfs(int len, int m) {
		if(len == m) {
			team = new boolean[n];
			for(int i=0; i<len; i++) {
				team[teamA[i]] = true;
			}
			minDiff = Math.min(minDiff, getDiff());
			return;
		}
		
		for(int i=0; i<n; i++) {
			if(!visited[i] && (len == 0 || teamA[len-1] < i)) {
				visited[i] = true;
				teamA[len] = i;
				dfs(len+1, m);
				visited[i] = false;
			}
		}
		
	}
	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for(int t =1 ; t<=tc; t ++) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n][n];
			
			for(int i=0; i<n; i++) {
				tk = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					arr[i][j] = Integer.parseInt(tk.nextToken());
				}
			}
			
			minDiff = Integer.MAX_VALUE;
			visited = new boolean[n];
			teamA = new int[n/2];
			dfs(0, n/2);
			System.out.println("#" + t + " " + minDiff);
		}
	}
}
