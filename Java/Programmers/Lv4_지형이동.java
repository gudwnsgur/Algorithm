import java.util.*;

// 1. BFS로 각 node numbering
// 2. 각 노드의 거리 최소 비용 구하기
// 3. Kruskal (union-find)

class Pair {
    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Edge {
    int s, e, value;
    Edge(int s, int e, int value) {
        this.s = s;
        this.e = e;
        this.value = value;
    }
}

class Solution {
    int n;
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    boolean[][] visited;
    int[][] map, lands;
    int[] parents;
    ArrayList<Pair> arr = new ArrayList<>();
    HashMap<String, Integer> dist = new LinkedHashMap<>();

    void bfs(int x, int y, int nodeNumber, int height) {

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(x, y));

        while (!queue.isEmpty()) {
            int curX = queue.element().first, curY = queue.element().second;
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + curX, ny = dy[i] + curY;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (visited[nx][ny] && map[nx][ny] != nodeNumber) {
                    int diff = Math.abs(lands[curX][curY] - lands[nx][ny]);

                    if (!dist.containsKey(Integer.toString(map[nx][ny]) + Integer.toString(nodeNumber))) {
                        dist.put(Integer.toString(map[nx][ny]) + Integer.toString(nodeNumber), diff);
                        arr.add(new Pair(map[nx][ny], nodeNumber));
                    }
                    else {
                        int prev = dist.get(Integer.toString(map[nx][ny]) + Integer.toString(nodeNumber));
                        if(diff < prev) dist.put(Integer.toString(map[nx][ny]) + Integer.toString(nodeNumber), diff);
                    }
                } else if (!visited[nx][ny] && Math.abs(lands[nx][ny] - lands[curX][curY]) <= height) {
                    map[nx][ny] = nodeNumber;
                    visited[nx][ny] = true;
                    queue.add(new Pair(nx, ny));
                }
            }
            queue.remove();
        }
    }

    int getParent(int node) {
        if(parents[node] == node) return node;
        return getParent(parents[node]);
    }
    void unionParents(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if(a < b) parents[b] = a;
        else parents[a] = b;
    }

    public int solution(int[][] land, int height) {
        n = land.length;
        visited = new boolean[n + 1][n + 1];
        map = new int[n + 1][n + 1];
        lands = land;


        // bfs
        int nodeNum = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    map[i][j] = nodeNum;
                    bfs(i, j, nodeNum, height);
                    nodeNum++;
                }
            }
        }
        if(nodeNum == 2) return 0;

        // get edges with graph
        ArrayList<Edge> edges = new ArrayList<>();
        for(int i=0; i<arr.size(); i++) {
            edges.add(new Edge(arr.get(i).first,  arr.get(i).second,
                    dist.get( Integer.toString(arr.get(i).first) + Integer.toString(arr.get(i).second))));
        }

        // sort edge
        Collections.sort(edges, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                if(o1.value < o2.value) return -1;
                else if(o1.value > o2.value) return 1;
                return 0;
            }
        });

        // kruskal algorithm
        int result = 0;
        parents = new int[nodeNum];
        for(int i=1; i<nodeNum; i++) parents[i] = i;
        for(Edge edge : edges) {
            if(getParent(edge.s) != getParent(edge.e)) {
                result += edge.value;
                unionParents(edge.s, edge.e);
            }
        }

        return result;
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] b = {{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}};
        System.out.println(s.solution(b, 1));

    }
}
