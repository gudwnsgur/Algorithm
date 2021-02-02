#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n, res = 1;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = 1; dp[1][0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] >= arr[i]) dp[0][i] = dp[0][i - 1] + 1;
		else dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] <= arr[i]) dp[1][i] = dp[1][i - 1] + 1;
		else dp[1][i] = 1;
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;
	return 0;
}
