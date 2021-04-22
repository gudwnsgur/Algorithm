import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node {
    int name, time;

    Node(int name, int time) {
        this.name = name;
        this.time = time;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] numOfLinks;
    static int[] time;

    static int topologicalSort() {
        int result = 0;

        ArrayList<Node> tmp = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.time < o2.time) return -1;
                else if (o1.time > o2.time) return 1;
                return 0;
            }
        });

        for (int i = 1; i <= n; i++) if (numOfLinks[i] == 0) pq.add(new Node(i, time[i]));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            result += cur.time;

            while (!pq.isEmpty()) {
                Node x = pq.poll();
                tmp.add(new Node(x.name, x.time - cur.time));
            }
            for(int i=0; i<graph.get(cur.name).size(); i++) {
                int next = graph.get(cur.name).get(i);
                numOfLinks[next]--;

                if(numOfLinks[next] == 0) tmp.add(new Node(next, time[next]));
            }

            pq.addAll(tmp);
            tmp.clear();
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        numOfLinks = new int[n + 1];
        time = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            tk = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(tk.nextToken());

            int m = Integer.parseInt(tk.nextToken());
            for (int j = 0; j < m; j++) {
                int e = Integer.parseInt(tk.nextToken());
                graph.get(i).add(e);
                numOfLinks[e]++;
            }
        }
        System.out.println(topologicalSort());
    }
}
