#include <string>
#include <vector>

using namespace std;

int dp[600001]{0, };

int solution(int n) {
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n ;i++) {
        dp[i] = (dp[i-1]+dp[i-2])%1000000007;
    }
    return dp[n]%1000000007;
}