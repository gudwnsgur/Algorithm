import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int d;
    static int n, m;
    static int[] arr, diff;

    static boolean isPossible(long mid) {
        int cnt = 0;
        int cur = 0;
        for(int i=0; i<diff.length; i++) {
            cur += diff[i];
            if(cur >= mid) cur = 0;
            else cnt++;
        }
        return cnt <= m;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        d = Integer.parseInt(tk.nextToken());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        arr = new int[n];
        diff = new int[n + 1];
        if(n == 0) {
            System.out.println(d);
            return;
        }

        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);

        diff[0] = arr[0];
        diff[n] = d - arr[n - 1];
        for (int i = 1; i < n; i++) diff[i] = arr[i] - arr[i - 1];

        int left = 1, right = d;
        int result = 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(isPossible(mid)) {
                result = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        System.out.println(result);
    }
}
