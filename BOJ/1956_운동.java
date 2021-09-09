import java.util.*;
import java.io.*;

class Main {
    static final int MAXVALUE = 987654321;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, result = Integer.MAX_VALUE;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        dist = new int[n+1][n+1];
        for(int i=0; i<=n; i++) Arrays.fill(dist[i], MAXVALUE);

        m = Integer.parseInt(tk.nextToken());
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int value = Integer.parseInt(tk.nextToken());
            dist[s][e] = value;
        }
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i=1; i<=n; i++) result = Math.min(result, dist[i][i]);
        System.out.println(result >= MAXVALUE ? -1 : result);
    }
}


