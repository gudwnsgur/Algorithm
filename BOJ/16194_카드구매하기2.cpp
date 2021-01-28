#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> p(n+1);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1, j=p[1]; i <= n; i++, j += p[1]) dp[i] = j;
	
	for (int i = 2; i <= n; i++) {
		// p[i] = i개를 살 때의 가격
		for (int j = i; j <= n; j++) {
			dp[j] = min(dp[j], p[i] + dp[j-i]);
		}
	}

	cout << dp[n] << endl;
	return 0;
}
