import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int[][] dp;
    static String result = "";

    public static void main(String[] args) throws IOException {
        String a = br.readLine();
        String b = br.readLine();
        int n = a.length(), m = b.length();
        dp = new int[n+1][m+1];

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a.charAt(i-1) == b.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
            }
        }
        System.out.println(dp[n][m]);

        int x = n, y = m;
        while(dp[x][y] > 0) {
            if(dp[x][y] == dp[x-1][y]) x--;
            else if(dp[x][y] == dp[x][y-1]) y--;
            else {
                result += a.charAt(x-1);
                x--; y--;
            }
        }
        StringBuilder sb = new StringBuilder(result);
        System.out.println(sb.reverse().toString());
    }
}
