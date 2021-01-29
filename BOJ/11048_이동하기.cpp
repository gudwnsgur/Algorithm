#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[1][1] = map[1][1];

	for (int i = 2; i <= n; i++) dp[i][1] += dp[i - 1][1] + map[i][1];
	for (int i = 2; i <= m; i++) dp[1][i] += dp[1][i - 1] + map[1][i];

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = map[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
