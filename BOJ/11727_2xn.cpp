#include <iostream>
#define DIV 10007
using namespace std;

int dp[1001]{ 0, };
int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;
	}
	
	cout << dp[n] << endl;
	return 0;
}