
import java.util.*;

class Solution {
    private int N;
    private boolean[] visited;
    private int[][] computer;


    public void bfs(int node) {
        visited[node] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(node);

        while (!queue.isEmpty()) {
            int cur = queue.element();
            for (int i = 0; i < N; i++) {
                if (cur != i && computer[cur][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
            queue.remove();
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        N = n;
        computer = computers;
        visited = new boolean[n + 1];
        for (int i = 0; i < computers.length; i++) {
            if (!visited[i]) {
                answer++;
                bfs(i);
            }

        }
        return answer;
    }
}
