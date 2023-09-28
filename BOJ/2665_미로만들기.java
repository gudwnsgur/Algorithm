import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {

    int x;
    int y;
    int changed;

    Node(int x, int y, int changed) {
        this.x = x;
        this.y = y;
        this.changed = changed;
    }
}

class Main {

    static final int[] dx = new int[]{0, 0, 1, -1};
    static final int[] dy = new int[]{1, -1, 0, 0};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static boolean[][] maze;
    static int[][] visited;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.println(getResult());
    }

    public static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        maze = new boolean[n][n];
        visited = new int[n][n];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                maze[i][j] = str.charAt(j) == '1';
                visited[i][j] = Integer.MAX_VALUE;
            }
        }
    }

    public static int getResult() {
        Queue<Node> queue = new LinkedList();
        queue.add(new Node(0, 0, maze[0][0] ? 0 : 1));
        maze[0][0] = true;

        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            if(visited[cur.x][cur.y] <= cur.changed) continue;
            visited[cur.x][cur.y] = cur.changed;
            if(cur.x == n-1 && cur.y == n-1) continue;

            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + cur.x;
                int ny = dy[i] + cur.y;

                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    queue.add(new Node(nx, ny, maze[nx][ny] ? cur.changed : cur.changed+1));
                }
            }
        }
        return visited[n-1][n-1];
    }
}

