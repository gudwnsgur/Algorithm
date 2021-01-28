#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MOD 1000000009
using namespace std;

vector<int> dp[4];
long long solve(int n) {
	if (n == 1 || n==2 ) return 1;
	if (n == 3) return 3;

	for (int i = 1; i <= 3; i++) dp[i] = vector<int>(n + 1, 0);

	// dp[i][j] : j를 만들 때 마지막 수가 i인 경우의 수
	dp[1][1] = 1; 
	dp[2][2] = 1;
	dp[1][3] = 1; dp[2][3] = 1; dp[3][3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[1][i] = (int) ((long long)(dp[2][i - 1] + dp[3][i - 1]) % MOD);
		dp[2][i] = (int) ((long long)(dp[1][i - 2] + dp[3][i - 2]) % MOD);
		dp[3][i] = (int) ((long long)(dp[1][i - 3] + dp[2][i - 3]) % MOD);
	}

	return ((long long)dp[1][n] + (long long)dp[2][n] + (long long)dp[3][n]) % MOD;
}

int main () {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		cout << solve(n)%MOD << endl;
	}
	return 0;
}
