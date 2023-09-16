import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] memories, costs;

    public static void main(String[] args) throws IOException {
        initialize();
        int[][] dp = new int[n + 1][10000 + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 10000; j++) {
                if (costs[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - costs[i]] + memories[i]);
                }
            }
        }

        for (int i = 0; i <= 10000; i++) {
            if (dp[n][i] >= m) {
                System.out.println(i);
                return;
            }
        }
    }

    static void initialize() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        memories = new int[n + 1];
        costs = new int[n + 1];
        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            memories[i] = Integer.parseInt(tk.nextToken());
        }
        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            costs[i] = Integer.parseInt(tk.nextToken());
        }

    }
}

