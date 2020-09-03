#include <iostream>
#define MOD 10007
using namespace std;

int n;
int dp[1001] = {0,1,3, };

int main() {
	cin >> n;
	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
	cout << dp[n] << endl;
	return 0;
}