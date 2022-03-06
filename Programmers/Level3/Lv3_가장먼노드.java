import java.util.*;

class Solution {
    ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    int [] result;
    boolean[] visited;

    int bfs(int n) {
        visited[1] = true;
        result[1] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        int length = 0;

        while(!queue.isEmpty()) {
            int size = queue.size();
            length++;
            for(int i=0; i<size; i++) {
                int node = queue.element();
                for(int j=0; j<graph.get(node).size(); j++) {
                    if(!visited[graph.get(node).get(j)]) {
                        visited[graph.get(node).get(j)] = true;
                        queue.add(graph.get(node).get(j));
                        result[graph.get(node).get(j)] = length;
                    }
                }
                queue.remove();
            }
        }
        return length-1;
    }

    public int solution(int n, int[][] edge) {
        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        result = new int[n+1];
        visited = new boolean[n+1];

        for(int i=0; i<edge.length; i++) {
            graph.get(edge[i][0]).add(edge[i][1]);
            graph.get(edge[i][1]).add(edge[i][0]);
        }

        for(int i=1; i<=n; i++) result[i] = n;

        int maxLen = bfs(n);
        int cnt = 0;
        for(int i=2; i<=n; i++) if(result[i] == maxLen) cnt++;
        return cnt;
    }
}
