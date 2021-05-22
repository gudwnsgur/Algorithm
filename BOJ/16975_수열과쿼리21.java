import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static long[] arr, segmentTree;

    static long getSum(int node, int s, int e, int left, int right) {
        if (left > e || right < s) return 0; // 범위 밖의 값을 가진 node
        if (left <= s && e <= right) return segmentTree[node]; // 범위 안에 있는 값을 가진 node

        return (getSum(node * 2, s, (s + e) / 2, left, right)
                + getSum(node * 2 + 1, (s + e) / 2 + 1, e, left, right));
        // 걸쳐있는 node
    }

    static long updateTree(int node, int s, int e, int x, int cost) {
        if(s <= x && x <= e) {
            if(s == e) return segmentTree[node] += cost;
            segmentTree[node] = updateTree(node * 2, s, (s + e) / 2, x, cost) +
                    updateTree(node * 2 + 1, (s + e) / 2 + 1, e, x, cost);
        }
        return segmentTree[node];
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        arr = new long[n + 1];
        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(tk.nextToken());
        segmentTree = new long[4 * n];

        m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken());
            int b = Integer.parseInt(tk.nextToken());

            if (a == 1) {
                int c = Integer.parseInt(tk.nextToken());
                int d = Integer.parseInt(tk.nextToken());

                updateTree(1, 1, n, b, d);
                updateTree(1, 1, n, c+1, -1*d);

            } else System.out.println(getSum(1,1,n, 1, b) + arr[b]);
        }
    }
}

