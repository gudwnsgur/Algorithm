import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static final int MAX = 10000001;
    static int n, m;
    static int[][] cost;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        cost = new int[n + 1][n + 1];

        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int value = Integer.parseInt(tk.nextToken());

            if (cost[s][e] != 0) cost[s][e] = Math.min(cost[s][e], value);
            else cost[s][e] = value;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && cost[i][j] == 0) cost[i][j] = MAX;
            }
        }

        // 플로이드 알고리즘
        for (int path = 1; path <= n; path++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cost[i][j] = Math.min(cost[i][j], cost[i][path] + cost[path][j]);
                }
            }
        }


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print((cost[i][j] >= MAX ? "0" : cost[i][j]) + " ");
            }
            System.out.println();
        }
    }
} 
