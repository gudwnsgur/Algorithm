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
    static int h, w;
    static int[][] sandCastle;
    static boolean[][] visited;
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    static boolean willBeErase(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (sandCastle[x + dx[i]][y + dy[i]] == 0) cnt++;
        }
        return sandCastle[x][y] <= cnt;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        h = Integer.parseInt(tk.nextToken());
        w = Integer.parseInt(tk.nextToken());
        sandCastle = new int[h][w];
        visited = new boolean[h][w];
        Queue<Pair> erase = new LinkedList<>();

        for (int i = 0; i < h; i++) {
            String str = br.readLine();
            for (int j = 0; j < w; j++) {
                if(str.charAt(j) != '.') sandCastle[i][j] = str.charAt(j)-'0';
                else {
                    sandCastle[i][j] = 0;
                    erase.add(new Pair(i, j));
                    visited[i][j] = true;
                }
                sandCastle[i][j] =  (str.charAt(j) == '.' ? 0 : str.charAt(j)-'0');
            }
        }

        int result = -1;
        while(!erase.isEmpty())
        {
            int size = erase.size();
            result++;
            // 추가
            for(int i=0; i<size; i++) {
                Pair pair = erase.poll();
                for(int j=0; j<8; j++) {
                    int nx = pair.x+dx[j], ny = pair.y+dy[j];
                    if(nx <0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny]) continue;
                    if(sandCastle[nx][ny] != 0 && willBeErase(nx, ny)) {
                        visited[nx][ny] = true;
                        erase.add(new Pair(nx,ny));
                    }
                }
            }
            // 삭제
            size = erase.size();
            for(int i=0; i<size; i++) {
                Pair pair = erase.poll();
                sandCastle[pair.x][pair.y] = 0;
                erase.add(pair);
            }

        }
        System.out.println(result);
    }
}
