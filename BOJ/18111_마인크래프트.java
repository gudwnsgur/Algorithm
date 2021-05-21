
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, b;
    static int[] land;
    static int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());

        land = new int[n * m];
        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                land[i * m + j] = Integer.parseInt(tk.nextToken());
                min = Math.min(min, land[i * m + j]);
                max = Math.max(max, land[i * m + j]);
            }
        }

        int result = Integer.MAX_VALUE;
        int height = 0;

        for (int i = max; i >= min; i--) {
            int tmp = b;
            int cur = 0;
            for (int j = 0; j < land.length; j++) {
                if(land[j] > i) {
                    cur += (land[j]- i)*2;
                    tmp += land[j]- i;
                }
                else if(land[j] < i) {
                    cur += i -land[j];
                    tmp -= i -land[j];
                }
            }
            if(tmp >= 0) {
                if(result > cur) {
                    height = i;
                    result = cur;
                }
            }
        }
        System.out.println(result + " " + height);
    }
}

