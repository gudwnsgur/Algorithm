import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k, res;
    static int[][] jump;

    static void dfs(int cur, int end, int value, boolean bigJumped) {
        if (cur >= end) {
            if(cur == end) res = Math.min(res, value);
            return;
        }

        if(!bigJumped) dfs(cur + 3, end, value + k, true);
        dfs(cur + 1, end, value + jump[cur][1], bigJumped);
        dfs(cur + 2, end, value + jump[cur][2], bigJumped);
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        jump = new int[n + 1][3];
        res = Integer.MAX_VALUE;

        for (int i = 1; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            jump[i][1] = Integer.parseInt(tk.nextToken());
            jump[i][2] = Integer.parseInt(tk.nextToken());
        }
        k = Integer.parseInt(br.readLine());
        dfs(1, n, 0, false);
        System.out.println(res);
    }
}
