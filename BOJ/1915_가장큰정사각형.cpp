#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


int main() {
	int n, m, res = 0;
	string str ="";
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			dp[i][j] = str[j] - '0';
			res = max(res, dp[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (!dp[i][j]) continue;
			dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			res = max(res, dp[i][j]);
		}
	}
	cout << res*res << endl;
	return 0;
}
