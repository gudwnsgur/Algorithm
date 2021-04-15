import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        long[] dp = new long[36];
        dp[0] = 1;
        for(int i = 1; i <= 35; i ++){
            int tmp = i;
            while(tmp != 0){
                dp[i] += dp[i - tmp] * dp[tmp - 1];
                tmp--;
            }
        }
        int n = Integer.parseInt(br.readLine());
        System.out.println(dp[n]);
    }
}
