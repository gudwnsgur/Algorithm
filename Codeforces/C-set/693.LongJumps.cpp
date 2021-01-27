#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
 
int solution(int n) {
	int res = 0;
	vector<int> num(n + 1);
	vector<int> dp(n+1);

	for (int i = 1; i <= n; i++) cin >> num[i];
	for (int i = n; i >= 1; i--) {
		dp[i] = num[i];
		if (i + num[i] <= n) {
			dp[i] += dp[i + num[i]];
		}
		res = max(res, dp[i]);
	}
	return res;
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}
