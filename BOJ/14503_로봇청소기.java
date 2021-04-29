import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Robot {
    int x, y, dir;
    Robot(int x, int y,int dir) {
        this.x= x;
        this.y = y;
        this.dir = dir;
    }
}
class Main {
    static final int[] dx = {-1, 0, 1, 0};
    static final int[] dy = {0, 1, 0, -1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int result = 0;
    static int[][] map;
    static boolean[][] visited;


    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        tk = new StringTokenizer(br.readLine());
        Robot robot = new Robot(
                Integer.parseInt(tk.nextToken()),
                Integer.parseInt(tk.nextToken()),
                Integer.parseInt(tk.nextToken())
        );

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++) {
                map[i][j] = Integer.parseInt(tk.nextToken());
            }
        }

        while(true) {
            if(map[robot.x][robot.y] == 1) break;
            if(!visited[robot.x][robot.y]) result++;
            visited[robot.x][robot.y] = true;

            int nextX= 0, nextY=0, nextDir=0;
            boolean pos = false;

            for(int i=3; i>=0; i--) {
                int nx = dx[(i+ robot.dir)%4] + robot.x;
                int ny = dy[(i+ robot.dir)%4] + robot.y;

                if(!visited[nx][ny] && map[nx][ny] == 0) {
                    pos = true;
                    nextX = nx;
                    nextY = ny;
                    nextDir = (i+ robot.dir)%4;
                    break;
                }
            }
            if(pos) robot = new Robot(nextX, nextY, nextDir);
            else robot = new Robot(robot.x + dx[(robot.dir + 2)%4],
                    robot.y + dy[(robot.dir + 2) %4], robot.dir);
        }
        System.out.println(result);
    }
}
