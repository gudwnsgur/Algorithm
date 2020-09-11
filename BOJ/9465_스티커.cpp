#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, testCase;
int dp[2][100001] = { 0, };
int sticker[2][100001];

int main() {
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> sticker[0][i];
		for (int i = 1; i <= n; i++) cin >> sticker[1][i];

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		int result = max(dp[0][1], dp[1][1]);


		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + sticker[0][i];
			dp[1][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + sticker[1][i];
			result = max(result, max(dp[0][i], dp[1][i]));
		}
		cout << result << endl;

		for (int i = 0; i <= n; i++) {
			dp[0][i] = 0;	dp[1][i] = 0;
		}
	}
	return 0;
}