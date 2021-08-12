import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        int w = Integer.parseInt(tk.nextToken());

        visited = new boolean[n+1];
        for(int i=0; i<=n; i++) tree.add(new ArrayList<>());
        for(int i=0; i<n-1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            tree.get(s).add(e);
            tree.get(e).add(s);
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int i=0; i<tree.get(cur).size(); i++) {
                int next = tree.get(cur).get(i);
                if(!visited[next]) {
                    visited[cur] = true;
                    q.add(next);
                }
            }
        }
        int leaf = 0;
        for(int i=1; i<=n; i++) if(!visited[i]) leaf++;
        System.out.println((double)w / leaf);

    }
}
