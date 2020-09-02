#include <iostream>
#define endl '\n'
using namespace std;

int dp[45] = { 0, };

bool isCorrect(int k) {
	for (int i = 1; i <= 44; i++) {
		for (int j = 1; j <= 44; j++) {
			if (dp[i] + dp[j] < 1000) {
				for (int l = 1; l <= 44; l++) {
					if (dp[i] + dp[j] + dp[l] == k) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 44; i++)
		dp[i] = dp[i - 1] + i;

	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		cout << isCorrect(k) << endl;
	}
	return 0;
}