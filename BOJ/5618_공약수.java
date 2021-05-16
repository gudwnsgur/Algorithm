import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main (String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] num = new int[n];
        int min = Integer.MAX_VALUE;
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            num[i] = Integer.parseInt(tk.nextToken());
            min = Math.min(num[i], min);
        }

        for(int i=1; i<=min; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) if(num[j] % i == 0) cnt++;
            if(cnt == n) System.out.println(i);
        }
    }
}
