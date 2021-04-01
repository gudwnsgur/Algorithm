import java.util.*;

class Solution {
    boolean[][] edges;
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
                for(int j=2; j<=n; j++) {
                    if(!visited[j] && edges[node][j]) {
                        visited[j] = true;
                        queue.add(j);
                        result[j] = length;
                    }
                }
                queue.remove();
            }
        }
        return length-1;
    }


    public int solution(int n, int[][] edge) {
        edges = new boolean[n+1][n+1];
        for(int i=0; i<edge.length; i++) {
            edges[edge[i][0]][edge[i][1]] = true;
            edges[edge[i][1]][edge[i][0]] = true;
        }
        result = new int[n+1];
        for(int i=2; i<=n; i++) result[i] = n;
        visited = new boolean[n+1];

        int maxLen = bfs(n);
        int cnt = 0;
        for(int i=2; i<=n; i++) if(result[i] == maxLen) cnt++;
        return cnt;
    }
}
