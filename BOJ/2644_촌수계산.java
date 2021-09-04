import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, src, dist, m;
    static boolean[][] graph;
    static boolean[] visited;
    static Queue<Integer> q = new LinkedList<>();

    static int bfs() {
        q.add(src);
        int len = 0;
        visited[src] = true;

        while(!q.isEmpty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int cur = q.poll();
                if(cur == dist) return len;
                for(int next = 1; next <=n; next++) {
                    if(graph[cur][next] && !visited[next]) {
                        visited[next] = true;
                        q.add(next);
                    }
                }
            }
            len++;
        }
        return -1;
    }


    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        graph = new boolean[n+1][n+1];
        visited = new boolean[n+1];

        tk = new StringTokenizer(br.readLine());
        src = Integer.parseInt(tk.nextToken());
        dist = Integer.parseInt(tk.nextToken());

        m = Integer.parseInt(br.readLine());
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s =Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            graph[s][e] = graph[e][s] = true;
        }

        System.out.println(bfs());
    }
}


