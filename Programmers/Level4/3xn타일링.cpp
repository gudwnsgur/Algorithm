#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long dp[5001]{ 0, };
int solution(int n) {
	if (n % 2) return 0; // 홀수 : 0

	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = (dp[i - 2] * 3)%1000000007;	
		for (int j = i - 4; j > 0; j--) {
			dp[i] += (2 * dp[j]) % 1000000007;
		}
		dp[i] = (dp[i]+2) % 1000000007;	// 모든 타일이 엮여 있는 special case
	}

	return dp[n] % 1000000007;
}
int main() {
	int n = 8;
	cout << solution(n);
	return 0;
}