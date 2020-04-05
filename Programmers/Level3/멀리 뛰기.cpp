#include <string>
#include <vector>
using namespace std;

#define MOD 1234567
long long dp[2001]{ 0, };

long long solution(int n) {
	long long answer = 0;
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}
	return dp[n]%MOD;
}

// n=1 => 1   (1)
// n=2 => 11,2 (2)
// n=3 => 111, 12, 21 (3)
// n=4 => 1111, 121,112,211,22 (5)
// n=5 => 11111, 1112, 1121, 1211, 2111, 122, 212, 221 (8)
 
// Fibonacci