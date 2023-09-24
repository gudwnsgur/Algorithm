import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static int[] levels;

    public static void main(String[] args) throws IOException {
        initialize();
        long left = levels[0];
        long right = Integer.MAX_VALUE;

        long result = 0;
        while(left <= right) {
            long mid = (left + right) / 2;
            if(possible(mid)) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(result);
    }
    static boolean possible(long cur) {
        long sum = 0;
        for(int i=0; i<n ; i++) {
            if (cur >= levels[i]) {
                sum += cur - levels[i];
            }
        }
        return sum <= k;
    }

    static void initialize() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        levels = new int[n];
        for (int i = 0; i < n; i++) {
            levels[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(levels);
    }
}

