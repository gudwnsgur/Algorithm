#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3]{ 0, };
int house[1001][3]{ 0, };

int main() {
	int n;
	cin >> n; // 집의 개수
	

	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];

		if (i == 0) {
			dp[i][0] = house[i][0];
			dp[i][1] = house[i][1];
			dp[i][2] = house[i][2];
		}
		else {
		dp[i][0] = house[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = house[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = house[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	return 0;
}


