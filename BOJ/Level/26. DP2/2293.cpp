#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001]{ 0, };

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}
	sort(coin.begin(), coin.end());

	dp[0] = 1;
	for (int i = 0; i < coin.size(); i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= coin[i]) dp[j] += dp[j - coin[i]];
		}
	}
	for(int i=1; i<=m ; i++) cout << dp[i] << ' ';
	cout << endl;


	return 0;
}