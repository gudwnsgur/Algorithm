import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] p, res;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        p = new int[n+1];
        res = new int[n+1];
        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());

        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            graph.get(s).add(e);
            p[e]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            if(p[i] == 0) {
                q.add(i);
                res[i] = 1;
            }
        }
        int order = 1;
        while(!q.isEmpty()) {
            int size = q.size();
            order++;
            for(int i=0; i<size; i++) {
                int cur = q.poll();
                for(int j=0; j<graph.get(cur).size(); j++) {
                    int next = graph.get(cur).get(j);
                    p[next]--;
                    if(p[next] == 0) {
                        res[next] = order;
                        q.add(next);
                    }
                }
            }
        }
        for(int i=1; i<=n; i++) System.out.print(res[i] + " ");
    }
}
