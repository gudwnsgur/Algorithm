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
    static int n;
    static int result = 0;
    static ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
    static boolean[] visited;


    static Pair bfs(int start) {
        int resNode = 0 , resValue = 0;
        visited = new boolean[n + 1];
        visited[start] = true;

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(start, 0));

        while (!queue.isEmpty()) {
            Pair cur = queue.poll();
            if(resValue < cur.value) {
                resNode = cur.node;
                resValue = cur.value;
            }

            for (int i = 0; i < graph.get(cur.node).size(); i++) {
                Pair next = graph.get(cur.node).get(i);
                if (!visited[next.node]) {
                    visited[next.node] = true;
                    queue.add(new Pair(next.node, cur.value + next.value));
                }
            }
        }
        return new Pair(resNode, resValue);
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());

        for (int i = 0; i < n - 1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int value = Integer.parseInt(tk.nextToken());

            graph.get(s).add(new Pair(e, value));
            graph.get(e).add(new Pair(s, value));
        }
        System.out.println(bfs(bfs(1).node).value);
    }
}
