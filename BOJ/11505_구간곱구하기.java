import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static final long MOD = 1000000007;
    static int n, m, k;
    static long[] arr, segmentTree;

    static long initTree(int node, int s, int e) {
        if (s == e) return segmentTree[node] = arr[s];
        return segmentTree[node] = (initTree(node * 2, s, (s + e) / 2) *
                initTree(node * 2 + 1, (s + e) / 2 + 1, e)) % MOD;
    }

    static long getMul(int node, int s, int e, int left, int right) {
        if (left > e || right < s) return 1; // 범위 밖의 값을 가진 node
        if (left <= s && e <= right) return segmentTree[node]; // 범위 안에 있는 값을 가진 node
        
        return (getMul(node * 2, s, (s + e) / 2, left, right)
                * getMul(node * 2 + 1, (s + e) / 2 + 1, e, left, right))%MOD;
        // 걸쳐있는 node
    }

    static long updateTree(int node, int s, int e, int dest, int next) {
        if (dest > e || dest < s) return segmentTree[node];
        if (s == e) return segmentTree[node] = next;

        return segmentTree[node] = updateTree(node * 2, s, (s + e) / 2, dest, next) *
                updateTree(node * 2 + 1, (s + e) / 2 + 1, e, dest, next)%MOD;
        // 리프노드까지
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        arr = new long[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(br.readLine());
        segmentTree = new long[4 * n];
        initTree(1, 1, n);

        for (int i = 0; i < m + k; i++) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken());
            int b = Integer.parseInt(tk.nextToken());
            int c = Integer.parseInt(tk.nextToken());

            if (a == 1) {
                arr[b] = c;
                updateTree(1, 1, n, b, c);
            } else System.out.println(getMul(1, 1, n, b, c));
        }
    }
}

