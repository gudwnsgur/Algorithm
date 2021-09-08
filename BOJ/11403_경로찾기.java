import java.util.*;
import java.io.*;
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static boolean[][] graph, dist;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        graph = new boolean[n][n];
        dist = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(tk.nextToken()) == 1;
                dist[i][j] = graph[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = ( dist[i][j] || (dist[i][k] && dist[k][j]));
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(dist[i][j] ? (1 + " ") : (0  +  " "));
            }
            System.out.println();
        }
    }
}


