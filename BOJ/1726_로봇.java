import java.util.*;
import java.io.*;

class Loc {
    int x, y, dir;

    Loc(int x, int y, int dir) {
        this.x = x;
        this.y = y;
        this.dir = dir;
    }
}

class Main {
    static final int[] realDir = {-1, 0, 2, 1, 3};
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1,  0, -1, 0};
    //  동, 남, 서, 북
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[][] map;
    static boolean[][][] visited;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        map = new int[n + 1][m + 1];
        visited = new boolean[n + 1][m + 1][4];

        for (int i = 1; i <= n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                map[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
        tk = new StringTokenizer(br.readLine());
        Loc start = new Loc(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()), realDir[Integer.parseInt(tk.nextToken())]);
        tk = new StringTokenizer(br.readLine());
        Loc end = new Loc(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()), realDir[Integer.parseInt(tk.nextToken())]);


        int cnt = 0;
        Queue<Loc> q = new LinkedList<>();
        q.add(start);
        visited[start.x][start.y][start.dir] = true;
        while (!q.isEmpty()) {
//            System.out.println(cnt  + "-----------------------------");
            int size = q.size();
            while (size-- > 0) {
                Loc cur = q.poll();
//                System.out.println("(" + cur.x + "," + cur.y + ") :" + (cur.dir == 0 ? ">" : cur.dir ==1 ? "V" : cur.dir ==2 ? "<" : "^" ));
                if (cur.x == end.x && cur.y == end.y && cur.dir == end.dir) {
                    System.out.println(cnt);
                    return;
                }

                // 1. Go
                int nx = cur.x + dx[cur.dir], ny= cur.y + dy[cur.dir];
                if( nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] == 0) {
                    if(!visited[nx][ny][cur.dir]) {
                        visited[nx][ny][cur.dir] =true;
                        q.add(new Loc(nx,ny,cur.dir));
//                        System.out.println(nx + " " + ny);
                    }
                    nx += dx[cur.dir];
                    ny += dy[cur.dir];
                    if( nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] == 0) {
                        if(!visited[nx][ny][cur.dir]) {
                            visited[nx][ny][cur.dir] = true;
                            q.add(new Loc(nx, ny, cur.dir));
//                            System.out.println(nx + " " + ny);
                        }
                        nx += dx[cur.dir];
                        ny += dy[cur.dir];
                        if( nx > 0 && nx <= n && ny > 0 && ny <= m && !visited[nx][ny][cur.dir] && map[nx][ny] == 0) {
                            visited[nx][ny][cur.dir] = true;
                            q.add(new Loc(nx,ny,cur.dir));
//                            System.out.println(nx + " " + ny);

                        }
                    }
                }

                // 2. Turn Left
                if(!visited[cur.x][cur.y][(cur.dir+3)%4] && map[cur.x][cur.y] == 0) {
                    visited[cur.x][cur.y][(cur.dir+3)%4] = true;
                    q.add(new Loc(cur.x, cur.y, (cur.dir+3)%4));
                }
                // 3. Turn Right
                if(!visited[cur.x][cur.y][(cur.dir+1)%4] && map[cur.x][cur.y] == 0) {
                    visited[cur.x][cur.y][(cur.dir+1)%4] = true;
                    q.add(new Loc(cur.x, cur.y, (cur.dir+1)%4));
                }
            }
            cnt++;
        }
        System.out.println(cnt);
    }
}


