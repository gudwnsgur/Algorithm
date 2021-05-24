import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, root, q;
    static int[] dp;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

    static int dfs(int node) {
        visited[node] = true;
        dp[node] = 1;
        for(int i=0; i<graph.get(node).size(); i++) {
            if(!visited[graph.get(node).get(i)]) {
                visited[graph.get(node).get(i)] = true;
                dp[node] += dfs(graph.get(node).get(i));
            }
        }
        return dp[node];
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        root = Integer.parseInt(tk.nextToken());
        q = Integer.parseInt(tk.nextToken());

        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        for(int i=0; i<n-1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            graph.get(s).add(e);
            graph.get(e).add(s);
        }
        dp = new int[n+1];
        visited = new boolean[n+1];
        dfs(root);

        for(int i=0; i<q; i++) {
            System.out.println(dp[Integer.parseInt(br.readLine())]);
        }
    }
}


