#include <string>
#include <vector>
using namespace std;

long long dp[81]{0, 1, 1, 2, 3};

long long solution(int N) {

	for (int i = 5; i <= N; i++) 
		dp[i] = dp[i - 2] + dp[i - 1];	// Fibonacci

	return 2*dp[N] + 4*dp[N-1] + 2*dp[N-2];
}