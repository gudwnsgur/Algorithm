import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int[][] map;
    static boolean[][] visited;
    static boolean result = false;

    public static void dfs(int x, int y) {
        if (x == n - 1 && y == n - 1) {
            result = true;
            return;
        }
        visited[x][y] = true;
        if (x + map[x][y] < n && !visited[x + map[x][y]][y]) dfs(x + map[x][y], y);
        if (y + map[x][y] < n && !visited[x][y+map[x][y]]) dfs(x, y + map[x][y]);
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) map[i][j] = Integer.parseInt(tk.nextToken());
        }

        dfs(0, 0);
        System.out.println(result ? "HaruHaru" : "Hing");
    }
}
