import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] parents;

    public static int getParent(int node) {
        if(node == parents[node]) return node;
        return parents[node] = getParent(parents[node]);
    }

    public static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a < b) parents[b] = a;
        else parents[a] = b;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        parents = new int[n];
        for (int i = 0; i < n; i++) parents[i] = i;

        for (int i = 1; i <= m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            if(getParent(s) == getParent(e)) {
                System.out.println(i);
                return;
            }
            union(s, e);

        }
        System.out.println(0);
    }
}

