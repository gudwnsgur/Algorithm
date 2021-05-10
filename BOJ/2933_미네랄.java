import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Loc {
    int x, y;
    Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static char[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 0, 1};
    static int[] dy = {0, 1, -1, 0};

    public static void moveCluster(ArrayList<Loc> tmp) {

        for (int i = 0; i < tmp.size(); i++) map[tmp.get(i).x][tmp.get(i).y] = '.';

        int descent = n-1;
        for (int i = 0; i < tmp.size(); i++) {
            Loc cur = tmp.get(i);
            if(cur.x == n-1) {
                descent = 0;
                break;
            }

            int j = cur.x + 1;
            for (; j<n && map[j][cur.y] == '.' ; j++) ;
            descent = Math.min(descent, j-cur.x-1);
        }
        for (int i = 0; i < tmp.size(); i++) map[tmp.get(i).x + descent][tmp.get(i).y] = 'x';
    }

    public static ArrayList<Loc> bfs(int x, int y) {
        boolean pos = (x == n - 1);
        ArrayList<Loc> result = new ArrayList<>();
        Queue<Loc> q = new LinkedList<>();

        result.add(new Loc(x, y));
        q.add(new Loc(x, y));

        while (!q.isEmpty()) {
            Loc cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '.' || visited[nx][ny]) continue;
                if (nx == n - 1) pos = true;
                visited[nx][ny] = true;
                q.add(new Loc(nx, ny));
                result.add(new Loc(nx, ny));
            }
        }

        if (pos) return new ArrayList<>();
        return result;
    }

    public static void solution(int x, int y) {
        map[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '.' || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            ArrayList<Loc> tmp = bfs(nx, ny);
            if (!tmp.isEmpty()) {
                moveCluster(tmp);
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        map = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) map[i][j] = s.charAt(j);
        }

        int tc = Integer.parseInt(br.readLine());
        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < tc; i++) {
            visited = new boolean[n][m];
            int height = Integer.parseInt(tk.nextToken());

            if (i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    if (map[n - height][j] == 'x') {
                        solution(n - height, j);
                        break;
                    }
                }
            }
            else {
                for (int j = m - 1; j >= 0; j--) {
                    if (map[n - height][j] == 'x') {
                        solution(n - height, j);
                        break;
                    }
                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
}
