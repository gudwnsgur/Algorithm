#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp(1, arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > dp.back()) dp.push_back(arr[i]);
		else {
			if (dp.size() == 1 && arr[i] < dp.back()) dp.back() = arr[i];
			else if (dp[0] > arr[i]) dp[0] = arr[i];
			else {
				for (int j = dp.size() - 2; j >= 0; j--) {
					if (arr[i] > dp[j]) {
						dp[j + 1] = arr[i];
						break;
					}
				}
			}
		}
	}
	cout << dp.size() << endl;

	return 0;
}
