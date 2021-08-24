import java.io.*;
import java.util.*;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] p;
    static StringBuilder sb = new StringBuilder();
    static StringBuilder result;
     
    static int getParent(int node) {
        if(node == p[node]) return node;
        return node = getParent(p[node]);
    }
    static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);
         
        if(a < b) p[b] = a;
        else p[a] = b;
    }
     
    static void solve(int op, int a, int  b) {
        if(op == 1) result.append(getParent(a) == getParent(b) ? "1" : "0");
        else union(a, b);
    }
     
    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int t= 1; t<=tc ;t++) {
            result = new StringBuilder();
            tk = new StringTokenizer(br.readLine());
            n = Integer.parseInt(tk.nextToken());
            m = Integer.parseInt(tk.nextToken());
            p = new int[n+1];
            for(int i=0; i<=n; i++) p[i] = i;
             
            for(int i=0; i<m; i++) {
                tk = new StringTokenizer(br.readLine());
                solve(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()),
                        Integer.parseInt(tk.nextToken()));
            }
            sb.append("#").append(t).append(" ").append(result.toString()).append("\n");
        }
        System.out.println(sb.toString());
    }
 
}

