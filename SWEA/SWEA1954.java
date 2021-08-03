import java.io.*;
import java.util.*;
 
public class SWEA1954 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
     
    static final int[] dx = {0, 1, 0, -1 };
    static final int[] dy = {1, 0, -1, 0 };
    public static void main(String[] args) throws IOException{
        int tc = Integer.parseInt(br.readLine());
         
        for(int t = 1; t<= tc;  t++) {
            int n = Integer.parseInt(br.readLine());
            int dir = 0, x =0, y = 0;
            int[][] map = new int[n][n];
         
            for(int num = 1; num <= n*n; num++) {
                map[x][y] = num;
             
                // change dir
                int tmpX = x + dx[dir];
                int tmpY = y + dy[dir];
                if(tmpX < 0 || tmpX >=n || tmpY < 0 || tmpY >= n ||
                    (map[tmpX][tmpY] != 0)) dir = (dir+1)%4;
             
                x += dx[dir];
                y += dy[dir];
            }
            sb.append("#").append(t).append("\n");
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    sb.append(map[i][j]).append(" ");
                }
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}
