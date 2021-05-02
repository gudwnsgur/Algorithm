import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

class Pair {
    int node, value;

    Pair(int node, int value) {
        this.node = node;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, x;
    static int s, e, value;

    static void dijkstra(int start, int[] dist, ArrayList<ArrayList<Pair>> graph) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.value < o2.value) return -1;
                else if(o1.value > o2.value) return 1;
                return 0;
            }
        });

        dist[start] = 0;
        pq.add(new Pair(start, 0 ));
        while(!pq.isEmpty()) {
            Pair cur = pq.poll();
            if(dist[cur.node] < cur.value) continue;
            for(int i=0; i<graph.get(cur.node).size(); i++) {
                Pair next = graph.get(cur.node).get(i);
                if(dist[next.node] > dist[cur.node] + next.value) {
                    dist[next.node] = dist[cur.node] + next.value;
                    pq.add(new Pair(next.node, dist[next.node]));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        x = Integer.parseInt(tk.nextToken());

        int[] goDist, backDist;
        goDist = new int[n + 1];
        backDist = new int[n + 1];
        ArrayList<ArrayList<Pair>> goGraph = new ArrayList<>();
        ArrayList<ArrayList<Pair>> backGraph = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            goDist[i] = Integer.MAX_VALUE;
            backDist[i] = Integer.MAX_VALUE;
            goGraph.add(new ArrayList<>());
            backGraph.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            s = Integer.parseInt(tk.nextToken());
            e = Integer.parseInt(tk.nextToken());
            value = Integer.parseInt(tk.nextToken());
            goGraph.get(e).add(new Pair(s, value));
            backGraph.get(s).add(new Pair(e, value));
        }

        dijkstra(x, goDist, goGraph);
        dijkstra(x, backDist, backGraph);

        int result = 0;
        for(int i=1; i<=n; i++) {
            result = Math.max(result, goDist[i] + backDist[i]);
        }
        System.out.println(result);
    }
}
