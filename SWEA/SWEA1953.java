import java.io.*;
import java.util.*;
 
class Loc {
    int x,y;
    Loc(int x, int y ) {
        this.x = x;
        this.y = y;
    }
}
public class Solution {
    static final int[][] dx = {{}, {0, 0, -1, 1}, {-1, 1}, {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static final int[][] dy = {{}, {1, -1, 0, 0}, {0, 0}, {-1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
     
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, r, c, l;
    static int[][] map;
    static boolean[][] visited;
     
    static boolean check(int cx, int cy, int nx, int ny) {
        int info = map[nx][ny];
        for(int i=0; i<dx[info].length; i++) {
            if(dx[info][i] == (cx-nx) && dy[info][i] == (cy-ny)) return true;
        }
        return false;
    }
     
    static int solution() {
        Queue<Loc> q = new LinkedList<>();
        q.add(new Loc(r, c));
        visited[r][c] = true;
         
        int day = 1;
        while(!q.isEmpty()) {
            if(day == l) break;
            int size = q.size();
            for(int s = 0; s<size; s++) {
                Loc cur = q.poll();
                int info = map[cur.x][cur.y];
             
                for(int i=0; i<dx[info].length; i++) {
                    int nx = cur.x + dx[info][i];
                    int ny = cur.y + dy[info][i];
                 
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] ) continue;
                    if(map[nx][ny] == 0) continue;
                    if(!check(cur.x, cur.y, nx, ny)) continue;
                     
                    visited[nx][ny] = true;
                    q.add(new Loc(nx, ny));
                }
            }
            day++;
        }
         
        int result = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visited[i][j]) result++;
            }
        }
        return result;
    }
     
    public static void main(String[] args) throws Exception {
        int tc = Integer.parseInt(br.readLine());
        for(int t=1; t<=tc; t++) {
            tk = new StringTokenizer(br.readLine());
            n = Integer.parseInt(tk.nextToken());
            m = Integer.parseInt(tk.nextToken());
            r = Integer.parseInt(tk.nextToken());
            c = Integer.parseInt(tk.nextToken());
            l = Integer.parseInt(tk.nextToken());
 
            visited = new boolean[n][m];
            map = new int[n][m];
            for(int i=0; i<n; i++) {
                tk = new StringTokenizer(br.readLine());
                for(int j=0; j<m; j++) {
                    map[i][j] = Integer.parseInt(tk.nextToken());
                }
            }
             
            System.out.println("#" + t + " " + solution());
        }
    }
}
