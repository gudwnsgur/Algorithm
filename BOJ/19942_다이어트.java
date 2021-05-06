import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int mp, mf, ms, mv;
    static int[][] pfsv;
    static int resultValue = Integer.MAX_VALUE;
    static int[] arr, resultArr;
    static String resultStr = "";
    static boolean[] visited;

    static String compareStr(String a, String b) {
        for (int i = 0; i < a.length() && i < b.length(); i++) {
            if (a.charAt(i) < b.charAt(i)) return a;
            else if (a.charAt(i) > b.charAt(i)) return b;
        }
        if(a.length() < b.length()) return a;
        return b;
}

    static void dfs(int len, int m, int n) {
        if (len == m) {
            int[] tmp = new int[5];
            for (int i = 0; i < arr.length; i++) {
                for (int j = 0; j < 5; j++) {
                    tmp[j] += pfsv[arr[i]][j];
                }
            }
            if (tmp[0] >= mp && tmp[1] >= mf && tmp[2] >= ms && tmp[3] >= mv && tmp[4] <= resultValue) {
                String str = "";
                for (int i = 0; i < arr.length; i++) {
                    str += (char) (arr[i] + 48);
                }
                if (tmp[4] == resultValue) resultStr = compareStr(resultStr, str);
                else resultStr = str;
                resultValue = tmp[4];
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (len == 0 || arr[len - 1] < i) {
                    visited[i] = true;
                    arr[len] = i;
                    dfs(len + 1, m, n);
                    visited[i] = false;
                }
            }
        }
    }

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        pfsv = new int[n][5];

        tk = new StringTokenizer(br.readLine());
        mp = Integer.parseInt(tk.nextToken());
        mf = Integer.parseInt(tk.nextToken());
        ms = Integer.parseInt(tk.nextToken());
        mv = Integer.parseInt(tk.nextToken());

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) pfsv[i][j] = Integer.parseInt(tk.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 1; i <= n; i++) {
            visited = new boolean[n];
            arr = new int[i];
            dfs(0, i, n);
        }

        if (resultValue == Integer.MAX_VALUE) System.out.println(-1);
        else {
            System.out.println(resultValue);
            for (int i = 0; i < resultStr.length(); i++) {
                System.out.print((resultStr.charAt(i)- 47) + " ");
            }
            System.out.println();
        }
    }
}
