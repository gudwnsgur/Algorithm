import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    static int n;
    static int[][] forest, dp;
    static int result = 0;

    static int dfs(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || forest[nx][ny] <= forest[x][y]) continue;
            dp[x][y] = Math.max(dfs(nx, ny) + 1, dp[x][y]);
        }
        return dp[x][y];
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        forest = new int[n][n];
        dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                forest[i][j] = Integer.parseInt(tk.nextToken());
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                result =Math.max(result, dp[i][j]);
            }
        }
        System.out.println(result);
    }
}
