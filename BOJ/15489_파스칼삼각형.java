import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;
    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(tk.nextToken());
        int c = Integer.parseInt(tk.nextToken());
        int w = Integer.parseInt(tk.nextToken());
        int sum = 0;
        int [][] dp = new int[31][31];

        for(int i=1; i<=30; i++) {
            for(int j=1; j<=i; j++) {
                dp[i][j] = (i==j || j==1 ? 1 : dp[i-1][j-1]+dp[i-1][j]);
            }
        }

        for(int i=0; i<w; i++) {
            for(int j=0; j<i+1; j++) {
                sum += dp[r+i][c+j];
            }
        }
        System.out.println(sum);
    }
}

