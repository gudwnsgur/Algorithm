
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int solve(int n) {
	vector<int> coin(n + 1, 0);
	int dest;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	cin >> dest;

	vector<int> dp(dest+1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= dest; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	return dp[dest];
}
int main () {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

