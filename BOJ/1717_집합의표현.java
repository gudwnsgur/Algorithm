import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] parents;

    static int getParent(int node) {
        if(node == parents[node]) return node;
        return parents[node] = getParent(parents[node]);
    }

    static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if(a < b) parents[b] = a;
        else parents[a] = b;
    }
    static boolean find(int a, int b) {
        return getParent(a) == getParent(b);
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        parents = new int[n+1];
        for(int i=0; i<=n; i++) parents[i] = i;

        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(tk.nextToken());
            if(op == 0 ) union(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));
            else System.out.println(
                    find(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken())) ?
                            "YES" : "NO"
            );
        }
    }
}
