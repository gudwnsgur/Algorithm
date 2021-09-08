import java.util.*;
import java.io.*;

class Loc {
    int x, y;
    int crush;

    Loc(int x, int y) {
        this.x = x;
        this.y = y;
        crush = 0;
    }

    Loc(int x, int y, int crush) {
        this.x = x;
        this.y = y;
        this.crush = crush;
    }
}

class Main {
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, k;
    static boolean[][] map;
    static boolean[][][] visited; // x, y

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        map = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = str.charAt(j) == '1';
            }
        }

        visited = new boolean[n][m][k + 1];
        visited[0][0][0] = true;

        // (0,0) => (n-1, m-1)
        Queue<Loc> q = new LinkedList<>();
        q.add(new Loc(0, 0));
        int result = 1;
        while (!q.isEmpty()) {
//            System.out.println(result + "--------------------");
            int size = q.size();
            while (size-- > 0) {
                Loc cur = q.poll();
//                System.out.println("(" + cur.x + "," + cur.y + ")  [" + cur.crush + "]");
                if (cur.x == n - 1 && cur.y == m - 1) {
                    System.out.println(result);
                    return;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i], ny = cur.y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    int nCrush = map[nx][ny] ? cur.crush + 1 : cur.crush;
                    if (nCrush > k) continue;

                    boolean canBeUsed = true;
                    for (int j = 0; j <= nCrush; j++) {
                        if (visited[nx][ny][j]) {
                            canBeUsed = false;
                            break;
                        }
                    }
                    if (canBeUsed) {
                        q.add(new Loc(nx, ny, nCrush));
                        visited[nx][ny][nCrush] = true;
                    }
                }
            }
            result++;
        }
        System.out.println(-1);
    }
}


