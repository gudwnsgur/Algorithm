#include <iostream>
#define endl '\n'
using namespace std;

int n, k;
long long dp[91] = {0, };

int main() {
	cin >> n;
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n] << endl;
	return 0;
}