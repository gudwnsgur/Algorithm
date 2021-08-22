import java.util.*;
import java.io.*;

class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int n, result;
    static int[] weight;
    static int[] arr;
    static boolean[] visited;

    static void subset(int len, int left, int right ){
        if(left < right) return;
        if(len == n) {
            result++;
            return;
        }

        subset(len+1, left+arr[len], right);
        subset(len+1, left, right+arr[len]);
    }

    static void dfs(int len) {
        if(len == n) {
            subset(0, 0, 0);
        }
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[len] = weight[i];
                dfs(len+1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int t= 1; t<=tc; t++) {
            result = 0;
            n = Integer.parseInt(br.readLine());
            weight = new int[n];
            arr = new int[n];
            visited = new boolean[n];
            tk = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) weight[i] = Integer.parseInt(tk.nextToken());

            dfs(0);
            sb.append("#").append(t).append(" ").append(result).append("\n");
        }
        System.out.println(sb.toString());
    }
}
