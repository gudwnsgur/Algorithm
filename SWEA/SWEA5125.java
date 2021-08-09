import java.io.*;
import java.util.*;

public class SWEA5125 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int tc, n, limitCal;
    static int[][] dp;
    static int[] score, cal;
    
    public static void main(String[] args) throws IOException{
    	tc = Integer.parseInt(br.readLine());
    	for(int t=1; t<=tc; t++) {
    		tk = new StringTokenizer(br.readLine());
    		n = Integer.parseInt(tk.nextToken());
    		limitCal = Integer.parseInt(tk.nextToken());
    		
    		dp = new int[n+1][limitCal+1];
    		score = new int[n+1];
    		cal = new int[n+1];
    		for(int i=1; i<=n; i++) {
    			tk = new StringTokenizer(br.readLine());	
    			score[i] = Integer.parseInt(tk.nextToken());
    			cal[i] = Integer.parseInt(tk.nextToken());
    		}
    		
    		for(int i=1; i<=n; i++) {
    			for(int j=1; j <= limitCal; j++) {
    				if(j - cal[i] >= 0) 
    					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j- cal[i]] + score[i]);
    				else dp[i][j] = dp[i-1][j];
    			}
    		}
    		sb.append("#").append(t).append(" ").append(dp[n][limitCal]).append("\n");
    	}
    	System.out.println(sb.toString());
	}
}

