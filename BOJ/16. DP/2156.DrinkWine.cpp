#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001]{ 0, };
int wine[10001]{ 0, };


int main() { 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> wine[i];

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max(dp[2], max(dp[1] + wine[3], wine[2] + wine[3]));
	
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]));
	}
	
	cout << dp[n];

	return 0;
}