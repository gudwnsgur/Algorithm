import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int k = Integer.parseInt(tk.nextToken());
        int[][] dp = new int[201][201];

        for (int i = 0; i <= 200; i++) dp[0][i] = 1;

        for (int i = 1; i <= 200; i++) {
            for (int j = 1; j <= 200; j++) {
                for (int l = i; l >= 0; l--) {
                    dp[i][j] += dp[l][j - 1];
                    dp[i][j] %= 1000000000;
                }
            }
        }
        System.out.println(dp[n][k]);
    }
}

