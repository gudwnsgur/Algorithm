import java.util.*;
import java.io.*;
class Node {
    int node, level;
    Node(int node, int level) {
        this.node = node;
        this.level = level;
    }
}
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int k, m, p;
    static ArrayList<Integer>[] graph;
    static ArrayList<Integer>[] order;
    static int[] parents;
    static int[] result;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<=tc ;i++) {
            input();
            System.out.print(i + " ");
            solve();
            System.out.println(result[m]);
        }
        while(tc-- > 0 ) {
        }
    }
    public static void input() throws IOException{
        tk = new StringTokenizer(br.readLine());
        k = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        p = Integer.parseInt(tk.nextToken());

        graph = new ArrayList[m+1];
        order = new ArrayList[m+1];

        result = new int[m+1];
        parents = new int[m+1];
        for(int i=0; i<=m; i++) {
            graph[i] = new ArrayList<>();
            order[i] = new ArrayList<>();
        }
        for(int i=0; i<p; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            graph[s].add(e);
            parents[e]++;
        }
    }
    public static void solve() {
        Queue<Node> q = new LinkedList<>();
        for(int i=1; i<=m; i++) {
            if(parents[i] == 0) {
                q.add(new Node(i, 1));
                result[i] = 1;
            }
        }

        while(!q.isEmpty()) {
            Node cur = q.poll();
            for(int next : graph[cur.node]) {
                order[next].add(cur.level);
                parents[next]--;

                if(parents[next] == 0) {
                    int level = getLevel(next);
                    result[next] = level;
                    q.add(new Node(next, level));
                }
            }
        }
    }
    static int getLevel(int node) {
        if(order[node].isEmpty()) return 0;
        if(order[node].size() == 1) return order[node].get(0);
        order[node].sort(Collections.reverseOrder());
        return (order[node].get(0) == (order[node].get(1)) ? order[node].get(0)+1 : order[node].get(0));
    }
}


