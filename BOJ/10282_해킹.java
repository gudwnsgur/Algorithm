import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    static int[] dijkstra(int n, int c, ArrayList<ArrayList<Pair>> graph) {

        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.value < o2.value) return -1;
                else if(o1.value > o2.value) return 1;
                return 0;
            }
        });

        pq.add(new Pair(c, 0));
        dist[c] = 0;
        while(!pq.isEmpty()) {
            Pair cur = pq.poll();
            for(int i=0; i<graph.get(cur.node).size(); i++) {
                Pair next = graph.get(cur.node).get(i);

                if(cur.value + next.value >= dist[next.node]) continue;
                dist[next.node] = cur.value + next.value;
                pq.add(new Pair(next.node, dist[next.node]));
            }

        }
        return dist;
    }

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0 ) {
            int n, d, c;
            tk = new StringTokenizer(br.readLine());
            n = Integer.parseInt(tk.nextToken());
            d = Integer.parseInt(tk.nextToken());
            c = Integer.parseInt(tk.nextToken());

            ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
            for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
            for(int i=0; i<d; i++) {
                tk = new StringTokenizer(br.readLine());
                int e = Integer.parseInt(tk.nextToken());
                int s = Integer.parseInt(tk.nextToken());
                int value = Integer.parseInt(tk.nextToken());
                graph.get(s).add(new Pair(e, value));
            }

            int[] dist = dijkstra(n, c, graph);

            int cnt = 0, time = 0;
            for(int i=1; i<=n; i++) {
                if(dist[i] != Integer.MAX_VALUE) {
                    cnt++;
                    time = Math.max(time, dist[i]);
                }
            }
            System.out.println(cnt + " " + time);
        }
    }
}
