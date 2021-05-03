import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int result = Integer.MAX_VALUE;
    static int[] flower = new int[3];
    static int[][] map;
    static boolean[][] existed;
    static int[] dx = {1, -1, 0, 0, 0};
    static int[] dy = {0, 0, 0, -1, 1};

    static void dfs(int length, int m) {
        if (length == m) {
            int local = 0;
            for (int i = 0; i < 3; i++) {
                local += flower[i];
            }
            result = Math.min(result, local);
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                boolean pos = true;
                for (int k = 0; k < 5; k++) {
                    if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= n ||
                            (existed[i + dx[k]][j + dy[k]])) {
                        pos = false;
                        break;
                    }
                }
                if (!pos) continue;
                int res = 0;
                for (int k = 0; k < 5; k++) {
                    res += map[i+dx[k]][j+dy[k]];
                    existed[i+dx[k]][j+dy[k]] = true;
                }
                flower[length] = res;
                dfs(length+1, m);
                for(int k=0 ;k<5; k++) existed[i+dx[k]][j+dy[k]] = false;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        existed = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
        dfs(0, 3);
        System.out.println(result);
    }
}
