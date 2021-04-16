class Solution {
    private static final int DIV = 1234567;
    public long solution(int n) {
        long[] dp = new long[2001];
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = (dp[i-2]+dp[i-1])%DIV;
        }
        return dp[n]%DIV;
    }
}
