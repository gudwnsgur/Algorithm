import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] path;
    static int[] p;

    static void unionParents(int a, int b) {
        a = getParnets(a);
        b = getParnets(b);
        if (a < b) p[b] = a;
        else p[a] = b;
    }

    static int getParnets(int a) {
        if (p[a] == a) return a;
        return p[a] = getParnets(p[a]);
    }

    static void union(int a, int b) {
        if (getParnets(a) != getParnets(b)) {
            unionParents(a, b);
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        p = new int[n + 1];
        for (int i = 1; i <= n; i++) p[i] = i;

        for (int i = 1; i <= n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                if(Integer.parseInt(tk.nextToken()) == 1) {
                    union(i, j);
                }
            }
        }

        path = new int[m];
        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) path[i] = Integer.parseInt(tk.nextToken());

        int parents = getParnets(path[0]);
        for(int i=1; i<m; i++) {
            if(parents != p[path[i]]) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}


