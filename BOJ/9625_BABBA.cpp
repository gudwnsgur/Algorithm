#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int main () {
	int k;
	cin >> k;
	long long dp[46];
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= k; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[k - 1] << ' ' << dp[k] << endl;
	return 0;
}
