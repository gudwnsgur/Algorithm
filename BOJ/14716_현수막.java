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
    static final int[] dx = {1, -1, 0, 0, 1, -1, -1, 1};
    static final int[] dy = {0, 0, 1, -1, -1, 1, -1, 1};
    static boolean[][] map, visited;
    static int n, m, cnt = 0;

    static void bfs(int x, int y) {
        cnt++;
        visited[x][y] = true;
        Queue<Loc> q = new LinkedList<>();
        q.add(new Loc(x, y));

        while(!q.isEmpty()) {
            Loc cur = q.poll();
            for(int i=0; i<8; i++) {
                int nx = cur.x + dx[i] , ny = cur.y + dy[i];
                if(nx <0 || nx >=n || ny < 0 || ny >=m || !map[nx][ny] || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.add(new Loc(nx, ny));
            }
        }
    }


    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        map = new boolean[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) map[i][j] = tk.nextToken().equals("1");
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!visited[i][j] && map[i][j]) bfs(i, j);
        System.out.println(cnt);
    }
}
