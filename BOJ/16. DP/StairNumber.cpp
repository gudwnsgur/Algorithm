#include <iostream>
#include <algorithm>

#define MOD 1000000000

using namespace std;

int dp[101][10]{ 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) 
	{
		dp[i][0] = dp[i - 1][1]%MOD;
		dp[i][9] = dp[i - 1][8]%MOD;
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1]%MOD + dp[i - 1][j + 1] % MOD)% MOD;
		}
	}
	
	int cnt = 0;

	for (int i = 0; i <= 9; i++)
		cnt = (cnt+dp[n][i])%MOD;
	cout << cnt%MOD;
	return 0;
}

