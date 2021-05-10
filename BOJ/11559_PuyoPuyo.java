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
    static Stack<Character> stack = new Stack<>();
    static final char[] color = {'R', 'G', 'B', 'P', 'Y'};
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static char[][] map;
    static boolean[][] visited;
    static ArrayList<Loc> exploded = new ArrayList<>();

    static ArrayList<Loc> bfs(int x, int y, char color) {
        Queue<Loc> q = new LinkedList<>();
        ArrayList<Loc> cur = new ArrayList<>();
        visited[x][y] = true;
        cur.add(new Loc(x,y));
        q.add(new Loc(x, y));

        while(!q.isEmpty()) {
            Loc loc = q.poll();
            for(int i=0; i<4; i++) {
                int nx = loc.x + dx[i], ny = loc.y + dy[i];
                if(nx < 0 || nx >= 12 || ny <0 || ny >= 6) continue;
                if(visited[nx][ny] || map[nx][ny] != color) continue;
                q.add(new Loc(nx,ny));
                cur.add(new Loc(nx,ny));
                visited[nx][ny] = true;
            }
        }

        return cur;
    }
    public static void main(String[] args) throws IOException {
        map = new char[12][6];
        for(int i=0; i<12; i++) {
            String s = br.readLine();
            for(int j=0; j<6; j++) {
                map[i][j] = s.charAt(j);
            }
        }

        for(int cnt=0; ; cnt++) {
            exploded.clear();
            visited = new boolean[12][6];

            for(int i=0; i<12; i++) {
                for(int j=0; j<6; j++) {
                    if(visited[i][j] || map[i][j] == '.') continue;
                    ArrayList<Loc> cur = bfs(i, j, map[i][j]);
                    if(cur.size() >= 4) exploded.addAll(cur);
                }
            }
            if(exploded.isEmpty()) {
                System.out.println(cnt);
                return;
            }

            for(int i=0; i<exploded.size(); i++) {
                map[exploded.get(i).x][exploded.get(i).y] = '.';
            }

            for(int i=0; i<6; i++) {
                stack.clear();
                for(int j=0; j<12; j++) {
                    if(map[j][i] != '.') {
                        stack.add(map[j][i]);
                        map[j][i] = '.';
                    }
                }
                for(int j=11; !stack.isEmpty(); j--) {
                    map[j][i] = stack.pop();
                }
            }
        }
    }
}
