#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s;
bool dp[101][1001] = {false, };

int main() {
	cin >> n >> s >> m;
	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {
		int volume;
		cin >> volume;
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + volume <= m) dp[i][j + volume] = true;
				if (j - volume >= 0) dp[i][j - volume] = true;
			}
		}
	}
	int i = m;
	for (; i >= 0; i--) {
		if (dp[n][i]) {
			cout << i << endl;
			break;
		}
	}
	if (i == -1) cout << "-1" << endl;
	return 0;
}