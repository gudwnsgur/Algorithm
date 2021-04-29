import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair {
    int x, y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int r, c;
    static boolean[][] lake;
    static boolean[][] visited, v;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static Pair[] L = new Pair[2];

    public static boolean isPossible() {
        // lake의 상태로 L 이 만날 수 있는지 확인
        v = new boolean[r][c];
        Queue<Pair> queue = new LinkedList<>();
        queue.add(L[0]);
        v[L[0].x][L[1].y] = true;

        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i=0; i<size; i++) {
                Pair cur = queue.poll();
                for(int j=0; j<4; j++) {
                    int nx = cur.x + dx[j], ny = cur.y + dy[j];
                    if(nx == L[1].x && ny == L[1].y) return true;
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c || v[nx][ny] || !lake[nx][ny]) continue;
                    v[nx][ny] = true;
                    queue.add(new Pair(nx, ny));
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        r = Integer.parseInt(tk.nextToken());
        c = Integer.parseInt(tk.nextToken());
        lake = new boolean[r][c];
        visited = new boolean[r][c];
        Queue<Pair> water = new LinkedList<>();

        int l = 0;
        for (int i = 0; i < r; i++) {
            String str = br.readLine();
            for (int j = 0; j < c; j++) {
                char ch = str.charAt(j);
                if (ch != 'X') {
                    water.add(new Pair(i, j));
                    lake[i][j] = true;
                    visited[i][j] = true;
                }
                if (ch == 'L') L[l++] = (new Pair(i, j));
            }
        }

        int result = 0;
        while (!water.isEmpty()) {
            int size = water.size();
            for (int i = 0; i < size; i++) {
                Pair cur = water.poll();
                for (int j = 0; j < 4; j++) {
                    int nx = cur.x + dx[j], ny = cur.y + dy[j];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
                    if (!lake[nx][ny]) {
                        visited[nx][ny] = true;
                        water.add(new Pair(nx, ny));
                    }
                }
            }

            size = water.size();
            for (int i = 0; i < size; i++) {
                Pair cur = water.poll();
                lake[cur.x][cur.y] = true;
                water.add(cur);
            }

            result++;
            if(isPossible()) {
                System.out.println(result);
                return;
            }
        }
        System.out.println(result-1);
    }
}
