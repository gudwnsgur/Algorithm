import java.util.*;

class Solution {
    ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    boolean[] visited;
    long[] arr;
    long result = 0;

    public void dfs(int prev, int next) {
        for (int i = 0; i < graph.get(next).size(); i++) {
            if (!visited[graph.get(next).get(i)]) {
                visited[graph.get(next).get(i)] = true;
                dfs(next, graph.get(next).get(i));
            }
        }
        if(arr[next] == 0 )return;

        result += (Math.abs(arr[next]));
        arr[prev] += arr[next];
        arr[next] = 0;
    }

    public long solution(int[] a, int[][] edges) {
        arr = new long[a.length];
        long sum = 0;

        for(int i=0; i<a.length; i++) {
            sum += a[i];
            arr[i] = a[i];
        }
        if (sum != 0) return -1;

        visited = new boolean[a.length];
        for (int i = 0; i <= a.length; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        visited[edges[0][1]] = true;
        dfs(edges[0][0], edges[0][1]);
        System.out.println(result);
        return result;
    }
}
