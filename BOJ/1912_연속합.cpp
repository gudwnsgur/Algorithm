#include <iostream>
using namespace std;

int dp[100001]{ 0, };

int main() {
	int n, max;
	cin >> n;
	
	int *arr = new int[n+1];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else dp[i] = arr[i];
	}

	max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}

	cout << max;
	return 0;
}