import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] inDegree;
    static ArrayList<Integer> result = new ArrayList<>();
    static Queue<Integer> zeroDegree = new LinkedList<>();
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        inDegree = new int[n + 1];

        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(tk.nextToken());
            int s = Integer.parseInt(tk.nextToken());
            for (int j = 1; j < k; j++) {
                int e = Integer.parseInt(tk.nextToken());
                if (!graph.get(s).contains(e)) {
                    graph.get(s).add(e);
                    inDegree[e]++;
                }
                s = e;
            }
        }
//        for(int i=1; i<=n; i++) System.out.println(inDegree[i]);

        for (int i = 1; i <= n; i++) if (inDegree[i] == 0) zeroDegree.add(i);

        while (!zeroDegree.isEmpty()) {
            int node = zeroDegree.poll();
            result.add(node);
            for (int j = 0; j < graph.get(node).size(); j++) {
                int next = graph.get(node).get(j);
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    zeroDegree.add(next);
                }
            }
        }

        if(result.size() != n) {
            System.out.println(0);
            return;
        }
        for(int i=0; i<result.size(); i++) {
            System.out.println(result.get(i));
        }
    }
} 
