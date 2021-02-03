#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define ll long long
#define MOD 10007
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 2, vector<int>(10, 0));
	// dp[i][j] : i개의 수중 첫번째에 j가 올 때 오름차순이 되는 경우의 수

	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 1; i <= n + 1; i++) dp[i][9] = 1;

	for (int i = 2; i <= n+1; i++) {
		for (int j = 8; j >= 0; j--) {
			dp[i][j] = (int)((ll)dp[i - 1][j] + (ll)dp[i][j + 1])%MOD;
		}
	}
	cout << dp[n + 1][0] % MOD << endl;
	return 0;
}
