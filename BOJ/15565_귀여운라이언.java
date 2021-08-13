import java.util.*;
import java.io.*;

class Loc {
    int x, y;

    Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    static final int INF = 987654321;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static boolean[] doll;
    static int[] res;
    static int result = INF;
    static ArrayList<Integer> idx = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());
        doll = new boolean[n + 1];
        res = new int[n + 1];

        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) doll[i] = tk.nextToken().equals("1");

        res[0] = INF;
        for (int i = 1; i <= n; i++) {
            if (!doll[i]) {
                res[i] = res[i - 1] + 1;
                continue;
            }
            idx.add(i);
            if (idx.size() >= k) res[i] = i - idx.get(idx.size() - k) + 1;
            else res[i] = INF;

            result = Math.min(res[i], result);
        }
        System.out.println(result >= INF ? -1 : result);
    }
}
