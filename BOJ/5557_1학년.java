import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static long count = 0;
    static int[] num;

    public static void main(String[] args) throws IOException {
        initialize();
        long[][] dp = new long[n][21];
        dp[1][num[1]] = 1;

        // i 까지 해서 j 를 만들 수 있는 경우의 수
        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= 20; j++) {
                if (j - num[i] >= 0) dp[i][j] += dp[i - 1][j - num[i]];
                if (j + num[i] <= 20) dp[i][j] += dp[i - 1][j + num[i]];
            }
        }
        System.out.println(dp[n - 1][num[n]]);
    }

    private static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        num = new int[n + 1];

        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            num[i] = Integer.parseInt(tk.nextToken());
        }
    }
}

