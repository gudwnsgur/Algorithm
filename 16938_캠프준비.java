import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, l, r, x;
    static int[] num;
    static boolean[] use;
    static int result = 0;

    public static void main(String[] args) throws IOException {
        initialize();
        dfs(0);
        System.out.println(result);
    }
    static void dfs(int length)  {
        if(length == n) {
            int sum = 0, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
            for(int i=0; i<n ;i++) {
                if(use[i]) {
                    sum += num[i];
                    max = Math.max(max, num[i]);
                    min =  Math.min(min, num[i]);
                }
            }
            if(sum >= l && sum <= r && (max-min) >= x) result++;
            return;
        }
        use[length] = true;
        dfs(length+1);
        use[length] = false;
        dfs(length+1);
    }

    static void initialize() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        l = Integer.parseInt(tk.nextToken());
        r = Integer.parseInt(tk.nextToken());
        x = Integer.parseInt(tk.nextToken());

        num = new int[n];
        use = new boolean[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            num[i] = Integer.parseInt(tk.nextToken());
        }
    }
}

