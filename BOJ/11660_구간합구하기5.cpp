#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[1025][1025], dp[1025][1025];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
	}

	return 0;
}
