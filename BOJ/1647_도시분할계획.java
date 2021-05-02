import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
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
    static int s, e, value;
    static int[] parent;
    static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
    static ArrayList<int[]> edges = new ArrayList<>();

    static int getParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = getParent(parent[node]);
    }
    static void unionParents(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        parent = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
            parent[i] = i;
        }
        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            s = Integer.parseInt(tk.nextToken());
            e = Integer.parseInt(tk.nextToken());
            if (s > e) {
                int tmp = s;
                s = e;
                e = tmp;
            }
            value = Integer.parseInt(tk.nextToken());
            edges.add(new int[]{s, e, value});
        }

        Collections.sort(edges, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[2] < o2[2]) return -1;
                else if (o1[2] > o2[2]) return 1;

                if (o1[0] < o2[0]) return -1;
                else if (o1[0] > o2[0]) return 1;

                if (o1[1] < o2[1]) return -1;
                else if (o1[1] > o2[1]) return 1;
                return 0;
            }
        });

        long result = 0;
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++) {
            if(cnt == n-2) break;
            s = edges.get(i)[0];
            e = edges.get(i)[1];
            long value = edges.get(i)[2];

            if (getParent(s) == getParent(e)) continue;

            cnt++;
            unionParents(s, e);
            result += value;
        }
        System.out.println(result);
    }
}
