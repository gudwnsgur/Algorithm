import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Edge {
    int x, y, value;

    Edge(int x, int y, int value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] alphabet = new int[123];
    static int[] parents;
    static ArrayList<Edge> edges = new ArrayList<>();
    static int n, total = 0;

    public static int getParents(int node) {
        if (node == parents[node]) return node;
        return parents[node] = getParents(parents[node]);
    }

    public static void union(int a, int b) {
        a = getParents(a);
        b = getParents(b);

        if (a < b) parents[b] = a;
        else parents[a] = b;
    }

    public static void main(String[] args) throws IOException {
        for (int i = 65; i <= 90; i++) alphabet[i] = i - 65 + 27;
        for (int i = 97; i <= 122; i++) alphabet[i] = i - 96;
        n = Integer.parseInt(br.readLine());
        parents = new int[n];
        for (int i = 0; i < n; i++) parents[i] = i;

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                int tmp = (int)s.charAt(j) + 1;
                if(s.charAt(j) >= 'a' && s.charAt(j) <= 'z') tmp -= 'a';
                if(s.charAt(j) >= 'A' && s.charAt(j) <= 'Z') tmp -= 'A'-26;
                if(s.charAt(j) != '0') {
                    total += tmp;
                    if (i != j) edges.add(new Edge(i, j, tmp));
                }
            }
        }

        Collections.sort(edges, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                if (o1.value < o2.value) return -1;
                else if (o1.value > o2.value) return 1;
                return 0;
            }
        });

        int cnt = 1;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges.get(i).x, y = edges.get(i).y;
            int value = edges.get(i).value;
            if (getParents(x) != getParents(y)) {
                cnt++;
                total -= value;
                union(x, y);
            }
        }
        if (cnt < n) System.out.println(-1);
        else System.out.println(total);
    }
} 
