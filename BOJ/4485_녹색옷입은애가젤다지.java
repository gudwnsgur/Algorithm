import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair {
    int x, y;
    int value;

    Pair(int x, int y, int value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] dist;
    static int[][] map;

    static int dijkstra(int x, int y, int n) {
        dist[x][y] = map[x][y];
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.value < o2.value) return -1;
                else if (o1.value > o2.value) return 1;
                return 0;
            }
        });

        pq.add(new Pair(x, y, map[x][y]));
        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + cur.x, ny = dy[i] + cur.y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[cur.x][cur.y] + map[nx][ny] >= dist[nx][ny]) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + map[nx][ny];
                pq.add(new Pair(nx, ny, dist[nx][ny]));
            }
        }
        return dist[n-1][n-1];
    }

    static void solution(int n, int number) throws IOException {
        dist = new int[n][n];
        map = new int[n][n];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
        System.out.println("Problem " + number + ": " + dijkstra(0, 0, n));
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int number = 1;
        while (n != 0) {
            solution(n, number);
            number++;
            n = Integer.parseInt(br.readLine());
        }
    }
}
