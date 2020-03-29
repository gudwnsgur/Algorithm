#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001]{ 0, };

int main() {
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		bool two = false, three = false;
		if (!(i % 2)) two = true;
		if (!(i % 3)) three = true;

		if (two && three) dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3]))+1;
		else if (two) dp[i] = min(dp[i - 1], dp[i / 2])+1;
		else if (three) dp[i] = min(dp[i - 1], dp[i / 3])+1;
		else dp[i] = dp[i - 1]+1;
	}
	cout << dp[n];
	return 0;
} 