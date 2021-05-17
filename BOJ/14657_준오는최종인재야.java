import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair {
    int nodeCnt, time;

    Pair(int nodeCnt, int time) {
        this.nodeCnt = nodeCnt;
        this.time = time;
    }
}

class Node {
    int node, value;

    Node(int node, int value) {
        this.node = node;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static Pair result = new Pair(1, 0);
    static ArrayList<ArrayList<Node>> graph = new ArrayList<>();
    static int n, limit, root;
    static boolean[] visited;

    static void input() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        limit = Integer.parseInt(tk.nextToken());

        visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());

        for (int i = 0; i < n - 1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int value = Integer.parseInt(tk.nextToken());

            graph.get(s).add(new Node(e, value));
            graph.get(e).add(new Node(s, value));
        }
    }


    static void dfs(int node, int nodeCnt, int value) {
        boolean hasChild = false;

        for (int i = 0; i < graph.get(node).size(); i++) {
            if (!visited[graph.get(node).get(i).node]) {
                hasChild = true;
                visited[graph.get(node).get(i).node] = true;
                dfs(graph.get(node).get(i).node, nodeCnt + 1, value + graph.get(node).get(i).value);
                visited[graph.get(node).get(i).node] = false;
            }
        }

        if (!hasChild) {
            if(result.nodeCnt < nodeCnt || (
                    result.nodeCnt == nodeCnt && value < result.time))
                root = node;

            if (result.nodeCnt < nodeCnt) {
                result = new Pair(nodeCnt, value);
            }
            else if (result.nodeCnt == nodeCnt) result = new Pair(nodeCnt, Math.min(value, result.time));
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        visited = new boolean[n+1];
        visited[1] = true;
        dfs(1, 1, 0);

        visited = new boolean[n+1];
        visited[root] = true;
        dfs(root, 1, 0);

        System.out.println(result.time % limit == 0 ? result.time / limit : result.time / limit + 1);
    }
}
