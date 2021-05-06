import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static HashMap<Integer, Integer> map = new HashMap<>();
    static long result = 0;
    static int[] arr, psum;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());
        arr = new int[n+1];
        psum = new int[n+1];

        tk = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(tk.nextToken());
            psum[i] = psum[i-1] + arr[i];
        }
        map.put(0,1);
        for(int i=1; i<=n; i++) {
            result += map.getOrDefault(psum[i]-k, 0);
            map.put(psum[i], map.getOrDefault(psum[i],0 ) + 1);
        }
        System.out.println(result);
    }
}
