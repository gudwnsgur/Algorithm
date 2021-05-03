import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static HashMap<String, Integer> node = new HashMap<>();
    static int nodeNo = 0;
    static int[] parents, people;

    static int getParents(int node) {
        if (node == parents[node]) return node;
        return parents[node] = getParents(parents[node]);
    }
    static void unionParents(int a, int b) {
        a = getParents(a);
        b = getParents(b);
        if(a < b) {
            parents[b] = a;
            people[a] += people[b];
        }
        else {
            parents[a] = b;
            people[b] += people[a];
        }
    }

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            node.clear();
            nodeNo = 0;
            n = Integer.parseInt(br.readLine());
            parents = new int[n*2];
            people = new int[n*2];
            for(int i=0; i<n*2; i++) {
                parents[i] = i;
                people[i] = 1;
            }

            for (int i = 0; i < n; i++) {
                tk = new StringTokenizer(br.readLine());
                String s = tk.nextToken(), e = tk.nextToken();
                int a = 0, b = 0;
                if (!node.containsKey(s)) {
                    node.put(s, nodeNo++);
                    a = nodeNo - 1;
                } else a = node.get(s);

                if (!node.containsKey(e)) {
                    node.put(e, nodeNo++);
                    b = nodeNo - 1;
                } else b = node.get(e);

                if (getParents(a) != getParents(b)) unionParents(a, b);
                System.out.println(Math.max(people[getParents(a)], people[getParents(b)]));
            }
        }
    }
}
