import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int[] dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    static final int[] dy = {0, 0, -1, 1, -1, 1, -1, 1};
    static int n;
    static char[][] map1, map2, result;
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        map1 = new char[n][n];
        map2 = new char[n][n];
        result = new char[n][n];
        for(int i=0; i<n; i++) {
            String str = br.readLine();
            for(int j=0; j<n; j++) {
                map1[i][j] = str.charAt(j);
            }
        }
        for(int i=0; i <n ; i++) {
            String str = br.readLine();
            for(int j=0; j<n; j++) {
                map2[i][j] = str.charAt(j);
            }
        }
        boolean end = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map2[i][j] == '.') {
                    result[i][j] = '.';
                    continue;
                }
                if(map1[i][j] == '*') {
                    end = true;
                }
                int cnt = 0;
                for(int k=0; k<8; k++) {
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx <0 || nx >=n || ny < 0 || ny >= n) continue;
                    if(map1[nx][ny] == '*') cnt++;
                }
                result[i][j] = (char)(cnt+48);
            }
        }
        if(end) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(map1[i][j] == '*') result[i][j] = '*';
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(result[i][j]);
            }
            System.out.println();
        }
    }
}


