import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws Exception {
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[1000001];
		dp[1] = 0;
		dp[2] = dp[3] = 1;
		
		for(int i=4; i<=n; i++) {
			if(i % 2 == 0 && i % 3 == 0) dp[i] = Math.min(dp[i-1], Math.min(dp[i/2], dp[i/3])) + 1;
			else if(i % 3 == 0) dp[i] = Math.min(dp[i-1], dp[i/3]) + 1;
			else if(i % 2 == 0) dp[i] = Math.min(dp[i-1], dp[i/2]) + 1;
			else dp[i] = dp[i-1] +1;
		}
		System.out.println(dp[n]);
	}
}
