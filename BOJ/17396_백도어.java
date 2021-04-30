import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.temporal.ValueRange;
import java.util.*;

class Pair {
    int node;
    long value;

    Pair(int node, long value) {
        this.node = node;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static boolean[] sight, visited;
    static ArrayList<Integer> node = new ArrayList<>();
    static HashMap<Integer, Boolean> map = new HashMap<>();
    static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();

    static long dijsktra(int start) {
        long[] dist = new long[n];
        for (int i = 0; i < n; i++) dist[i] = Long.MAX_VALUE;

        PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (dist[o1.node] < dist[o2.node]) return -1;
                else if (dist[o1.node] > dist[o2.node]) return 1;
                return 0;
            }
        });

        queue.add(new Pair(start, 0));
        visited[start] = true;
        dist[start] = 0;

        while (!queue.isEmpty()) {
            Pair cur = queue.poll();
            visited[cur.node] = true;
            if(dist[cur.node] < cur.value) continue;
            for (int i = 0; i < graph.get(cur.node).size(); i++) {
                int next = graph.get(cur.node).get(i).node;
                long value = graph.get(cur.node).get(i).value;
                if (dist[next] > dist[cur.node] + value) {
                    dist[next] = dist[cur.node] + value;
                    queue.add(new Pair(next, dist[next]));
                }
            }
        }
        if (dist[n - 1] == Long.MAX_VALUE) return -1;
        else return dist[n-1];
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        sight = new boolean[n];
        visited = new boolean[n];

        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int s = Integer.parseInt(tk.nextToken());
            if (s == 0 || i == n - 1) node.add(i);
            else map.put(i, true);
        }
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());

        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            long value = Integer.parseInt(tk.nextToken());
            if (map.containsKey(s) || map.containsKey(e)) continue;
            graph.get(s).add(new Pair(e, value));
            graph.get(e).add(new Pair(s, value));
        }

        System.out.println(dijsktra(0));
    }
}
