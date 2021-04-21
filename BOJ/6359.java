import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0 ) {
            int n = Integer.parseInt(br.readLine());
            boolean[] prison = new boolean[n+1];
            int result = 0;
            for(int i=1; i<=n; i++) {
                int cur = i;
                while(cur <= n) {
                    prison[cur] = !prison[cur];
                    cur += i;
                }
            }
            for(int i=1; i<=n; i++) if(prison[i]) result++;
            System.out.println(result);
        }
    }
}
