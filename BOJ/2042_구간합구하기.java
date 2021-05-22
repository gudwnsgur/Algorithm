
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, k;
    static long[] arr, segmentTree;

    static long initTree(int node, int s, int e) {
        if (s == e) return segmentTree[node] = arr[s];
        return segmentTree[node] = initTree(node * 2, s, (s + e) / 2) +
                initTree(node * 2 + 1, (s + e) / 2 + 1, e);
    }

    static long getSum(int node, int s, int e, int left, int right) {
        if (left > e || right < s) return 0;
        // 범위 밖의 값을 가진 node
        if (left <= s && e <= right) return segmentTree[node];
        // 범위 안에 있는 값을 가진 node
        return getSum(node * 2, s, (s + e) / 2, left, right)
                + getSum(node * 2 + 1, (s + e) / 2 + 1, e, left, right);
        // 걸쳐있는 node
    }

    static void updateTree(int node, int s, int e, int dest, long diff) {
        if (dest > e || dest < s) return;
        // dest가 범위 안에 존재하지 않음

        segmentTree[node] += diff;
        // 범위 안의 node값 변경

        if (s != e) {
            updateTree(node * 2, s, (s + e) / 2, dest, diff);
            updateTree(node * 2 + 1, (s + e) / 2 + 1, e, dest, diff);
        }
        // 리프노드까지
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        arr = new long[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(br.readLine());

        segmentTree = new long[4*n];
        initTree(1, 1, n);

        for (int i = 0; i < m + k; i++) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken());
            long b = Long.parseLong(tk.nextToken());
            long c = Long.parseLong(tk.nextToken());

            if (a == 1) {
                updateTree(1, 1, n, (int) b, c - arr[(int)b]);
                arr[(int)b] = c;
            } else System.out.println(getSum(1, 1, n, (int)b, (int)c));
        }
    }
}

