import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int[][] map;
    static int n, m, target;
    static int targetX, targetY;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        target = Integer.parseInt(tk.nextToken());
        map = new int[n][m];
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt == target) {
                    targetX = i;
                    targetY = j;
                }
                map[i][j] = cnt++;
            }
        }

        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        for (int i = 0; i < m; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= targetX; i++) {
            for (int j = 1; j <= targetY; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        for (int i = targetX; i < n; i++)
            dp[i][targetY] = dp[targetX][targetY];
        for (int i = targetY; i < m; i++)
            dp[targetX][i] = dp[targetX][targetY];

        for (int i = targetX + 1; i < n; i++) {
            for (int j = targetY + 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        System.out.println(dp[n-1][m-1]);
    }
}

