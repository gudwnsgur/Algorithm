import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static boolean isFin;
    static boolean[] visited;
    static ArrayList<Integer>[] graph;

    static void dfs(int cur, int len) {
        if(len >= 5)  {
            isFin = true;
            return;
        }

        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur].get(i);
            if(!visited[next]) {
                visited[next] = true;
                dfs(next, len+1);
                visited[next] = false;
            }
        }
    }


    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        graph = new ArrayList[n];
        for(int i=0; i<n; i++) graph[i] = new ArrayList<>();
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            graph[s].add(e);
            graph[e].add(s);
        }


        for(int i=0; i<n; i++) {
            isFin = false;
            visited = new boolean[n];
            visited[i] = true;
            dfs(i, 1);
            if(isFin) {
                System.out.println(1);
                return;
            }
        }
        System.out.println(0);
    }
}


