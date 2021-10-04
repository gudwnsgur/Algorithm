import java.io.*;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static boolean[][] map;

    public static void main(String[] args) throws Exception {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        map = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) map[i][j] = str.charAt(j) == '1';
        }

        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if(map[i][j]) {
                    cnt++;
                    for(int ii=0; ii<=i; ii++) {
                        for(int jj=0; jj<=j; jj++) {
                            map[ii][jj] = !map[ii][jj];
                        }
                    }
                }
            }
        }
        System.out.println(cnt);

    }
}
