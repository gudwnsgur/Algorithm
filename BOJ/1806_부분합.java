import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, s, result = Integer.MAX_VALUE;
    static int[] arr, sum;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        s = Integer.parseInt(tk.nextToken());

        arr = new int[n];
        sum = new int[n + 1];
        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(tk.nextToken());
            sum[i + 1] = sum[i] + arr[i];
        }

        for (int i = 1; i <= n; i++) {
            int curRes = Integer.MAX_VALUE;
            int left = 0, right = i-1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if(sum[i] - sum[mid] >= s) {
                    curRes = i-mid;
                    left = mid+1;
                }
                else right = mid-1;
            }
            if(curRes != Integer.MAX_VALUE) {
                result = Math.min(result, curRes);
            }
        }
        System.out.println(result == Integer.MAX_VALUE ? 0 : result);
    }
}
