import java.util.*;
import java.io.*;
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] prevScore, p;
    static boolean [][] graph;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<=tc ;i++) {
            solve();
        }
    }

    public static void solve() throws IOException{
        n = Integer.parseInt(br.readLine());
        graph = new boolean[n+1][n+1];
        p = new int[n+1];
        prevScore = new int[n+1];

        tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) prevScore[i] = Integer.parseInt(tk.nextToken());

        for(int i=1; i<n; i++) {
            for(int j=i+1; j<=n; j++) {
                graph[prevScore[i]][prevScore[j]] = true;
            }
        }

        m = Integer.parseInt(br.readLine());
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            if(graph[s][e]) {
                graph[s][e] = false;
                graph[e][s] = true;
            }
            else if(graph[e][s]) {
                graph[e][s] = false;
                graph[s][e] = true;
            }
        }
        for(int i=1; i<=n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j]) {
                    p[j]++;
                }
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) if(p[i] == 0) q.add(i);
        while(!q.isEmpty()) {
            int cur = q.poll();
            result.add(cur);
            for(int i=1; i<=n; i++) {
                if(graph[cur][i]) {
                    p[i]--;
                    if(p[i] == 0) {
                        q.add(i);
                    }
                }
            }
        }
        if(!q.isEmpty() || result.size() != n) System.out.println("IMPOSSIBLE");
        else {
            for(int i=0; i<result.size(); i++) System.out.print(result.get(i) + " ");
            System.out.println();
        }
    }
}


