import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int d, p;
    static final int MAX = 100000;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        d = Integer.parseInt(tk.nextToken());
        p = Integer.parseInt(tk.nextToken());
        int[] dp = new int[100001];

        for(int i=0; i<p; i++) {
            tk = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(tk.nextToken());
            int cap = Integer.parseInt(tk.nextToken());

            for(int j = d; j >= len; j--) {
                if(dp[j-len] != 0) dp[j] = Math.max(dp[j], (Math.min(dp[j-len], cap)));
            }
            dp[len] = Math.max(dp[len], cap);
        }
        System.out.println(dp[d]);
    }
}
