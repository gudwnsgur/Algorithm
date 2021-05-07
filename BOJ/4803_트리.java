import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static boolean[][] graph;
    static boolean isTree;

    static boolean[] visited;
    static int[] parent;

    static void dfs(int node) {
        visited[node] = true;
        for(int i=1; i<=n; i++) {
            if(graph[node][i]) {
                if(parent[node] == i) continue;
                if(!visited[i]) {
                    parent[i] = node;
                    dfs(i);
                }
                else isTree = false;
            }
        }
    }

    static void solve(int tc) throws IOException {
        graph = new boolean[n + 1][n + 1];
        visited = new boolean[n + 1];
        parent = new int[n + 1];


        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            graph[s][e] = true;
            graph[e][s] = true;
        }
        if (n == 0 || m == 0) {
            if (n == 0) System.out.println("Case " + tc + ": No trees.");
            else {
                if (n == 1) System.out.println("Case " + tc + ": There is one tree.");
                else System.out.println("Case " + tc + ": A forest of " + n + " trees.");
            }
            return;
        }

        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                isTree = true;
                dfs(i);
                if(isTree) cnt++;
            }
        }

        if (cnt == 0) System.out.println("Case " + tc + ": No trees.");
        else if (cnt == 1) System.out.println("Case " + tc + ": There is one tree.");
        else System.out.println("Case " + tc + ": A forest of " + cnt + " trees.");
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        int tc = 1;
        while (n != 0 || m != 0) {
            solve(tc);
            tc++;
            tk = new StringTokenizer(br.readLine());
            n = Integer.parseInt(tk.nextToken());
            m = Integer.parseInt(tk.nextToken());
        }
    }
}
