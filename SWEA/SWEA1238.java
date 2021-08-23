import java.io.*;
import java.util.*;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static boolean[][] graph;
    static boolean[] visited;
     
    public static void main(String[] args) throws IOException {
         
        for(int tc =1; tc<=10; tc++) {
            graph = new boolean[101][101];
            visited = new boolean[101];
            tk = new StringTokenizer(br.readLine());
             
            int n = Integer.parseInt(tk.nextToken())/2;
            int start = Integer.parseInt(tk.nextToken());
             
            tk = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) {
                graph[Integer.parseInt(tk.nextToken())][Integer.parseInt(tk.nextToken())] = true;
            }
             
            visited[start] = true;
            Queue<Integer> q = new LinkedList<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            q.add(start);
             
            while(!q.isEmpty()) {
                int size = q.size();
                pq.clear();
                for(int i=0; i<size; i++) {
                    int cur = q.poll();
                    pq.add(cur);
                     
                    for(int next=1; next<=100; next++) {
                        if(graph[cur][next] && !visited[next]) {
                            visited[next] = true;
                            q.add(next);
                        }
                    }
                }
            }
            sb.append("#").append(tc).append(" ").append(pq.poll()).append("\n");
        }
        System.out.println(sb.toString());
    }
 
}
