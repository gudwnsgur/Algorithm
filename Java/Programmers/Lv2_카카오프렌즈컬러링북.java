import java.util.*;

class Pair {
    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {

    int M, N;
    int numberOfArea = 0;
    int maxSizeOfOneArea = 0;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};

    boolean[][] visited;
    int[][] map;

    int bfs(int x, int y, int color) {
        int cnt = 1;
        visited[x][y] = true;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x, y));


        while (!q.isEmpty()) {
            int curX = q.element().first, curY = q.element().second;
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + curX, ny = dy[i] + curY;
                if (nx < 0 || nx >= M || ny < 0 || ny >= N )continue;
                if (visited[nx][ny] || map[nx][ny] != color) continue;
                visited[nx][ny] = true;
                q.add(new Pair(nx, ny));
                cnt++;
            }
            q.remove();
        }
        return cnt;
    }


    public int[] solution(int m, int n, int[][] picture) {
        M = m;
        N = n;
        visited = new boolean[m][n];
        map = new int[m][n];
        for (int i = 0; i < m; i++) System.arraycopy(picture[i], 0, map[i], 0, n);


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && map[i][j] != 0) {
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(i, j, map[i][j]));
                }
            }
        }


        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}

