import java.util.*;
import java.io.*;
class Node {
    int name, value;
    Node(int name, int value ) {
        this.name = name;
        this.value = value;
    }
}
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int src, dest;
    static int[] inDegree, dist;
    static ArrayList<Node>[] graph, inverseGraph;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        graph = new ArrayList[n+1];
        inverseGraph = new ArrayList[n+1];
        inDegree = new int[n+1];
        dist = new int[n+1];
        for(int i=0; i<=n; i++) {
            graph[i] = new ArrayList<>();
            inverseGraph[i] = new ArrayList<>();
        }


        m = Integer.parseInt(br.readLine());
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());
            int value = Integer.parseInt(tk.nextToken());
            graph[s].add(new Node(e,value));
            inverseGraph[e].add(new Node(s,value));
            inDegree[e]++;
        }

        tk = new StringTokenizer(br.readLine());
        src = Integer.parseInt(tk.nextToken());
        dest = Integer.parseInt(tk.nextToken());

        System.out.println(topologicalSort());
        System.out.println(getPath());
    }
    static int topologicalSort() {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n+1];
        q.add(src);

        while(!q.isEmpty()) {
            int cur = q.poll();
            if(visited[cur]) continue;
            visited[cur] = true;
            for(int i=0; i<graph[cur].size(); i++) {
                Node next = graph[cur].get(i);
                dist[next.name] = Math.max(dist[next.name], dist[cur] + next.value);
                if(--inDegree[next.name] == 0) q.add(next.name);
            }
        }
        return dist[dest];
    }

    static int getPath() {
        int result = 0;
        boolean[] visited = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        q.add(dest);
        while(!q.isEmpty()) {
            int cur = q.poll();
            if(visited[cur])continue;
            visited[cur] = true;
            for(Node next : inverseGraph[cur]) {
                if(dist[cur] - dist[next.name] == next.value) {
                    result++;
                    q.add(next.name);
                }
            }
        }
        return result;
    }
}


