import java.util.*;
import java.io.*;

class Main {
    static final int MAXVALUE = 987654321;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, r;
    static int[][] dist;
    static int[] value;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        r = Integer.parseInt(tk.nextToken());

        dist = new int[n+1][n+1];
        value = new int[n+1];

        tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) value[i] = Integer.parseInt(tk.nextToken());

        for(int i=0; i<r; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int v = Integer.parseInt(tk.nextToken());

            dist[s][e] = v;
            dist[e][s] = v;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dist[i][j] == 0 ) dist[i][j] = MAXVALUE;
            }
        }
        for(int i=1; i<=n; i++) dist[i][i] = 0;

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] =  Math.min( dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
        int result = Integer.MIN_VALUE;
        for(int i=1; i<=n; i++) {
            int local = 0;
            for(int j=1; j<=n; j++) {
                if(dist[i][j] <= m) local += value[j];
            }
            result = Math.max(local, result);
        }
        System.out.println(result);
    }
}



