#include <string>
#include <iostream>
#include <vector>
using namespace std;

int dp[15][14]{ 0, };

int solution(int n)
{
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 2; i <= n; i++) {
		int j = 1;
		for (; j < i-1; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
		dp[i][j] = dp[i][j - 1];
	}

	int sum = 0;
	for (int i = 0; i <= n - 1; i++)  sum += dp[n][i];
	
	return sum;
}

// testCase
int main() {
	int n;
	while (1) {
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}