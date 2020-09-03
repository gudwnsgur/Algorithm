#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, k;

// 1차원 배열 dp
int dp[100001] = { 0, };

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= 1; j--) {
			if (w <= j) dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k] << endl;
	return 0;
}

/* 2차원 배열 dp  
int item[101][2]; // W(무게), V(가치)
int **dp;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	dp = new int*[n + 1];
	for (int i = 0; i <= n; i++) dp[i] = new int[k+1];

	for (int i = 0; i <= k; i++) dp[0][i] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (item[i][0] > j)
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], item[i][1] + dp[i-1][j-item[i][0]]);
			}
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}
*/
