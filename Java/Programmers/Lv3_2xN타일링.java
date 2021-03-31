
import java.util.*;

class Solution {
    int DIV = 1000000007;
    int[] dp;
    public int solution(int n) {
        dp =new int[n+1];
        dp[1] = 1; dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = (dp[i-2] + dp[i-1])%DIV;
        }
        return dp[n]%DIV;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
