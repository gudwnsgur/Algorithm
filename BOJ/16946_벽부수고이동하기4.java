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
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, 1, -1};
    static int n, m;
    static int[][] result, group;
    static boolean[][] wall, visited;
    static ArrayList<Integer> groupSize = new ArrayList<>();

    public static int bfs(int x, int y, int idx) {
        int cnt = 1;
        Queue<Loc> queue = new LinkedList<>();
        queue.add(new Loc(x, y));

        while (!queue.isEmpty()) {
            Loc cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + cur.x, ny = dy[i] + cur.y;
                if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if (!visited[nx][ny] && !wall[nx][ny]) {
                    visited[nx][ny] = true;
                    group[nx][ny] = idx;
                    queue.add(new Loc(nx, ny));
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static int count(int x, int y) {
        if(!wall[x][y]) return 0;
        int cnt = 1;

        Set<Integer> set = new HashSet<>();
        for(int i=0; i<4; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if(group[nx][ny] == 0 || set.contains(group[nx][ny])) continue;
            set.add(group[nx][ny]);
            cnt += groupSize.get(group[nx][ny]);
        }
        return cnt%10;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        wall = new boolean[n + 1][m + 1];
        result = new int[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1];
        group = new int[n+2][m+2];
        groupSize.add(0);

        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            for (int j = 1; j <= m; j++) wall[i][j] = s.charAt(j - 1) == '1';
        }

        int idx = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!visited[i][j] && !wall[i][j]) {
                    visited[i][j] = true;
                    group[i][j] = idx;
                    groupSize.add(bfs(i, j, idx));
                    idx++;
                }
            }
        }
//
//        for(int i=0; i<groupSize.size(); i++) {
//            System.out.println(groupSize.get(i));
//        }
//
//        for(int i=0; i<=n; i++) {
//            for(int j=0; j<=m;j++) {
//                System.out.print(group[i][j] + " ");
//            }
//            System.out.println();
//        }

        // groupSize, group
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                result[i][j] = count(i, j);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) System.out.print(result[i][j]);
            System.out.println();
        }
    }
}

