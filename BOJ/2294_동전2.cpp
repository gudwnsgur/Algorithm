#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
#define MAX 100001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// dp[i][j] : i원까지 사용했을 때 j원을 만드는 최소 개수
	int n, k;
	cin >> n >> k;
	vector<int> coin(n+1), dp(k + 1, MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) cin >> coin[i];
	coin[0] = -1;

	sort(coin.begin(), coin.end());

	for (int i = coin[1]; i <= k; i++) if (i % coin[1] == 0) dp[i] = i/coin[1];

	for (int i = 2; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	cout << (dp[k] == MAX ? -1 : dp[k]) << endl;
	return 0;
}
