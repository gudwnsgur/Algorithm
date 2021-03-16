#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define ll long long
using namespace std;

vector<vector<ll>> num, dp;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp = vector<vector<ll>>(n, vector<ll>(n, 0));
	num = vector<vector<ll>>(n, vector<ll>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num[i][j];
		}
	}

	dp[0][0] = 1;


	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (dp[i][j] == 0) continue;
			if (i == n - 1 && j == n - 1) break;

			if (i + num[i][j] < n) dp[num[i][j] + i][j] += dp[i][j];
			if (j + num[i][j] < n) dp[i][num[i][j] + j] += dp[i][j];
		}
	}

	cout << dp[n - 1][n - 1] << endl;
	return 0;
}

