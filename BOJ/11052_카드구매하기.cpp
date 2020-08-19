#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0, };


int main() {
	int n;
	cin >> n;
	int *p = new int[n+1];
	for (int i = 1; i <= n; i++) cin >> p[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[n] << endl;
	return 0;
}
// 1 100 160 1 1 1 1 1 1 1