#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001] = { 0, };
int arr[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		int localMax = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
				localMax = max(localMax, dp[j] + arr[i]);
		}
		dp[i] = localMax;
	}

	int maxLength = 0;
	for (int i = 1; i <= n; i++) maxLength = max(maxLength, dp[i]);
	cout << maxLength << endl;
	return 0;
}