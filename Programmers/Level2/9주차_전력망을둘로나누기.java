import java.util.*;
import java.io.*;

class Solution {
    boolean[][] graph;
    boolean[] visited;
    int result = Integer.MAX_VALUE;
    
    public int bfs(int node, int n) {
        int cnt = 1;
        visited[node] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int i=1; i<=n; i++) {
                if(graph[cur][i] && !visited[i]) {
                    visited[i] = true;
                    q.add(i);
                    cnt++;
                } 
            }
        }
        return cnt;        
    }
    
    public int solution(int n, int[][] wires) {
        graph = new boolean[n+1][n+1];
        for(int i=0; i<wires.length; i++) {
            graph[wires[i][0]][wires[i][1]] = true;
            graph[wires[i][1]][wires[i][0]] = true;
        }
        
        for(int i=0; i<wires.length; i++) {
            graph[wires[i][0]][wires[i][1]] = false;
            graph[wires[i][1]][wires[i][0]] = false;
        
            visited = new boolean[n+1];
            result = Math.min(result, Math.abs(bfs(wires[i][0], n) - bfs(wires[i][1], n)));
            
            graph[wires[i][0]][wires[i][1]] = true;
            graph[wires[i][1]][wires[i][0]] = true;
        
        }
        return result;
    }
}
